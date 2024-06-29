#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "include/matplotlibcpp.h"
#include <vector>
#include "PriceData.h"
#include "Graph.h"
#include <fstream>
#include <sstream>
#include <unordered_map>

std::unordered_map<std::string, std::string> readEnv(const std::string& envFilePath) {
    std::unordered_map<std::string, std::string> envMap;
    std::ifstream file(envFilePath);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        std::string key, value;
        if (std::getline(lineStream, key, '=') && std::getline(lineStream, value)) {
            envMap[key] = value;
        }
    }

    return envMap;
}

using namespace std;
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

bool performCurlRequest(const string& url, string& response) {
    CURL *curl = curl_easy_init();
    if(!curl) {
        cerr << "Failed to initialize curl" << endl;
        return false;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    if(res != CURLE_OK) {
        cerr << "Failed to perform curl request: " << curl_easy_strerror(res) << endl;
        return false;
    }
    return true;
}



int main() {
    auto env = readEnv("../.env");
    std::string apiKey = env["API_KEY"];
    vector<double> x = {1,2,3,4,5}; 
    vector<double> y = {1,4,9,16,25};
    string url = "https://api.polygon.io/v2/aggs/ticker/AAPL/range/1/hour/2023-01-09/2023-01-09?apiKey=" + apiKey;
    string response;
    if(!performCurlRequest(url, response)) {
        return 1;
    }
    nlohmann::json jsonResponse = nlohmann::json::parse(response);
    PriceData priceData(jsonResponse["count"].get<int>());
    for(int i = 0; i < jsonResponse["count"]; i++) {
        priceData.close.at(i) = jsonResponse["results"][i]["c"];
        priceData.high.at(i) = jsonResponse["results"][i]["h"];
        priceData.low[i] = jsonResponse["results"][i]["l"];
        priceData.numTrades[i] = jsonResponse["results"][i]["n"];
        priceData.open[i] = jsonResponse["results"][i]["o"];
        priceData.timestamp[i] = jsonResponse["results"][i]["t"];
        priceData.volume[i] = jsonResponse["results"][i]["v"];
        priceData.vwap[i] = jsonResponse["results"][i]["vw"];
    }
    Graph graph(priceData.timestamp, priceData.close);
    graph.newtonInterpolation();
    graph.linearInterpolation();
    vector<double> interpolatedValues;
    vector<double> linearInterpolatedValues;
    double diff = priceData.timestamp[priceData.timestamp.size() - 1] - priceData.timestamp[priceData.timestamp.size() - 2];
    for(int i = 0; i < priceData.timestamp.size(); i++) {
        double linearInterpolatedValue = graph.evalLinearInterpolation(priceData.timestamp[i]);
        linearInterpolatedValues.push_back(linearInterpolatedValue);
        cout << priceData.timestamp[i] << " " << priceData.close[i] << linearInterpolatedValue << endl;
    }   


    //matplotlibcpp::plot(interpolatedValues);
    matplotlibcpp::scatter(priceData.timestamp, priceData.close);
    matplotlibcpp::plot(priceData.timestamp, linearInterpolatedValues);
    matplotlibcpp::xlabel("Timestamp");
    matplotlibcpp::ylabel("Close Price");
    std:: cout << "Residual: " << graph.residual() << std::endl;    
    matplotlibcpp::show();
    return 0;
}
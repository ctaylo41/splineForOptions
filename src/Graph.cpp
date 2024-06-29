#include "Graph.h"
#include "matrix.h"
#include "vector.h"
#include <iostream>
Graph::Graph(std::vector<double> x, std::vector<double> y, std::vector<double> z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
Graph::Graph(std::vector<double> x, std::vector<double> y)
{
    this->x = x;
    this->y = y;
}

void Graph::newtonInterpolation()
{
    const std::vector<double> &x = this->x;
    const std::vector<double> &y = this->y;
    int n = x.size();
    std::vector<double> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = y[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = n-1; j >= i; j--)
        {
            result[j] = (result[j]- result[j-1]) / (x[j] - x[j-i]);
        }
    }
    this->newtonCoeffecients = result;
}

double Graph::evalNewtonInterpolation(double xInterpolated)
{
    double result = this->newtonCoeffecients.back();
    int n = this->newtonCoeffecients.size();
    for (int i = n - 2; i >= 0; i--) {
        result = this->newtonCoeffecients[i] + (xInterpolated - this->x[i]) * result;
    }
    return result;
}

void Graph::linearInterpolation() {
    std::vector<std::vector<double>> data;
    for (int i = 0; i < this->x.size(); i++) {
        data.push_back({1,this->x[i]});
    }
    Matrix A(data);
    Vector b(this->y);
    Matrix AT = A.transpose();
    Matrix ATA = AT * A;
    Matrix ATb = AT * b;
    Matrix x = ATA.inverse() * ATb;

    this->linearCoeffecients = {x.get(0,0), x.get(1,0)};
}

double Graph::evalLinearInterpolation(double xInterpolated) {
    return this->linearCoeffecients[0] + this->linearCoeffecients[1] * xInterpolated;
}

double Graph::residual() {
    double sumSquaredRegression = 0;
    double sumSquaredTotal = 0;
    double mean = 0;
    for(int i = 0; i < this->y.size(); i++) {
        mean += this->y[i];
    }
    mean /= this->y.size();

    for (int i = 0; i < this->x.size(); i++) {
        sumSquaredRegression += pow(this->y[i] - this->evalLinearInterpolation(this->x[i]), 2);
        sumSquaredTotal += pow(this->y[i] - mean, 2);
    }
    return 1 - sumSquaredRegression / sumSquaredTotal;
}

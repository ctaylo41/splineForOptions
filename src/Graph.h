#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
class Graph {
    private:
        std::vector<double> x;
        std::vector<double> y;
        std::vector<double> z;
        std::vector<double> newtonCoeffecients;
    public:
        Graph(std::vector<double> x, std::vector<double> y, std::vector<double> z);
        Graph(std::vector<double> x, std::vector<double> y);
        void newtonInterpolation();

        double evalNewtonInterpolation(double xInterpolated);
};

#endif
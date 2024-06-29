#include "Graph.h"
#include "matrix.h"
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
    for (int i = 0; i < n; i++)
    {
        std::cout << newtonCoeffecients.at(i) << std::endl;
    }
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
}
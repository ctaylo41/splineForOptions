#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
    public:
        int rows;
        int cols;
        std::vector<std::vector<double>> data;
        Matrix(int rows, int cols);
        static Matrix Multiply(Matrix& a, Matrix& b);
};
#endif
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
    public:
        int rows;
        int cols;
        std::vector<std::vector<double> > data;
        Matrix(int rows, int cols);
        Matrix Multiply(Matrix& a, Matrix& b);
        Matrix Transpose(Matrix& a);
        Matrix Inverse(Matrix& a);
        Matrix CholeskyDecomp(Matrix& a);
        double get(int i, int j);
        int getRows();
        int getCols();
        void set(int i, int j, double value);
        std::vector<std::vector<double> > getData();
};
#endif
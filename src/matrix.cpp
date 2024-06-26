#include <vector>
#include "matrix.h"
#include <iostream>
Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->data.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        data[i].resize(cols);
    }
}

Matrix::Matrix(int n)
{
    this->rows = n;
    this->cols = n;
    this->data.resize(n);
    for (int i = 0; i < n; i++)
    {
        data[i].resize(n, 0);
        data[i][i] = 1;
    }
}

Matrix::Matrix(std::vector<std::vector<double>> data)
{
    this->data = data;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].size() != data[0].size())
        {
            throw std::invalid_argument("All rows must have the same number of columns");
        }
    }
    this->rows = data.size();
    this->cols = data[0].size();
}

std::vector<std::vector<double>> Matrix::getData()
{
    return data;
}

double Matrix::get(int i, int j)
{
    return data[i][j];
}

int Matrix::getRows()
{
    return rows;
}

int Matrix::getCols()
{
    return cols;
}

void Matrix::set(int i, int j, double value)
{
    data[i][j] = value;
}

Matrix Matrix::Multiply(Matrix &a, Matrix &b)
{
    if (a.cols != b.rows)
    {
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    Matrix result(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < b.cols; j++)
        {
            for (int k = 0; k < a.cols; k++)
            {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}
Matrix Matrix::Transpose()
{
    Matrix a = *this;
    Matrix result(a.cols, a.rows);
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            result.data[j][i] = a.data[i][j];
        }
    }

    return result;
}
Matrix Matrix::Inverse(Matrix &a)
{
    if (a.rows != a.cols)
    {
        throw std::invalid_argument("Matrix is not square");
    }
    int n = a.rows;
    Matrix result(n);
    Matrix L(n);
    Matrix U(n);
    LUDecomposition(a, L, U);
    for (int i = 0; i < n; i++)
    {
        Matrix b(n);
        b.data[i][0] = 1;
        Matrix y = L.forwardSolve(b);
        Matrix x = U.backwardSolve(y);
        for (int j = 0; j < n; j++)
        {
            result.data[j][i] = x.data[j][0];
        }
    }
    return result;
}


Matrix Matrix::CholeskyDecomp(Matrix &a)
{
    if (a.rows != a.cols)
    {
        throw std::invalid_argument("Matrix is not square");
    }
    Matrix result(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            double sum = 0;
            for (int k = 0; k < j; k++)
            {
                sum += result.data[i][k] * result.data[j][k];
            }
            if (i == j)
            {
                double value = a.data[i][i] - sum;
                if (value < 0)
                {
                    throw std::runtime_error("Matrix is not positive definite");
                }
                result.data[i][j] = sqrt(value);
            }
            else
            {
                if (result.data[j][j] == 0)
                {
                    throw std::runtime_error("Division by zero encountered in Cholesky decomposition");
                }
                result.data[i][j] = (a.data[i][j] - sum) / result.data[j][j];
            }
        }
    }
    return result;
}

bool Matrix::equals(Matrix &a, Matrix &b)
{
    if (a.rows != b.rows || a.cols != b.cols)
    {
        return false;
    }
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            if (a.data[i][j] != b.data[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

Matrix Matrix::backwardSolve(Matrix &b)
{
    Matrix a = *this;
    if (a.rows != a.cols)
    {
        throw std::invalid_argument("Matrix is not square");
    }
    if (a.rows != b.rows)
    {
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    Matrix result(a.rows, b.cols);
    for (int i = a.rows - 1; i >= 0; i--)
    {
        for (int j = 0; j < b.cols; j++)
        {
            double sum = 0;
            for (int k = i + 1; k < a.cols; k++)
            {
                sum += a.data[i][k] * result.data[k][j];
            }
            result.data[i][j] = (b.data[i][j] - sum) / a.data[i][i];
        }
    }
    return result;
}

Matrix Matrix::forwardSolve(Matrix &b)
{
    Matrix a = *this;
    if (a.rows != a.cols)
    {
        throw std::invalid_argument("Matrix is not square");
    }
    if (a.rows != b.rows)
    {
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    Matrix result(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < b.cols; j++)
        {
            double sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum += a.data[i][k] * result.data[k][j];
            }
            result.data[i][j] = (b.data[i][j] - sum) / a.data[i][i];
        }
    }
    return result;
}

void Matrix::LUDecomposition(Matrix &a, Matrix &L, Matrix &U)
{
    if (a.rows != a.cols)
    {
        throw std::invalid_argument("Matrix is not square");
    }

    int n = a.rows;

    L = Matrix(n);
    U = Matrix(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum += L.data[i][k] * U.data[k][j];
            }
            U.data[i][j] = a.data[i][j] - sum;
        }

        for (int j = i + 1; j < n; j++)
        {
            double sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum += L.data[j][k] * U.data[k][i];
            }
            L.data[j][i] = (a.data[j][i] - sum) / U.data[i][i];
        }
    }
}
#include <vector>
#include "matrix.h"

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

std::vector<std::vector<double> > Matrix::getData()
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
Matrix Matrix::Transpose(Matrix &a)
{
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
    Matrix L = CholeskyDecomp(a);
    Matrix U = Transpose(L);
    Matrix result(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            double sum = 0;
            if (i == j)
            {
                sum = 1;
            }
            for (int k = 0; k < i; k++)
            {
                sum -= L.data[i][k] * result.data[k][j];
            }
            result.data[i][j] = sum / L.data[i][i];
        }
    }
    for (int i = a.rows - 1; i >= 0; i--)
    {
        for (int j = 0; j < a.cols; j++)
        {
            double sum = 0;
            if (i == j)
            {
                sum = 1;
            }
            for (int k = i + 1; k < a.rows; k++)
            {
                sum -= U.data[i][k] * result.data[k][j];
            }
            result.data[i][j] = sum / U.data[i][i];
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
                result.data[i][j] = sqrt(a.data[i][i] - sum);
            }
            else
            {
                result.data[i][j] = (a.data[i][j] - sum) / result.data[j][j];
            }
        }
    }
    return result;
}
#include <vector>

class Matrix {
public:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        data.resize(rows);
        for(int i = 0; i < rows; i++) {
            data[i].resize(cols);
        }
    }
    static Matrix Multiply(Matrix& a, Matrix& b) {
        if(a.cols != b.rows) {
            throw std::invalid_argument("Matrix dimensions do not match");
        }
        Matrix result(a.rows, b.cols);
        for(int i = 0; i < a.rows; i++) {
            for(int j = 0; j < b.cols; j++) {
                for(int k = 0; k < a.cols; k++) {
                    result.data[i][j] += a.data[i][k] * b.data[k][j];
                }
            }
        }
        return result;
    }
};
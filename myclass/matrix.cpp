#include <iostream>
#include <stdexcept>

class Matrix {
private:
    int** data;
    int rows;
    int cols;
    void allocateMemory() {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols]();
        }
    }
    void freeMemory() {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }

public:
    Matrix() : rows(0), cols(0), data(nullptr) {}

    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        if (rows <= 0 || cols <= 0) {
            throw std::invalid_argument("Размеры матрицы должны быть положительными");
        }
        allocateMemory();
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix() {
        freeMemory();
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            freeMemory();
            rows = other.rows;
            cols = other.cols;
            allocateMemory();
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    void fill(int value) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = value;
            }
        }
    }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            data[i][j] = value;
        } else {
            throw std::out_of_range("Индексы вне диапазона");
        }
    }

    int getElement(int i, int j) const {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return data[i][j];
        } else {
            throw std::out_of_range("Индексы вне диапазона");
        }
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }

    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Размеры матриц должны совпадать для сложения");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Количество столбцов первой матрицы должно равняться количеству строк второй матрицы");
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                int sum = 0;
                for (int k = 0; k < cols; ++k) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }

    Matrix operator+(const Matrix& other) const {
        return add(other);
    }

    Matrix operator*(const Matrix& other) const {
        return multiply(other);
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
};
#include <iostream>
using namespace std;

int main() {
        Matrix A(2, 3);
        Matrix B(2, 3);

        int value = 1;
        for (int i = 0; i < A.getRows(); ++i) {
            for (int j = 0; j < A.getCols(); ++j) {
                A.setElement(i, j, value++);
            }
        }
        
        value = 7;
        for (int i = 0; i < B.getRows(); ++i) {
            for (int j = 0; j < B.getCols(); ++j) {
                B.setElement(i, j, value++);
            }
        }
        
        cout << "Матрица A:" << endl;
        A.print();
        
        cout << "\nМатрица B:" << endl;
        B.print();
        Matrix AT = A.transpose();
        cout << "\nТранспонированная A:" << endl;
        AT.print();

        Matrix C = A.add(B);
        cout << "\nA + B:" << endl;
        C.print();

        Matrix D(3, 2);
        D.fill(2);
        cout << "\nМатрица D:" << endl;
        D.print();
        
        Matrix E = A.multiply(D);
        cout << "\nA * D:" << endl;
        E.print();
    return 0;
}
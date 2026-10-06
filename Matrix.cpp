#include "Matrix.h"

#include <iostream>
#include <random>
#include <string>

Matrix::Matrix() : data_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(int size) : Matrix(size, size) {
    for (int i = 0; i < size; ++i) {
        data_[i][i] = 1;
    }
}

Matrix::Matrix(int rows, int cols) : data_(nullptr), rows_(rows), cols_(cols) {
    if (rows < 0 || cols < 0) {
        throw std::invalid_argument("Matrix dimensions cannot be negative");
    }

    if (rows_ == 0 || cols_ == 0) {
        return;
    }

    data_ = new int*[rows_];
    int allocatedRows = 0;
    try {
        for (; allocatedRows < rows_; ++allocatedRows) {
            data_[allocatedRows] = new int[cols_]{};
        }
    } catch (...) {
        for (int i = 0; i < allocatedRows; ++i) {
            delete[] data_[i];
        }
        delete[] data_;
        data_ = nullptr;
        throw;
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows_; ++i) {
        delete[] data_[i];
    }
    delete[] data_;
}

int Matrix::get(int i, int j) const {
    checkIndices(i, j);
    return data_[i][j];
}

void Matrix::set(int i, int j, int value) {
    checkIndices(i, j);
    data_[i][j] = value;
}

void Matrix::inputFromKeyboard() {
    std::cout << "Enter " << rows_ * cols_ << " integer values:\n";
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cin >> data_[i][j];
        }
    }
}

void Matrix::fillRandom() {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, 99);

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = distribution(generator);
        }
    }
}

void Matrix::print() const {
    if (rows_ == 0 || cols_ == 0) {
        std::cout << "[empty matrix]\n";
        return;
    }

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cout << data_[i][j] << (j + 1 == cols_ ? '\n' : ' ');
        }
    }
}

int Matrix::sum() const {
    int result = 0;
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result += data_[i][j];
        }
    }
    return result;
}

int Matrix::getRows() const {
    return rows_;
}

int Matrix::getCols() const {
    return cols_;
}

Matrix Matrix::transpose() const {
    Matrix result(cols_, rows_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result.set(j, i, data_[i][j]);
        }
    }
    return result;
}

void Matrix::checkIndices(int i, int j) const {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::out_of_range("Matrix index is out of range");
    }
}

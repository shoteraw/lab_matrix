#pragma once

#include <stdexcept>

class Matrix {
public:
    Matrix();
    explicit Matrix(int size);
    Matrix(int rows, int cols);
    ~Matrix();

    int get(int i, int j) const;
    void set(int i, int j, int value);
    void inputFromKeyboard();
    void fillRandom();
    void print() const;
    int sum() const;
    int getRows() const;
    int getCols() const;
    Matrix transpose() const;

private:
    int** data_;
    int rows_;
    int cols_;

    void checkIndices(int i, int j) const;
};

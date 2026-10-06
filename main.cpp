#include "Matrix.h"

#include <iostream>

int main() {
    try {
        Matrix m1;
        Matrix m2(3);
        Matrix m3(3, 4);
        Matrix m4(2, 3);

        std::cout << "M1 (" << m1.getRows() << "x" << m1.getCols() << "):\n";
        m1.print();
        std::cout << "\nM2 (identity):\n";
        m2.print();
        std::cout << "\nM3 (zeros):\n";
        m3.print();
        std::cout << "\nM4 (zeros):\n";
        m4.print();

        for (int i = 0; i < m2.getRows(); ++i) {
            for (int j = 0; j < m2.getCols(); ++j) {
                m2.set(i, j, i * j);
            }
        }
        std::cout << "\nM2 after filling with i * j:\n";
        m2.print();

        m3.fillRandom();
        std::cout << "\nM3 with random values:\n";
        m3.print();

        std::cout << "\nFill M4 from the keyboard.\n";
        m4.inputFromKeyboard();
        std::cout << "M4:\n";
        m4.print();

        std::cout << "\nSum of M3 elements: " << m3.sum() << "\n";

        Matrix transposed = m4.transpose();
        std::cout << "\nTranspose of M4:\n";
        transposed.print();

        try {
            Matrix bad(-1, 5);
        } catch (const std::invalid_argument& error) {
            std::cout << "Caught: " << error.what() << '\n';
        }

        try {
            m3.get(100, 100);
        } catch (const std::out_of_range& error) {
            std::cout << "Caught: " << error.what() << '\n';
        }
    } catch (const std::exception& error) {
        std::cerr << "Unexpected error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}

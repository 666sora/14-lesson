#include <iostream>
#include <vector>

int main() {
    int matrix[4][4];
    std::cout << "Matrix 1:" << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << "Input number: ";
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "Matrix 2:" << std::endl;
    bool equal = true;
    for (int i = 0; i < 4 && equal; i++) {
        for (int j = 0; j < 4 && equal; j++) {
            std::cout << "Input number: ";
            int temp;
            std::cin >> temp;
            equal = (temp == matrix[i][j] ? equal : false);
        }
    }
    if (equal) std::cout << "Matrixes are equal";
    else std::cout << "Matrixes are not equal";
}

/*
Требуется реализовать небольшую программу для сравнения 
двух двумерных матриц размерами 4х4 на предмет их полного 
равенства. Программа принимает на вход две целочисленные 
матрицы A и B, которые вводятся с помощью std::cin и сравнивает 
их на предмет полного равенства. Если матрицы равны, то об этом 
сообщается в стандартном выводе. Алгоритм должен быть по возможности 
оптимальным и не проводить лишних операций.
*/
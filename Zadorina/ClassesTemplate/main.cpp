#include <iostream>
#include <vector>
#include "MyArray.h"

template <typename T>
MyArray<T> readInput(MyArray<T> m) {
    std::cout << "Введите " << int(m) << " элементов: ";
    for (int i = 0; i < int(m); i++) {
        std::cin >> m[i];
    }

    return m;
}

template <typename T>
void printMyArray(const MyArray<T>& m) {
    for (int i = 0; i < int(m); i++)
        std::cout << m[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::cout << " -/ Шаблоны классов /-\n";

    std::cout << "Введите размер первого массива: ";
    int n;
    std::cin >> n;
    MyArray<int> first(n);
    first = readInput(std::move(first));

    std::cout << "Введите размер второго массива: ";
    std::cin >> n;
    MyArray<int> second(n);
    second = readInput(std::move(second));

    std::cout << int(first) << std::endl;
    std::cout << int(second) << std::endl;

    if (first == second)
        std::cout << "Массивы равны!\n";

    std::cout << "Перемноженные массивы: ";
    double res = first * second;
    std::cout << res << std::endl;
    return 0;
}

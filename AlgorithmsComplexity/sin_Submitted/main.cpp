#include <iomanip>
#include <iostream>
#include <fstream>
#include <cmath>

#include "Math.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

void PrintTestInfo(const Math& math, double x, double epsilon, int num);

// 1. Гиперболический синус или косинус через рекуррентную формулу
// 2. Тангенс x через деление sin и cos, которые вычисляются через ряд Тейлора

int main() {
    std::ifstream fin("test.txt");

    int num = 0;
    double x;
    double epsilon;
    while (!fin.eof()) {
        ++num;

        fin >> x;
        if (fin.eof()) {
            return 0;
        }
        fin >> epsilon;

        Math math(x, epsilon);

        PrintTestInfo(math, x, epsilon, num);
    }

    return 0;
}

void PrintTestInfo(const Math& math, double x, double epsilon, int num) {

    std::cout << GREEN << "Test " << num << RESET << std::endl;
    std::cout << std::setw(17) << "epsilon = " << epsilon << std::endl;

    std::cout << (std::abs(math.sin() - std::sin(x)) > epsilon ? RED : RESET);
    std::cout << std::setw(11) << std::right << "sin(" << x << ") = " << std::setw(10) << std::left << math.sin() 
              << std::setw(11) << std::right << "std::sin(" << x << ") = " << std::sin(x) << std::endl;

    std::cout << (std::abs(math.cos() - std::cos(x)) > epsilon ? RED : RESET);
    std::cout << std::setw(11) << std::right << "cos(" << x << ") = " << std::setw(10) << std::left << math.cos() 
              << std::setw(11) << std::right << "std::cos(" << x << ") = " << std::cos(x) << std::endl;
              
    std::cout << (std::abs(math.tan() - std::tan(x)) > epsilon ? RED : RESET);
    std::cout << std::setw(11) << std::right << "tan(" << x << ") = " << std::setw(10) << std::left << math.tan()
              << std::setw(11) << std::right << "std::tan(" << x << ") = " << std::tan(x) << std::endl;

    std::cout << (std::abs(math.sinh() - std::sinh(x)) > epsilon ? RED : RESET);
    std::cout << std::setw(11) << std::right << "sinh(" << x << ") = " << std::setw(10) << std::left << math.sinh() 
              << std::setw(11) << std::right << "std::sinh(" << x << ") = " << std::sinh(x) << std::endl;

    std::cout << (std::abs(math.cosh() - std::cosh(x)) > epsilon ? RED : RESET);
    std::cout << std::setw(11) << std::right << "cosh(" << x << ") = " << std::setw(10) << std::left << math.cosh() 
              << std::setw(11) << std::right << "std::cosh(" << x << ") = " << std::cosh(x) << std::endl;

    std::cout << std::endl;
}


#pragma once

#include <iostream>
#include <iomanip>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

class Test {

    static void Assert(double first, double second, double epsilon) {
        std::cout << (std::abs(first - second) > epsilon ? RED : RESET);
        std::cout << std::setw(11) << std::right << "taylor = " << std::setw(10) << std::left << first 
                  << std::setw(11) << std::right << "std::sin(" << x << ") = " << second << std::endl;
    }
};

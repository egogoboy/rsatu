#include <cstdint>
#include <cstdlib>
#include <iostream>

int main() {
    double res = 1;
    int n;
    int pow;

    std::cout << "Введите число: ";
    std::cin >> n;
    std::cout << "Введите степень: ";
    std::cin >> pow;

    for (int i = 0; i < std::abs(pow); ++i) {
        res *= n;
    }

    if (pow < 0) {
        res = 1 / res;
    }

    std::cout << "Число " << n << " в степени " << pow << ": " << res << std::endl;
}

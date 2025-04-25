#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

int64_t LinePower(int n, int pow);
int64_t BinPower(int n, int pow);

int main() {
    std::string output_file = "exel.csv";
    std::ofstream fout(output_file);
    int64_t res = 1;
    int n;
    int pow;

    std::cout << "Введите число: ";
    std::cin >> n;

    fout << "Основание: " << n;

    int count_of_operations = 0;
    for (int pow = 1; pow != 101; ++pow) {
        std::cout << "Status: " << pow << "/100\n";
        fout << ',' << pow << ',' << pow << ',' << BinPower(n, pow) << std::endl;
    }
    
    std::cout << "Success!\n";
}

int64_t LinePower(int n, int pow) {
    int64_t res = 1;
    for (int i = 0; i < std::abs(pow); ++i) {
        res *= n;
    }

    return res;
}

int64_t BinPower(int n, int pow) {
    int count_of_operations = 0;
    int64_t res = 1;
    while (pow != 0) {
        if (pow & 1) {
            res *= n;
            ++count_of_operations;
        }

        n *= n;
        pow >>= 1;
        ++count_of_operations;
    }

    return count_of_operations;
}

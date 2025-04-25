#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

struct Result {
    int value;
    int count;
};

Result simpleCalc(const std::vector<int>& coefficients, int x) {
    int result = 0;
    int count = 0;

    for (int i = 0; i < coefficients.size(); ++i) {
        int x_pow = 1;
        for (int j = 0; j < static_cast<int>(coefficients.size()) - i - 1; ++j) {
            ++count;
            x_pow *= x;
        }

        result += coefficients[i] * x_pow;
        ++count;
    }

    return {result, count};
}

Result gornerCalc(const std::vector<int>& coefficients, int x, int index) {
    if (index == 0) {
        return {coefficients[index], 0};
    }

    Result gorner = gornerCalc(coefficients, x, index - 1);
    
    return {coefficients[index] + x * gorner.value, gorner.count + 1};
}

Result gornerCalc(const std::vector<int>& coefficients, int x) {
    return gornerCalc(coefficients, x, coefficients.size() - 1);
}

bool checkResult(const Result& result, int solution);
void printTestInfo(int number, int n, const std::vector<int>& coefficients, int x, bool correct);
void printTable(const Result& simple, const Result& gorner); 

int main() {
    std::ifstream fin("test.txt");

    if (!fin.is_open()) {
        std::cerr << "File doesn't exist\n";
        return 0;
    }

    int num = 0;

    while (!fin.eof()) {
        ++num;
        int n;
        fin >> n;
        if (fin.eof()) {
            break;
        }
        std::vector<int> coefficients(n + 1);

        for (int& x : coefficients) {
            fin >> x;
        }

        int x;
        fin >> x;

        Result simple = simpleCalc(coefficients, x);
        Result gorner = gornerCalc(coefficients, x);

        printTestInfo(num, n, coefficients, x, simple.value == gorner.value);

        printTable(simple, gorner);
        std::cout << std::endl;

    }

    return 0;
}

void printTestInfo(int number, int n, const std::vector<int>& coefficients, int x, bool correct) {
    std::cout << (correct ? GREEN : RED) << "Test " << number << RESET << std::endl;
    std::cout << "n: " << n << std::endl;
    std::cout << "coefficients: ";
    for (auto x : coefficients) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "x: " << x << std::endl;
}

void printTable(const Result& simple, const Result& gorner) {
    int column_width = 15;
    std::cout << std::setw(column_width) << "solution" << std::setw(column_width) << "simple" << std::setw(column_width) << "gorner" << std::endl;
    std::cout << std::setw(column_width) << "result" << std::setw(column_width) << simple.value << std::setw(column_width) << gorner.value << std::endl;
    std::cout << std::setw(column_width) << "multiplications" << std::setw(column_width) << simple.count << std::setw(column_width) << gorner.count << std::endl;
}

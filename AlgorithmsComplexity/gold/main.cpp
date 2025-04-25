#include <fstream>
#include <iostream>
#include <cmath>

double function(double x) {
    if (x < 2) {
        return x * x;
    } else {
        return 6 - x;
    }
}

const double PHI = (1 + sqrt(5)) / 2;
double goldenSectionSearch(double a, double b, double epsilon) {
    double x1 = b - (b - a) / PHI;
    double x2 = a + (b - a) / PHI;
    double f1 = function(x1); 
    double f2 = function(x2); 
    
    while (std::fabs(b - a) > epsilon) {
        if (f1 > f2) {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = b - (b - a) / PHI;
            f1 = function(x1);
        } else {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + (b - a) / PHI;
            f2 = function(x2);
        }
    }

    return (a + b) / 2;
}

int main() {
    std::ifstream fin("test.txt");
    if (!fin.is_open()) {
        std::cerr << "File doesn't exist\n";
        return 0;
    }
    
    double a;
    double b;
    std::cout << "Enter left and right bounds: ";
    std::cin >> a >> b;

    std::cout << "Enter epsilon: ";
    double epsilon;
    std::cin >> epsilon;

    std::cout << "Function:\n";
    std::cout << "x^2, x < 2\n6 - x, x >= 2\n";

    std::cout << "Result: " << goldenSectionSearch(a, b, epsilon) << "\n\n";

    return 0;
}

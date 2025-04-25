#include <iostream>
#include <cmath>

double function(double x) {
    return std::log(x * x + 0.1) - std::log(20);
}

double e_function(double x) {
    return std::exp(x) + x - 2;
}

double bisection(double(*func)(double), double a, double b, double epsilon) {
    double fa = func(a);
    double fb = func(b);
    double c;

    while (std::fabs(b - a) > epsilon) {
        c = a + (b - a) / 2;
        double fc = func(c);

        if (fc == 0) {
            return c;
        } else if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    return (a + b) / 2;
}

int main() {
    bool exit = false;
    int choise;
    while (!exit) {
        choise = 0;
        std::cout << "1 - Call bisection\n"
                  << "2 - Exit\n>>";
        std::cin >> choise;

        switch (choise){
            case 1: {
                double(*func)(double);

                std::cout << "Select function:\n1 - ln(x^2 + 0.1) - ln(20)\n"
                          << "2 - e^x + x - 2\n>>";

                std::cin >> choise;

                if (choise == 1) {
                    func = function;
                } else if (choise == 2) {
                    func = e_function;
                }
                double a;
                double b;
                std::cout << "Enter left and right bounds: ";
                std::cin >> a >> b;

                std::cout << "Enter epsilon: ";
                double epsilon;
                std::cin >> epsilon;

                double res = bisection(func, a, b, epsilon);
                std::cout << "Function:\n";
                if (func == function) {
                    std::cout << "ln(x^2 + 0.1) - ln(20)\n";
                    std::cout << "Result: " << res << "\n\n";
                } else if (func == e_function) {
                    std::cout << "e^x + x - 2\n";
                    std::cout << "Result: " << res << std::endl;
                    std::cout << "e(x) = " << std::exp(res) << std::endl;
                    std::cout << "-x + 2 = " << -res + 2 << "\n\n";
                }

                break;
            }
            case 2: {
                exit = true;
                break;
            }
            default: {
                std::cout << "Unknown choise\n";
                break;
            }
        }
    }

    return 0;
}

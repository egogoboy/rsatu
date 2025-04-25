#include <cmath>
#include <iostream>

class Math {
public:
    Math(double x, double epsilon) {
        sin_x = taylor_sin(x, epsilon);
        cos_x = taylor_cos(x, epsilon);
        tan_x = taylor_tan(sin_x, cos_x, epsilon);
        sinh_x = taylor_sinh(x, epsilon);
        cosh_x = taylor_cosh(x, epsilon);
    }

    double sin() const {
        return sin_x;
    }

    double cos() const {
        return cos_x;
    }

    double tan() const {
        return tan_x;
    }

    double sinh() const {
        return sinh_x;
    }

    double cosh() const {
        return cosh_x;
    }

private:
    double taylor_sinh(double x, double epsilon) {
        double result = 0.0;
        double term = x;   
        int n = 2;        
        double x_pow = x * x;

        while (std::abs(term) >= epsilon) {  
            result += term;

            term *= x_pow / n / (n + 1);  
            n += 2;
        }

        return result;
    }

    double taylor_cosh(double x, double epsilon) {
        double result = 0.0;
        double term = 1.0;  
        int n = 1;
        double x_pow = x * x;

        while (std::abs(term) >= epsilon) {
            result += term;

            term *= x_pow / n / (n + 1); 
            n += 2;
        }

        return result;
    }

    double taylor_sin(double x, double epsilon) {
        double result = 0.0;
        double term = x;  
        int n = 2;       
        double x_pow = x * x;

        while (std::abs(term) >= epsilon) {
            result += term;
            term *= -x_pow / n / (n + 1);
            n += 2;
        }

        return result;
    }

    double taylor_cos(double x, double epsilon) {
        double result = 0.0;
        double term = 1.0;  
        int n = 1;
        double x_pow = x * x;

        while (std::abs(term) >= epsilon) { 
            result += term;
            term *= -x_pow / n / (n + 1);  
            n += 2;
        }

        return result;
    }

    double taylor_tan(double sin_x, double cos_x, double epsilon) {

        if (std::abs(cos_x) < epsilon) {
            std::cerr << "Ошибка: деление на ноль (cos(x) близок к нулю)." << std::endl;
            return NAN;  
        }

        return sin_x / cos_x;
    }

    double sin_x;
    double cos_x;
    double tan_x;
    double sinh_x;
    double cosh_x;

};

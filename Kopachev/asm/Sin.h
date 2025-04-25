#include <cmath>
#include <iostream>

class Sin {
public:
    static double SinX(int x) {
        return CountSinX(std::pow(x, 2), x, 1, 1, 0.001);
    }

    static double CountSinX(int x_square, int x, int fact, int fact_num, float e) {
        double res = static_cast<double>(x) / fact;

        if (res > e) {
            int new_x = x * x_square;
            int new_fact = fact * (fact_num + 1) * (fact_num + 2);

            res -= CountSinX(x_square, new_x, new_fact, fact_num + 2, e);
        }

        return res;
    }

    static double CountSinXM(double x, double x_square, int sign, int n, float e) {
        if (std::fabs(x) < e) {
            return x;
        }
        
        n += 2;
        return x + sign * CountSinXM((x * x_square) / (n - 1) / n, x_square, -sign, n, e);
    }

};

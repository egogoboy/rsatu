#ifndef TDATSPLINT_H
#define TDATSPLINT_H

#include "TDat.h"

#include <iostream>
#include "MyException.h"
#include <cmath>

class TDatSplInt : public TDat {

    public:

        using TDat::TDat;

        double getY(double x) override {
            return interpolateY(points_, x);
        }

    private:

        std::vector<double> gaussianElimination(std::vector<std::vector<double>> matrix, std::vector<double> results) {
            int n = matrix.size();
            
            // Прямой ход метода Гаусса
            for (int i = 0; i < n; i++) {
                // Находим максимальный элемент в столбце для выбора главного элемента
                int maxRow = i;
                for (int k = i + 1; k < n; k++) {
                        if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i])) {
                            maxRow = k;
                    }
                }

                // Переставляем строки
                std::swap(matrix[i], matrix[maxRow]);
                std::swap(results[i], results[maxRow]);

                // Приводим к диагональному виду
                for (int k = i + 1; k < n; k++) {
                    double factor = matrix[k][i] / matrix[i][i];
                    for (int j = i; j < n; j++) {
                        matrix[k][j] -= factor * matrix[i][j];
                    }
                    results[k] -= factor * results[i];
                }

            }

            // Обратный ход метода Гаусса
            std::vector<double> solution(n);
            for (int i = n - 1; i >= 0; i--) {
                solution[i] = results[i];
                for (int j = i + 1; j < n; j++) {
                    solution[i] -= matrix[i][j] * solution[j];
                }
                solution[i] /= matrix[i][i];
            }

            return solution;
        }       

        double interpolateY(const std::vector<Point_> &data, double x_) {
            // Находим точки x1, x2 (меньше x_) и x3, x4 (больше x_)
            int n = data.size();
            int x1_idx = -1, x2_idx = -1, x3_idx = -1, x4_idx = -1;
            
            for (int i = 0; i < n; i++) {
                if (data[i].x < x_) {
                    x1_idx = x2_idx;
                    x2_idx = i;
                } else if (data[i].x > x_) {
                    if (x3_idx == -1) x3_idx = i;
                    else x4_idx = i;
                    if (x4_idx != -1) break;
                }
            }

            if (x1_idx == -1 || x2_idx == -1 || x3_idx == -1 || x4_idx == -1) {
                throw MyException("TDatSplInt::interpolateY: Недостаточно точек вокруг х");
            }

            double x1 = data[x1_idx].x, y1 = data[x1_idx].y;
            double x2 = data[x2_idx].x, y2 = data[x2_idx].y;
            double x3 = data[x3_idx].x, y3 = data[x3_idx].y;
            double x4 = data[x4_idx].x, y4 = data[x4_idx].y;

            // Составляем матрицу системы уравнений
            std::vector<std::vector<double>> matrix = {
                { std::pow(x1, 3), std::pow(x1, 2), x1, 1 },
                { std::pow(x2, 3), std::pow(x2, 2), x2, 1 },
                { std::pow(x3, 3), std::pow(x3, 2), x3, 1 },
                { std::pow(x4, 3), std::pow(x4, 2), x4, 1 }
            };
            std::vector<double> results = { y1, y2, y3, y4 };

            // Находим коэффициенты a, b, c, d
            std::vector<double> coefficients = gaussianElimination(matrix, results);
            double a = coefficients[0], b = coefficients[1], c = coefficients[2], d = coefficients[3];

            // Вычисляем значение y(x_) по многочлену
            return a * pow(x_, 3) + b * pow(x_, 2) + c * x_ + d;

        }
};

#endif // TDATSPLINT_H

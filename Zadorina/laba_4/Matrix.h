#ifndef Mmatr_TRIX_H
#define Mmatr_TRIX_H

#include <vector>
#include <iostream>
#include "MyException.h"

class Matrix {
    
    public:

        Matrix(): n_{0}, m_{0} {}
        Matrix(int n, int m): n_{n}, m_{m} {}
        ~Matrix() {}

        void setMatrix() {
            if (n_ == 0 && m_ == 0) {
                throw MyException("Не заданы размеры матрицы");
            }

            std::vector<std::vector<double>> temp(n_, std::vector<double>(m_)); 
            std::cout << "Введите элементы матрицы (" << n_ << " строк, " << m_ << " столбцов):" << std::endl;

            for (size_t i = 0; i < n_; ++i) {
                for (size_t j = 0; j < m_; ++j) {
                    std::cin >> temp[i][j];
                }
            }

            matr_ = temp;
        } 

        void printMatrix() {
            std::cout << "Матрица:\n";

            for (int i = 0; i < n_; i++) {
                for (int j = 0; j < m_; j++){
                    std::cout << matr_[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        std::string getMatrixSize() {
            std::string size;
            size = std::to_string(n_) + " * " + std::to_string(m_);
            return size;
        }

        void setMatrixSize(int a, int b) {
            n_ = a;
            m_ = b;
        }

        Matrix operator = (double matr) {
            for (int i = 0; i < n_; i++) {
                for (int j = 0; j < m_; j++) {
                    matr_[i][j] = matr;
                }
            }

            return *this;
        }

        Matrix operator + (Matrix& b) {
            Matrix res;
            std::vector<std::vector<double>> temp(n_, std::vector<double> (m_));

            if (this->getMatrixSize() != b.getMatrixSize()) {
                throw MyException("Размерности матриц не согласованы для сложения");
            }


            for (int i = 0; i < n_; i++) { 
                for (int j = 0; j < m_; j++) {
                    temp[i][j] = matr_[i][j] + b.matr_[i][j];
                }
            }

            res.matr_ = temp;
            res.setMatrixSize(n_, m_);
            return res;
        }

        
        Matrix operator * (Matrix& B) {
            if (m_ != B.n_) {
                throw MyException("Размерности матриц не согласованы для умножения!");
            }

            std::vector<std::vector<double>> temp(n_, std::vector<double>(B.m_));
            Matrix res;
            int p = B.m_;

            for (int i = 0; i < n_; ++i) {
                for (int j = 0; j < p; ++j) {
                    temp[i][j] = 0;
                    for (int k = 0; k < m_; ++k) {
                        temp[i][j] += matr_[i][k] * B.matr_[k][j];
                    }
                }
            }

            res.matr_ = temp;
            res.setMatrixSize(n_, B.m_);
            return res;
        }

        Matrix operator * (int k) {
            std::vector<std::vector<double>> temp(n_, std::vector<double> (m_));
            Matrix res;

            for (int i = 0; i < n_; i++) { 
                for (int j = 0; j < m_; j++) {
                    temp[i][j] = matr_[i][j] * k;
                }
            }

            res.matr_ = temp;
            res.setMatrixSize(n_, m_);
            return res;
        }

        bool operator == (Matrix& B) {
            bool flag = true;
            
            if (this->getMatrixSize() != B.getMatrixSize()) {
                throw MyException("Размерности матриц не согласованы для сравнения!");
            }

            for (int i = 0; i < n_; i++) { 
                for (int j = 0; j < m_; j++) {
                    if (!(matr_[i][j] == B.matr_[i][j])) {
                        flag = false;
                    }
                }
            }
            return flag;
        }

        Matrix& operator ++ () {
            std::vector<std::vector<double>> temp(m_, std::vector<double> (n_)); 

            for (int i = 0; i < n_; i++) { 
                for (int j = 0; j < m_; j++) {
                    temp[j][i] = matr_[i][j];
                }
            }

            matr_ = temp;
            std::swap(n_, m_);
            return *this;
        }

        Matrix operator ++ (int) {
            Matrix res = *this;

            std::vector<std::vector<double>> temp(m_, std::vector<double> (n_)); 

            for (int i = 0; i < n_; i++) { 
                for (int j = 0; j < m_; j++) {
                    temp[j][i] = matr_[i][j];
                }
            }

            matr_ = temp;
            std::swap(n_, m_);
            return res;
        }

    private:
        std::vector<std::vector<double>> matr_;

        int n_;
        int m_;

};

#endif

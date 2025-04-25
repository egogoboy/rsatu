#pragma once

#include <stdexcept>
#include <vector>
#include <iostream>
#include "MyException.h"

template <typename T>
class MyArray {

    public:
        MyArray() {}
        MyArray(const std::vector<T>& m) : data{m} {}
        MyArray(int size) {
            this->data.resize(size);
        }

        double operator * (const MyArray& m) const {
            if (int(*this) != int(m)) {
                throw MyException("Размеры массивов должны совпадать");
            }

            double result;
            for (int i = 0; i < data.size(); i++) {
                result += this->data[i] * m.data[i];
            }

            return result;
        }

        bool operator == (const MyArray<T>& m) const {
            if (data.size() != m.data.size())
                return false;

            for (int i = 0; i < data.size(); i++) {
                if (data[i] != m.data[i])
                    return false;
            }

            return true;
        }

        operator int() const {
            return this->data.size();
        }

        T& operator[](int index) {
            if (index > data.size()) {
                throw std::out_of_range("Выход за границы массива");
            }
            return data[index];
        }

        const T& operator[](int index) const {
            if (index > data.size()) {
                throw std::out_of_range("Выход за границы массива");
            }
            return data[index];
        }

        int getSize() {
            return data.size();
        }

        void setArray(const std::vector<T>& m) {
            data = m;
        }

    private:
        std::vector<T> data;

};

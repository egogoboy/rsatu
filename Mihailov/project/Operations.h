#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include "Num.h"

class Operations {

    public:

        static std::string sum(std::string firstNum, std::string secondNum) {
            
            if (firstNum.size() < secondNum.size()) {
                alligment(firstNum, secondNum.size());
            }
            else if (firstNum.size() > secondNum.size()) {
                alligment(secondNum, firstNum.size());
            }
            
            int carry = 0;
            std::string result = firstNum;
            for (int i = firstNum.size() - 1; i >= 0; i--) {
                if (firstNum[i] != '.') {
                    carry += firstNum[i] - '0' + secondNum[i] - '0';
                    result[i] = carry % 2 + '0';
                    carry /= 2;
                }
            }

            return result;

        }

        static std::vector<std::string> div(int a, int b, std::string firstNum, std::string secondNum) {
            std::string line = "-------------------------";
            std::vector<std::string> result;
            if (firstNum.size() < secondNum.size()) {
                alligment(firstNum, secondNum.size());
            }
            result.push_back(firstNum);

            int countOfOperations = 0;
            Num MDK(std::abs(b) * -1);
            Num MPK(std::abs(b));

            std::string mdk = MDK.getModCode();
            std::string mpk = MPK.getModCode();
            
            while (countOfOperations <= secondNum.size() - 2) {
                result.push_back("+");
                if (result[result.size() - 2].substr(0, 2) == "00") {
                    result.push_back(mdk);
                }
                else {
                    result.push_back(mpk);
                }
                
                move(mpk);
                move(mdk);

                result.push_back(line.substr(0, 4 + secondNum.size()));
                int firstNumIndex = result.size() - 4;
                int secondNumIndex = result.size() - 2;
                
                firstNum = result[firstNumIndex];
                secondNum = result[secondNumIndex];
                result.push_back(sum(firstNum, secondNum));
                
                countOfOperations++;
            }
            
            return result;
            
        }

        static void alligment(std::string& num, int neededSize) {
            
            std::string sign = num.substr(0, 3);
            num = num.substr(3, num.size() - 3);
            neededSize -= 3;

            while (num.size() < neededSize) {
                if (sign == "00.") 
                    num = '0' + num;
                else if (sign == "11.") 
                    num = '1' + num;
            }

            num = sign + num;
        }

    private:

        static void move(std::string &num) {
            
            for (int i = num.size() - 1; i > 2; i--) {
                num[i] = num[i - 1];
            }

            num[3] = num[1];
        }
};

#endif // OPERATIONS_H

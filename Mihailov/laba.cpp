#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#include "class/binaryCode.h"

void printVector(std::vector<int> x) {
    for (auto i : x)
        std::cout << i;
    return;
}

int main() {
    std::string closeProgramChoise = "";
    do {
        int a = 1, b = 0;
        while (a >= b) {
            bool correctInput = true;
            std::cout << "Введите границы диапазона\n";
            std::cout << "a = ";
            std::cin >> a;
            if (std::cin.fail()) {
                correctInput = false;
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
            }
            if (correctInput) {
                std::cout << "b = ";
                std::cin >> b;
                if (std::cin.fail() || a >= b) {
                    correctInput = false;
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                }
                if (a >= b)
                    correctInput = false;
            }
            if (!correctInput) {
                std::cout << "Ошибка ввода границ диапазона\n";
            }
        }
        
        int c = 0;
        std::string changeCChoise = "";
        do {
            do {
            std::cout << "Введите значение целого десятичного числа\nc = ";       
            std::cin >> c;
            if (c < a || c > b) 
                std::cout << "Ошибка ввода числа c\n";

        } while (c < a || c > b);
        
        int n = 0;
        std::string machineCodeChangeChoise = "";
        do {
            machineCodeChangeChoise = "";
            do {
            std::cout   << "Введите номер машинного кода n:\n"  
                        << "1 - прямой код\n" 
                        << "2 - обратный код\n" 
                        << "3 - дополнительный код\n" 
                        << "4 - модифицированный дополнительный код\n" 
                        << "n = ";
                std::cin >> n;
                if (n < 1 || n > 4)
                    std::cout << "Ошибка ввода номера машинного кода\n";
            } while (n < 1 || n > 4);

            std::cout << "Наименование машинного кода: ";
            switch (n) {
                case 1: 
                    std::cout << "прямой код\nc = "; 
                    printVector(binaryCode::binCode(c));
                    break; 
                case 2: 
                    std::cout << "обратный код\nc = "; 
                    printVector(binaryCode::reverseCode(c)); 
                    break;
                case 3: 
                    std::cout << "дополнительный код\nc = ";
                    printVector(binaryCode::additionalCode(c));
                    break;
                case 4: 
                    std::cout << "модифицированный дополнительный код\nc = "; 
                    printVector(binaryCode::modAdditionalCode(c));
                    break;
            }
            std::cout << "\n";
            do {
                if (machineCodeChangeChoise != "")
                    std::cout << "Ошибка ввода изменение номера машинного кода\n";
                std::cout << "изменить номер машинного кода?\ny/n (да/нет)\n";
                std::cin >> machineCodeChangeChoise;
            } while (machineCodeChangeChoise != "n" && machineCodeChangeChoise != "нет" && machineCodeChangeChoise != "y" && machineCodeChangeChoise != "да");
        } while (machineCodeChangeChoise == "y" || machineCodeChangeChoise == "да");
        do {
            if (changeCChoise != "")
                std::cout << "Ошибка ввода запроса на изменение числа c\n";
            std::cout << "изменить значение числа c?\ny/n (да/нет)\n";
            std::cin >> changeCChoise;
        } while (changeCChoise != "n" && changeCChoise != "нет" && changeCChoise != "y" && changeCChoise != "да");

        } while (changeCChoise == "y" || changeCChoise == "да");
        do {
            if (closeProgramChoise != "")
                std::cout << "Ошибка ввода на завершение работы программы\n";
            std::cout << "Завершить работу программы?\ny/n (да/нет)\n";
            std::cin >> closeProgramChoise;
        } while (closeProgramChoise != "n" && closeProgramChoise != "нет" && closeProgramChoise != "y" && closeProgramChoise != "да");


    } while (closeProgramChoise == "n" || closeProgramChoise == "нет");
    

    return 0;
}

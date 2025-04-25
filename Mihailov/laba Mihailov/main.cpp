#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> binCode(int x, bool isNegative) {
    std::vector<int> result;
    int temp_x = x;
    if (temp_x < 0)
        temp_x *= -1;
    while (temp_x != 0) {
        result.push_back(temp_x % 2);
        temp_x /= 2;
    }
    result.push_back(0);
    result.push_back(isNegative ? 1 : 0);
    std::reverse(result.begin(), result.end());
    return result;
}

std::vector<int> reverseCode(int x, bool isNegative) {
    std::vector<int> result = binCode(x, isNegative);

    if (isNegative)
        for (int i = 1; i < result.size(); i++) {
            if (result[i] == 1)
                result[i] = 0;
            else
                result[i] = 1;
        }
    return result;
}

std::vector<int> additionalCode(int x, bool isNegative) {
    std::vector<int> result = reverseCode(x, isNegative);

    if (result.size() == 2 && result[0] == 1 && result[1] == 1) {
        result[0] = 0;
        result[1] = 0;
        return result;
    }

    if (x < 0) {
        bool carry = true;
        for (int i = result.size() - 1; i > 0; i--) {
            if (result[i] == 1 && carry) {
                result[i] = 0;
            }
            else if (carry) {
                result[i] = 1;
                carry = false;
            }
        }
    }
    return result;
}

bool isValidNumber(const std::string& str, int& number) {
    try {
        size_t idx;
        number = std::stoi(str, &idx);
        return idx == str.size();
    } catch (std::invalid_argument&) {
        return false;
    } catch (std::out_of_range&) {
        return false;
    }
}


std::vector<int> modAdditionalCode(int x, bool isNegative) {
    std::vector<int> result = additionalCode(x, isNegative);
    std::reverse(result.begin(), result.end());
    result.push_back(result[result.size() - 1]);
    std::reverse(result.begin(), result.end());
    return result;
}

void printVector(std::vector<int> x) {
    for (auto i : x)
        std::cout << i;
    return;
}

int main() {

    setlocale(LC_ALL, "Russian");

    std::string closeProgramChoise = "";
    do {
        int a = 1, b = 0;
        bool isNegative = true;
        bool correctInput;
        do {
            correctInput = true;
            std::string str;
            std::cout << "Введите границы диапазона\n";
            std::cout << "a = ";
            std::cin >> str;
            if (!isValidNumber(str, a)) {
                correctInput = false;
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
            }
            if (correctInput) {
                std::cout << "b = ";
                std::cin >> str;
                if (!isValidNumber(str, b)) {
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
        } while (!correctInput);

        int c = 0;
        std::string changeCChoise = "";
        do {
            bool correctInput = true;
            do {
                std::string str;
                std::cout << "Введите значение целого десятичного числа\nc = ";
                std::cin >> str;

                if (!isValidNumber(str, c)) {
                    correctInput = false;
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                }
                else {
                    isNegative = (c < 0) || (str[0] == '-' && c == 0);
                    break;
                }

                if (c < a || c > b)
                    correctInput = false;

                if (!correctInput)
                    std::cout << "Ошибка ввода числа c\n";

            } while (!correctInput);

            int n = 0;
            std::string machineCodeChangeChoise = "";

            do {
                machineCodeChangeChoise = "";
                bool correctInput;
                do {
                    correctInput = true;
                    std::string str;
                    std::cout   << "Введите номер машинного кода n:\n"
                                << "1 - прямой код\n"
                                << "2 - обратный код\n"
                                << "3 - дополнительный код\n"
                                << "4 - модифицированный дополнительный код\n"
                                << "n = ";
                    std::cin >> str;
                    if (!isValidNumber(str, n)) {
                        correctInput = false;
                        std::cin.clear();
                        std::cin.ignore(INT_MAX, '\n');
                    }
                    if (n < 1 || n > 4)
                        correctInput = false;

                    if (!correctInput)
                        std::cout << "Ошибка ввода номера машинного кода\n";
                } while (!correctInput);

                std::cout << "Наименование машинного кода: ";
                switch (n) {
                    case 1:
                        std::cout << "прямой код\nc = ";
                        printVector(binCode(c, isNegative));
                        break;
                    case 2:
                        std::cout << "обратный код\nc = ";
                        printVector(reverseCode(c, isNegative));
                        break;
                    case 3:
                        std::cout << "дополнительный код\nc = ";
                        printVector(additionalCode(c, isNegative));
                        break;
                    case 4:
                        std::cout << "модифицированный дополнительный код\nc = ";
                        printVector(modAdditionalCode(c, isNegative));
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

    exit(0);
}

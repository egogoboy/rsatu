#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <set>
#include <stdexcept>
#include <string>
#include "Operations.h"
#include "Num.h"


bool isValidNumber(const std::string &str, int &number);
void getInputNums(int &a, int &b);
void getNumberOfOperation(int &n);
bool processAnswer(std::string ans); 
bool checkNumberOfOperation(int n);
std::string getYNAnswer(std::string str);
void printTable(int a, int b, int c);
std::string printDiv(std::vector<std::string> &result, int countOfOperations);
std::string rToNormal(std::string r);
void roundR(std::string &r);

int a, b;
std::set<std::string> YesNoVariants = {"y", "n", "да", "нет"};

int main() {
 
    bool programWork = true;
    do {
        getInputNums(a, b);

        Num first(std::abs(a));
        Num second(-1 * std::abs(b));

        std::string ans;
        int n;
        bool numberOfDiv = false;
        do {
            getNumberOfOperation(n);

            if (checkNumberOfOperation(n)) {
                std::cout << "Без восстановления остатка со сдвигом делителя\n";
                int zA, zB, zR;
                zA = (a < 0 ? 1 : 0);
                zB = (b < 0 ? 1 : 0);
                zR = (zA + zB) % 2;
                std::cout << "zA = " << zA << "\n";
                std::cout << "zB = " << zB << "\n";
                std::cout << "zR = zA (+) zB = " << zA << " (+) " << zB << " = " << zR << " => \"" << (zR == 0 ? "+" : "-") << "\"\n";
                printTable(std::abs(a), std::abs(b), std::abs(b) * -1);
                std::cout << "\n";
                std::vector<std::string> res = Operations::div(std::abs(a), std::abs(b) * -1, first.getModCode(), second.getModCode());

                int countOfOperations = res[0].size() - 1;
                int countOfPrint = 1;
                bool continuePrint = true;
                std::string r;
                while (countOfPrint <= countOfOperations && continuePrint) {
                    r = printDiv(res, countOfPrint);
                    countOfPrint++;
                    if (countOfPrint != countOfOperations) {
                        ans = getYNAnswer("Продолжить деление?\nY/N (Да/Нет): ");
                        continuePrint = processAnswer(ans);
                    } else { 
                        continuePrint = false;
                    }
                }

                int k = r.size() - 1;
                while (k > 0 && r[k] == '0')
                    k--;

                if (k != 0)
                    r = r.substr(0, k + 1);
    
                std::cout << "R(2) = " << (zR == 0 ? "+" : "-") << r[0] << "," << r.substr(1, r.size() - 1) << "\n";
                std::cout << "R(10) = " << (zR == 1 ? "-" : "") << rToNormal(r) << "\n";
            } else {
                std::cout << "Способ деления не реализован\n";
            }

            ans = getYNAnswer("Изменить номер способа деления?\nY/N (Да/Нет): ");
            numberOfDiv = processAnswer(ans);
        } while (numberOfDiv);
        ans = getYNAnswer("Изменить значение чисел?\nY/N (Да/Нет): ");
        programWork = processAnswer(ans);
    } while (programWork);

    return 0;
}

std::string rToNormal(std::string r) {

    double res = 0;
    int power = -1;
    for (int i = 1; i < r.size(); i++) {
        res += (r[i] - '0') * double(std::pow(2, power));
        power--;
    }
    
    std::string result = std::to_string(res);
    result[1] = ',';

    int k = result.size() - 1;
    while (k > 0 && result[k] == '0')
        k--;

    if (k != 0)
        result = result.substr(0, k + 1);

    return result;

}

std::string printDiv(std::vector<std::string> &result, int countOfOperations) {
    int countOfPrinted = 0;
    int i = 0;

    std::string r = "";

    std::cout << std::setw(8 + result[i].size()) << std::right << result[i++] << "\n";
    
    while (countOfPrinted <= countOfOperations) {
        std::cout << std::setw(8) << result[i++] << "\n";
        std::cout << std::setw(8 + result[i].size()) << std::right << result[i++] << "\n";
        std::cout << std::setw(10 + result[i - 1].size()) << std::right<< result[i++] << "\n";
        if (result[i].substr(0, 2) == "00") {
            std::cout << "  1 <-  " << result[i++] << " > 0" << "\n";
            r += "1";
        }
        else {
            std::cout << (countOfPrinted == 0 ? " 0, <-  " : "  0 <-  ") << result[i++] << " < 0" << "\n";
            r += "0";
        }

        countOfPrinted++;
    }
    
    bool isRounded = false;
    if (r.size() == result[0].size() - 1) {
        isRounded = true;
        roundR(r);       
    }
    
    std::cout << "|R|" << (isRounded ? "(округ)" : "") << " = " << r[0] << "," << r.substr(1, r.size() - 1) << "\n";
    return r;
}

void roundR(std::string &r) {
    bool carry = r[r.size() - 1] - '0';
    for (int i = r.size() - 2; i >= 0; i--) {
        if (r[i] != '.') {
            if (carry && r[i] == '1') {
                r[i] = '0';
            }
            else if (carry) {
                r[i] = '1';
                carry = false;
            }
        }
    }
}

void printTable(int a, int b, int c) {
    Num first(a);
    Num second(b);
    Num third(c);
    std::cout << "     |A|        |B|        -|B|\n";
    std::cout << "ПК   " << std::left << std::setw(11) << first.getRightCode() << std::setw(11) << second.getRightCode() << std::setw(11) << third.getRightCode() << "\n";
    std::cout << "МДК  " << std::left << std::setw(11) << first.getModCode() << std::setw(11) << second.getModCode() << std::setw(11) << third.getModCode() << "\n";
}

void getInputNums(int &a, int &b) {
    bool correctInput;
    do {
        std::string inputA, inputB;
        correctInput = true;
        std::cout << "Введите 2 целых десятичных числа (|A| < |B|):\n";
        std::cout << "A = ";
        std::cin >> inputA;
        std::cout << "B = ";
        std::cin >> inputB;
        
        if (!isValidNumber(inputA, a) || !isValidNumber(inputB, b)) {
            correctInput = false;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        else if (std::abs(a) >= std::abs(b)) {
            correctInput = false;
        }

        if (!correctInput) {
            std::cerr << "Ошибка ввода значений чисел\n";
        }
        else {
            Num first(a);
            Num second(b);
            std::cout << "A(2) = " << (a < 0 ? "-" : "") << first.getBinCode() << "\n";
            std::cout << "B(2) = " << (a < 0 ? "-" : "") << second.getBinCode();
            std::cout << "\n";
        }
    } while (!correctInput);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void getNumberOfOperation(int& n) {
    bool correctInput;
    do {
        correctInput = true;
        std::string inputN;

        std::cout << "Введите номер способа деления n:\n";
        std::cout << "1 - ВОСО\n";
        std::cout << "2 - ВОСД\n";
        std::cout << "3 - БОСО\n";
        std::cout << "4 - БОСД\n";
        std::cout << "n = ";
        
        std::cin >> inputN;

        if (!isValidNumber(inputN, n)) {
            correctInput = false;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }

        if (n < 1 || n > 4)
            correctInput = false;

        if (!correctInput) {
            std::cout << "Ошибка ввода номера способа деления\n";
        }

    } while (!correctInput);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool checkNumberOfOperation(int n) {
    return n == 4;
}

bool processAnswer(std::string ans) {
    if (ans == "y" || ans == "да") {
        return true;
    }
    return false;
}

std::string getYNAnswer(std::string message) {
    std::string s;
    
    bool correctInput = true;
    do {
        if (!correctInput) {
            if (message == "Изменить номер способа деления?\nY/N (Да/Нет): ") {
                std::cout << "Ошибка ввода запроса на изменение номера способа деления\n";
            }
            else if (message == "Продолжить деление?\nY/N (Да/Нет): ") {
                std::cout << "Ошибка ввода запроса на продолжение деления\n";
            }
            else if (message == "Изменить значение чисел?\nY/N (Да/Нет): ") {
                std::cout << "Ошибка ввода запроса на изменение чисел\n";
            }
            }
        
        std::cout << message;
        correctInput = true;
        std::cin >> s;

        for (int i = 0; i < s.size(); i++)
            s[i] = std::tolower(s[i]);

        if (YesNoVariants.count(s) == 0)
            correctInput = false;

    } while (!correctInput);

    return s;
}

bool isValidNumber(const std::string &str, int &number) {
    try {
        size_t idx;
        number = std::stoi(str, &idx);
        return idx == str.size();
    }
    catch (std::invalid_argument&) {
        return false;
    }
    catch (std::out_of_range&) {
        return false;
    }
}

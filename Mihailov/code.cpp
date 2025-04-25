#include <cctype>
#include <climits>
#include <ios>
#include <iostream>
#include <limits>
#include <set>
#include <algorithm>
#include <string>

#include "Num.h"
#include "Operations.h"

bool isValidNumber(const std::string& str, int& number);

void getInputNums(int& a, int& b);
void printSum(std::string first, std::string second);
void getNumberOfOperation(int& n);

bool checkNumberOfOperation(int n);
bool processAnswer(std::string ans);
std::string getYNAnswer(std::string message);

std::set<std::string> YesNoVariants = {"y", "n", "да", "нет"};
int a, b;

int main() {
    
    bool programWork = true;
    do {
        getInputNums(a, b); 
         
        Num first(-a);
        Num second(b);

        std::string ans;

        int n;
        do {
            getNumberOfOperation(n);

            if (checkNumberOfOperation(n)) {
                printSum(first.getModCode(), second.getModCode());
            } else {
                std::cout << "Операция не реализованна\n";
            }

            ans = getYNAnswer("Изменить номер операции? Да/Нет (Y/N)\n");
            if (!processAnswer(ans))
                break;
        } while (!checkNumberOfOperation(n));

        ans = getYNAnswer("Изменить значения чисел? Да/Нет (Y/N)\n");
        if (!processAnswer(ans))
            programWork = false;

    } while (programWork);

}

void printSum(std::string first, std::string second) {
 
    std::cout << "-A + B\n";
    std::cout << "A(МДК) = " << first << "   ";
    std::cout << "B(МДК) - " << second << "\n";
    
    int maxNumSize = std::max(first.size(), second.size());
    Operations::alligment(first, maxNumSize);
    Operations::alligment(second, maxNumSize);

    std::string result = Operations::sum(first, second);

    std::cout << "  " << first << "\n";
    std::cout << " +\n";
    std::cout << "  " << second << "\n";

    std::string sideLine = "---------------------------------------------------";
    std::cout << sideLine.substr(0, maxNumSize + 4) << "\n";
    std::cout << "  " << result << "\n";

    std::cout << "R(МДК) = " << result << "\n";
    
    if (result.substr(0, 2) == "11") {
        std::cout << "R(ПК) = 1" <<  Num(-a + b).getRightCode() << std::endl;
    }
    std::cout << "R(2) = " << (-a + b < 0 ? "-" : "") << Num(-a +b).getBinCode() << std::endl;
    std::cout << "R(10) = " << -a + b << "\n";
}

void getInputNums(int& a, int& b) {
    bool correctInput;
    do {
        std::string inputA, inputB;
        correctInput = true;

        std::cout << "Введите 2 целых десятичных числа A и B:\n";
        std::cout << "a = ";
        std::cin >> inputA;
        std::cout << "b = ";
        std::cin >> inputB;

        if (!isValidNumber(inputA, a) || !isValidNumber(inputB, b)) {
            correctInput = false;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        
        if (!correctInput) {
            std::cout << "Ошибка ввода значений чисел\n";
        }
        else {
            Num first(a);
            Num second(b);
            std::cout << "A(2) = " << (a < 0 ? "-" : "");
            std::cout << first.getBinCode();
            std::cout << "    B(2) = " << (b < 0 ? "-" : "");
            std::cout << second.getBinCode();
            std::cout << std::endl;
        }
    } while (!correctInput);
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void getNumberOfOperation(int& n) {
    bool correctInput;
    do {
        correctInput = true;
        std::string inputN;

        std::cout << "Введите номер выполняемой операции n\n";
        std::cout << "1 - A + B\n";
        std::cout << "2 - A - B\n";
        std::cout << "3 - -A + B\n";
        std::cout << "4 - -A - B\n";
        std::cout << "n = ";
        
        std::cin >> inputN;

        if (!isValidNumber(inputN, n)) {
            correctInput = false;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }

        if (n < 0 || n > 4)
            correctInput = false;

        if (!correctInput) {
            std::cout << "Ошибка ввода номера операции\n";
        }

    } while (!correctInput);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool checkNumberOfOperation(int n) {
    return n == 3;
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

bool isValidNumber(const std::string& str, int& number) {
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

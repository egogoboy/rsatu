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
            std::cout << "������� ������� ���������\n";
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
                std::cout << "������ ����� ������ ���������\n";
            }
        } while (!correctInput);

        int c = 0;
        std::string changeCChoise = "";
        do {
            bool correctInput = true;
            do {
                std::string str;
                std::cout << "������� �������� ������ ����������� �����\nc = ";
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
                    std::cout << "������ ����� ����� c\n";

            } while (!correctInput);

            int n = 0;
            std::string machineCodeChangeChoise = "";

            do {
                machineCodeChangeChoise = "";
                bool correctInput;
                do {
                    correctInput = true;
                    std::string str;
                    std::cout   << "������� ����� ��������� ���� n:\n"
                                << "1 - ������ ���\n"
                                << "2 - �������� ���\n"
                                << "3 - �������������� ���\n"
                                << "4 - ���������������� �������������� ���\n"
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
                        std::cout << "������ ����� ������ ��������� ����\n";
                } while (!correctInput);

                std::cout << "������������ ��������� ����: ";
                switch (n) {
                    case 1:
                        std::cout << "������ ���\nc = ";
                        printVector(binCode(c, isNegative));
                        break;
                    case 2:
                        std::cout << "�������� ���\nc = ";
                        printVector(reverseCode(c, isNegative));
                        break;
                    case 3:
                        std::cout << "�������������� ���\nc = ";
                        printVector(additionalCode(c, isNegative));
                        break;
                    case 4:
                        std::cout << "���������������� �������������� ���\nc = ";
                        printVector(modAdditionalCode(c, isNegative));
                        break;
                }
                std::cout << "\n";
                do {
                    if (machineCodeChangeChoise != "")
                        std::cout << "������ ����� ��������� ������ ��������� ����\n";
                    std::cout << "�������� ����� ��������� ����?\ny/n (��/���)\n";
                    std::cin >> machineCodeChangeChoise;
                } while (machineCodeChangeChoise != "n" && machineCodeChangeChoise != "���" && machineCodeChangeChoise != "y" && machineCodeChangeChoise != "��");
            } while (machineCodeChangeChoise == "y" || machineCodeChangeChoise == "��");
            do {
                if (changeCChoise != "")
                    std::cout << "������ ����� ������� �� ��������� ����� c\n";
                std::cout << "�������� �������� ����� c?\ny/n (��/���)\n";
                std::cin >> changeCChoise;
            } while (changeCChoise != "n" && changeCChoise != "���" && changeCChoise != "y" && changeCChoise != "��");

            } while (changeCChoise == "y" || changeCChoise == "��");
            do {
                if (closeProgramChoise != "")
                    std::cout << "������ ����� �� ���������� ������ ���������\n";
                std::cout << "��������� ������ ���������?\ny/n (��/���)\n";
                std::cin >> closeProgramChoise;
            } while (closeProgramChoise != "n" && closeProgramChoise != "���" && closeProgramChoise != "y" && closeProgramChoise != "��");


    } while (closeProgramChoise == "n" || closeProgramChoise == "���");

    exit(0);
}

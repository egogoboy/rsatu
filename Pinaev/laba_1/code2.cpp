#include <clocale>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include "inf.h"

void calcEntropy(std::string &text); 


int main() {

    setlocale(LC_ALL, "Russian");
    
    std::string s = "йцукенгшщзхъфывапролджэячсмитьбюЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM[]{};':\",.<>/?1234567890()*&^%$#@!~`ёЁa";
    
    std::cout << s << "\n";

    std::cout << "Введите значение энтропии: ";
    double informative;
    std::cin >> informative;
    
    double result_informative = -informative;
    std::string text = "";

    int cur = 0;
    while (cur < s.size() && std::abs(result_informative - informative) > 0.01) {
        if (result_informative < informative)
            cur++;
        text += s[cur];
        
        result_informative = inf::calcInf(text);
    }

    std::ofstream fout("result.txt");
    
    fout << text << std::endl;

    fout.close();
    //std::cout << "Сгенерированный текст записан в файл \"result.txt\"\n";

    calcEntropy(text);   
}

void calcEntropy(std::string &text) {
    std::map<char, int> letters;

    for (char c : text) {
        letters[c]++;
    }

    std::map<char, double> infOfLetters;
    std::cout << "Letter        Letter's informative\n";
    for (auto element : letters) {
        std::cout << element.first << " - " << element.second << std::setfill(' ') << std::setw(10);
        infOfLetters[element.first] = (double)element.second / text.size();
        std::cout << "P" << element.first << " = " << infOfLetters[element.first] << std::endl;
    }

    double informative = 0;
    for (auto i : infOfLetters) {
        informative += i.second * std::log2(i.second);
    }
    informative *= -1;

    std::cout << "\nH = " << informative << std::endl;
}

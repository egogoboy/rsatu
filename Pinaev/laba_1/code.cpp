#include <clocale>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>

int main() {

    setlocale(LC_ALL, "Russian");
    std::map<char, int> letters;
    
    std::ifstream fin;
    std::string fileHandler = "";
    do {
        if (fileHandler != "") {
            std::cerr << "Ошибка открытия файла \"" << fileHandler << "\"! Возможно, такого файла не существует.\n";
        }
        std::cout << "Введите название тектового файла: ";
        std::cin >> fileHandler;
        fin.open(fileHandler);
    } while (!fin.is_open());
    
    std::string text = "";
    getline(fin, text);
    
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

#include <iostream>
#include "Dictionary.h"

int main() {
    std::cout << "Частотный словарь\n";

    Dictionary dictionary("text.txt");   

    std::cout << "Словарь по алфавиту:\n";
    dictionary.printDictionaryByAlphabet();
    std::cout << "---------------------------------------------------\n";
    std::cout << "Словарь по частоте:\n";
    dictionary.printDictionaryByFrequency();
    std::cout << "---------------------------------------------------\n";
    std::cout << "Самое редкое слово:\n";
    dictionary.printTheMostUnfrequentWord();
    std::cout << "---------------------------------------------------\n";
    std::cout << "Слова на букву d:\n";
    dictionary.printWordsOnLetter('d');

    return 0;
}

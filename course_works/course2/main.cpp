#include "classes/ProcessUserAction.h"
#include "classes/Anagram.h"
#include "classes/Tests.h"

#include <iostream>
#include <string>

const std::string border = "-----------------------------------------------------\n";

void processAction(const std::string& action, Anagram& inputData);

void printHeader();

int main() {

    printHeader();

    try {
        while (true) {
            std::string inputFileName = ProcessUserAction::getInputFile();

            Anagram inputData(inputFileName);

            std::string action;
           
            do {
                std::cout << border;
                action = ProcessUserAction::getUserAction();
                std::cout << border;

                processAction(action, inputData);
            } while (action != ProcessUserAction::GET_NEW_TEXT && action != ProcessUserAction::CLOSE_PROGRAM);
            
            if (action == ProcessUserAction::CLOSE_PROGRAM)
                break;
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}

void processAction(const std::string& action, Anagram& inputData) {

    if (action == ProcessUserAction::PRINT_ALL_ANAGRAMS) {
        std::cout << "Все анаграммы: \n";
        inputData.printAllAnagrams();
    }

    if (action == ProcessUserAction::PRINT_NON_ANAGRAMS) {
        std::cout << "Слова без анаграмм: \n";
        inputData.printWordsWithoutAnagrams();
    }

    if (action == ProcessUserAction::FIND_ANAGRAMS) {

        std::cout << "Введите слово, для которого необходимо найти анаграмму\n";
        std::cout << "Слово: ";
        std::string word;
        std::getline(std::cin, word);
        std::vector<std::string> findedAnagrams = inputData.findAnagrams(word);

        if (findedAnagrams.empty()) {
            std::cout << "В тексте нет анаграмм к этому слову\n";
        }
        else if (findedAnagrams.size() == 1 && findedAnagrams[0] == word) {
            std::cout << "В тексте нет анаграмм к этому слову, но оно встречается\n";
        } else {
            std::cout << "Анаграммы к этому слову: ";
            for (auto x : findedAnagrams)
                if (x != word)
                    std::cout << x << " ";
            std::cout << std::endl;
        }

    }
}

void printHeader() {

    std::cout << "                      __ _  _ __    __ _   __ _  _ __   __ _  _ __ ___  \n";
    std::cout << "                     / _` || '_ \\  / _` | / _` || '__| / _` || '_ ` _ \\ \n";
    std::cout << "                    | (_| || | | || (_| || (_| || |   | (_| || | | | | |\n";
    std::cout << "                     \\__,_||_| |_| \\__,_| \\__, ||_|    \\__,_||_| |_| |_|\n";
    std::cout << "                                          |___/                         \n";



}

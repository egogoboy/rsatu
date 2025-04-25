#include "ProcessUserAction.h"
#include "CustomExceptionHandler.h"
#include "Tests.h"

std::string ProcessUserAction::getInputFile() {
    std::string inputStream = getUserChooseOfInputStream();
    std::string inputFileName;

    if (inputStream == FROM_DEFAULT_FILE) {
        inputFileName = DEFAULT_FILE_NAME;
    }

    if (inputStream == FROM_CUSTOM_FILE) {
        inputFileName = getCustomFileName();
    }

    if (inputStream == FROM_CONSOLE) {
        inputFileName = getDataFromConsole();
    }

    if (inputStream == FROM_TESTS) {
        Tests::generateTestText(5000, TESTS_FILE_NAME);
        inputFileName = TESTS_FILE_NAME;
    }
    

    return inputFileName;
}

std::string ProcessUserAction::getUserAction() {
    std::string choose = "";
    while (choose != "1" && choose != "2" && choose != "3" && choose != "4" && choose != "5") {
        std::cout << "Что нужно сделать:\n";
        std::cout << "1 - вывести все анаграммы\n";
        std::cout << "2 - вывести все не анаграммы\n";
        std::cout << "3 - вывести анаграммы по слову\n";
        std::cout << "4 - получить другой текст\n";
        std::cout << "5 - завершить программу\n";
        std::cout << "Выбор: ";

        std::getline(std::cin, choose);

        if (choose != "1" && choose != "2" && choose != "3" && choose != "4" && choose != "5") {
            std::cout << "Нет такого варианта выбора\n";
        }
    }

    return processUserActionChoose(choose);
}

std::string ProcessUserAction::processUserActionChoose(const std::string& choose) {
    int x = std::stoi(choose);

    switch (x) {
        case 1: return PRINT_ALL_ANAGRAMS;
        case 2: return PRINT_NON_ANAGRAMS;
        case 3: return FIND_ANAGRAMS;
        case 4: return GET_NEW_TEXT;
        case 5: return CLOSE_PROGRAM;
    }

    throw UnknownUserChooseException("Неизвестный вариант выбора");
}

std::string ProcessUserAction::getUserChooseOfInputStream() {

    std::string choose = "";
    while (choose != "1" && choose != "2" && choose != "3" && choose != "4") {
        std::cout << "Откуда считать текст:\n";
        std::cout << "1 - стандартный файл\n";
        std::cout << "2 - свой файл\n";
        std::cout << "3 - консоль\n";
        std::cout << "4 - тесты\n";
        std::cout << "Выбор: ";
        
        std::getline(std::cin, choose);
        
        // Какой ужас... но мне лень это переписывать
        if (choose != "1" && choose != "2" && choose != "3" && choose != "4") {
            std::cout << "Нет такого варианта\n";
        }
    }

    return processUserInputStreamChoose(choose);
}

std::string ProcessUserAction::processUserInputStreamChoose(const std::string& choose) {

   int temp = std::stoi(choose);

    switch (temp) {
        case 1: return FROM_DEFAULT_FILE;
        case 2: return FROM_CUSTOM_FILE;
        case 3: return FROM_CONSOLE;
        case 4: return FROM_TESTS;
    }
    
    throw UnknownUserChooseException("Неизвестный вариант выбора");
}

std::string ProcessUserAction::getCustomFileName() {
    std::string fileName = "";

    std::cout << "Введите имя файла с расширением: ";
    std::cin >> fileName;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return fileName;
}

std::string ProcessUserAction::getDataFromConsole() {
    std::cout << "Введите текст, оканчивающийся знаком # (# не будет включен в текст): ";
    
    std::ofstream fout(CONSOLE_FILE_NAME);
    char c;
    do {
        std::cin.get(c);
        fout << c;
    } while (c != '#');

    fout.close();

    std::cin.clear();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return CONSOLE_FILE_NAME;
}

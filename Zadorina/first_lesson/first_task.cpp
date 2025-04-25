#include <iostream>
#include "classes/TPerson.h"
#include "classes/TSpisok.h"
#include "classes/TStudent.h"

int main() {
 
    TStudent student("sudakov", "egor", "urievich", "ipb-23", "2");
    std::cout << student.getFullData() << std::endl;

    std::string fileHandler;
    std::cout << "Использовать файл по умолчанию? y/n\n";
    char c;
    std::cin >> c;
    
    if (c == 'y') {
        fileHandler = "temp.dat";
    }
    else if (c == 'n') {
        std::cout << "Введите название файла с расширением: ";
        std::cin >> fileHandler;
    }

    TPerson firstPerson(fileHandler);   
    std::cout << "Человек инициализирован из файла " << fileHandler << std::endl;
    std::cout << "TPerson.getFullData() == " << firstPerson.getFullData() << std::endl;

    TSpisok spisok(fileHandler);
    std::cout << "Список инициализирован из файла " << fileHandler << std::endl;
    std::cout << "Длина списка: " << spisok.getCountOfPerson() << std::endl;

    std::cout << "Введите данные человека, которого необходимо добавить: \n";
    std::string surname, name, patronymic;
    
    std::cout << "Введите фамилию: ";
    std::cin >> surname;

    std::cout << "Введите имя: ";
    std::cin >> name;

    std::cout << "Введите отчество: ";
    std::cin >> patronymic;
    
    TPerson newPerson(surname, name, patronymic);
    spisok.addPerson(newPerson);

    std::cout << "Новый человек добавлен, размер списка: " << spisok.getCountOfPerson() << std::endl;

    std::cout << "Напишите данные какого человека необходимо получить: ";
    int i; std::cin >> i;
    std::cout << "ФИО " << i << "-го человека: " << spisok.getFIO(i) << std::endl;
    std::cout << "Ссылка на " << i << "-го человека: " << &spisok.getPersonLink(i) << std::endl;
    return 0;
}

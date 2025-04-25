#include <cstdio>
#include <iostream>

#include "classes/TPerson.h"
#include "classes/TSpisok.h"
#include "classes/TStudent.h"
#include "classes/TSotrudnik.h"

std::string defaultFile = "temp.dat";

TPerson* addNewPerson();
void editPerson(TSpisok& spisok);
void deletePerson(TSpisok& spisok);

std::vector<std::string> parsePersonData(std::string personData);
void getFIO(std::string& surname, std::string& name, std::string& patronymic);

int main() {
 
//    TStudent student("sudakov", "egor", "urievich", "ipb-23", "2");
 //   std::cout << student.getFullData() << std::endl;

    std::string fileHandler;
    std::cout << "Использовать файл по умолчанию? y/n\n";
    char c;
    std::cin >> c;
    
    if (c == 'y') {
        fileHandler = defaultFile;
    }
    else if (c == 'n') {
        std::cout << "Введите название файла с расширением: ";
        std::cin >> fileHandler;
    }
    
    TSpisok spisok(fileHandler);
    std::cout << "Список инициализирован из файла " << fileHandler << std::endl;
    std::cout << "Длина списка: " << spisok.getCountOfPerson() << std::endl;

    char n;
    do {
        std::cout << "Введите номер операции, которую вы хотите выполнить:\n";
        std::cout << "1 - добавить нового человека\n";
        std::cout << "2 - редактировать данные человека\n";
        std::cout << "3 - удалить человека\n";
        std::cout << "4 - завершить программу\n";
        std::cin >> n;

        switch (n) {
            case '1':
                spisok.addPerson(addNewPerson());
            break;
            case '2':
                editPerson(spisok);
            break;
            case '3':
                deletePerson(spisok);
            break;
            case '4':
                continue;
            break;
            default:
                std::cout << "Неверный номер операции\n";
            break;
        }
   } while (n != '4');

        
    return 0;
}

std::vector<std::string> parsePersonData(std::string personData) {
    std::vector<std::string> result(1, "");
    
    for (auto i : personData) {
        if (i == ' ') {
            result.push_back("");
        }
        else {
            result[result.size() - 1] += i;
        }
    }

    return result;
}

void deletePerson(TSpisok& spisok) {
    std::cout << "Количество людей в списке: " << spisok.getCountOfPerson() << "\n";
    std::cout << "Введите номер человека, которого необходимо удалить: ";
    
    int id;
    std::cin >> id;

    TPerson* editingPerson = &spisok.getPersonLink(id - 1);
    std::cout << "Данные человека: " << editingPerson->getFullData();

    spisok.removePerson(id - 1);
    std::cout << "\nЧеловек удалён из списка\n";

    return;

}

void editPerson(TSpisok& spisok) {
    std::cout << "Количество людей в списке: " << spisok.getCountOfPerson() << "\n";
    std::cout << "Введите номер человека, данные которого необходимо отредактировать: ";
    
    int id;
    std::cin >> id;

    TPerson& editingPerson = spisok.getPersonLink(id - 1);
    std::cout << "Данные человека: " << editingPerson.getFullData() << "\n";

    std::vector<std::string> personData = parsePersonData(editingPerson.getFullData());

    std::cout << "Введите новые данные через пробел: ";
    std::string newFullData;
    std::getline(std::cin, newFullData);
    std::getline(std::cin, newFullData);

    std::vector<std::string> newPersonData = parsePersonData(newFullData);
/*
    if (personData.size() != newPersonData.size()) {
        std::cerr << "Несоответствие типов!\n";
        return;
    }
*/
    TPerson* newPerson;
    switch (personData.size()) {
        case 3:
            newPerson = new TPerson(newPersonData[0], newPersonData[1], newPersonData[2]);
        break;
        case 4:
            newPerson = new TSotrudnik(newPersonData[0], newPersonData[1], newPersonData[2], newPersonData[3]);
        break;
        case 5:
            newPerson = new TStudent(newPersonData[0], newPersonData[1], newPersonData[2], newPersonData[3], newPersonData[4]);
        break;
        default:
            std::cerr << "Неизвестный тип\n";
        return;
    }

    spisok.editPerson(id - 1, newPerson);
}

TPerson* addNewPerson() {
    std::cout << "Введите, кто этот человек:\n";
    std::cout << "1 - обычный челвоек (TPerson)"  << "\n";
    std::cout << "2 - студент (TStudent)" << "\n";
    std::cout << "3 - сотрудник (TSotrudnik)"  << "\n";
    std::string inputType;
    std::cin >> inputType;

    int type = std::stoi(inputType);
    
    std::cout << "Введите данные человека, которого необходимо добавить: \n";
    TPerson* newPerson;
    std::string name, surname, patronymic;
    getFIO(surname, name, patronymic);

        switch (type) {
        case 1: 
            newPerson = new TPerson(name, surname, patronymic);
        break;
        case 2:
            {
                std::string group, course;
                std::cout << "Введите имя группы: \n";
                std::cin >> group;
                std::cout << "Введите курс: \n";
                std::cin >> course;
                newPerson = new TStudent(name, surname, patronymic, group, course);
            }
        break;
        case 3:
            {
                std::string tabel;
                std::cout << "Введите табельный номер: \n";
                std::cin >> tabel;
                newPerson = new TSotrudnik(name, surname, patronymic, tabel);
            }
        break;
    }
    return newPerson;
}

void getFIO(std::string& name, std::string& surname, std::string& patronymic) {
    std::cout << "Введите имя: \n";
    std::cin >> name;
    std::cout << "Введите фамилию: \n";
    std::cin >> surname;
    std::cout << "Введите отчество: \n";
    std::cin >> patronymic;
}

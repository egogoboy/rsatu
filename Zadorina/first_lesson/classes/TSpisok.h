#ifndef TSPISOK_H
#define TSPISOK_H

#include <cstdio>
#include <fstream>
#include <list>
#include <string>
#include "TPerson.h"

class TSpisok {
    public:

        TSpisok() {
            loadFromFile_("temp.dat");
        }

        TSpisok(std::string fileHandler) {
            loadFromFile_(fileHandler); 
        }

        ~TSpisok() {
            std::ofstream fout("result.txt");
            while (!persons_.empty()) {
                TPerson tempPerson = persons_.front();
                fout << tempPerson.getFullData() << std::endl;
                persons_.pop_front();
            }
            fout.close();
            std::cout << "Результат записан в файл result.txt\n";
        }

        void addPerson(TPerson newPerson) {
            persons_.push_back(newPerson);
        }

        void removePerson(int i) {
            std::list<TPerson> tempPerson;
            if (i >= 0 && i < persons_.size()) {
                int counter = 0;
                for (TPerson& j : persons_) {
                    if (counter != i) {
                        tempPerson.push_back(persons_.back());
                    }
                    counter++;
                }
            }
            persons_ = tempPerson;
        }

        TPerson& getPersonLink(int i) {
            if (i >= 0) {
                int counter = 1;
                if (i < persons_.size()) {
                    for (auto& j : persons_) {
                        if (counter == i) {
                            return j;
                        }
                        else {
                            counter++;
                        }
                    }
                }
            }
            return persons_.front();
        }

        std::string getFIO(int i) {
            if (i >= 0) {
                int counter = 1;
                if (i < persons_.size()) {
                    for (auto j : persons_) {
                        if (counter == i) {
                            return j.getFullData();
                        }
                        else {
                            counter++;
                        }
                    }
                }
                std::cerr << "i value is too large!\n";
                return "";
            }
            std::cerr << "i value cannot be less than zero";
            return "";
        }

        int getCountOfPerson() {
            return persons_.size();
        }

    private:

        void loadFromFile_(std::string fileHandler) {
            std::ifstream fin(fileHandler);
            if (fin.is_open()) {
                while (!fin.eof()) {
                    std::string s, n, p;
                    fin >> s >> n >> p;
                    TPerson tempPerson(s, n, p);
                    if (!fin.eof())
                        persons_.push_back(tempPerson);
                }
            }
            else {
                std::cerr << "Не существует файла temp.dat\n";
            }
            fin.close();
        }

        std::list<TPerson> persons_;

};

#endif // TSPISOK_H

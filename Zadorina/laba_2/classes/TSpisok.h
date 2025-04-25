#ifndef TSPISOK_H
#define TSPISOK_H

#include <cstdio>
#include <fstream>
#include <list>
#include <string>
#include <vector>

#include "TPerson.h"
#include "TStudent.h"
#include "TSotrudnik.h"

class TSpisok {
    public:

        TSpisok() {
            loadFromFile_(DEFAULT_INPUT_FILE_HANDLER);
        }

        TSpisok(std::string fileHandler) {
            loadFromFile_(fileHandler); 
        }

        ~TSpisok() {
            std::ofstream fout(DEFAULT_OUTPUT_FILE_HANDLER);
            for (auto i : persons_) {
                fout << i->getFullData() << "\n";
            }
            fout.close();
            std::cout << "Результат записан в файл result.txt\n";
        }

        void addPerson(TPerson* newPerson) {
            persons_.push_back(newPerson);
        }

        void editPerson(int id, TPerson* newPerson) {
            if (id >= 0 && id < persons_.size()) {
                persons_[id] = newPerson;
                return;
            } 
            std::cerr << "out of range\n";
            return;

        }

        void removePerson(int i) {
            if (i >= 0 && i < persons_.size()) {
                for (int j = i + 1; j < persons_.size(); j++) {
                    persons_[j - 1] = persons_[j];
                }
            }
            persons_.resize(persons_.size() - 1);
        }

        TPerson& getPersonLink(int i) {
            if (i >= 0 && i < persons_.size())
                return *persons_[i];
            return *persons_[0];
        }

        std::string getFIO(int i) {
            if (i >= 0 && i < persons_.size())
                return persons_[i]->getFullData();
            return persons_[0]->getFullData();
        }

        int getCountOfPerson() {
            return persons_.size();
        }

    private:

        void loadFromFile_(std::string fileHandler) {
            std::ifstream fin(fileHandler);

            if (fin.is_open()) {
                while (!fin.eof()) {
                    std::string inputDataLine;
                    std::getline(fin, inputDataLine);
                    if (inputDataLine != "") {
                        TPerson *tempPerson = getPerson(inputDataLine);
                        if (!fin.eof())
                            persons_.push_back(tempPerson);
                    }
                }
            }
            else {
                //throw "Не существует файла " + fileHandler + "\n";
                std::cerr << "Не существует файла " + fileHandler + "\n";
            }
            fin.close();
        }

        std::vector<std::string> parseInputData(std::string input) {
            std::vector<std::string> result(1, "");
            for (auto x : input) {
                if (x == ' ')
                    result.push_back("");
                else
                    result[result.size() - 1] += x;
            }

            return result;
        }

        TPerson* getPerson(std::string input) {

            std::vector<std::string> inputData = parseInputData(input);

            switch (inputData.size()) {
                case 3: return new TPerson(inputData[0], inputData[1], inputData[2]);
                case 4: return new TSotrudnik(inputData[0], inputData[1], inputData[2], inputData[3]);
                case 5: return new TStudent(inputData[0], inputData[1], inputData[2], inputData[3], inputData[4]);
                default:
                    //throw "Unknown type!\n";
                        std::cerr << "unknown type!\n";
                        return new TPerson("", "", "");
            }

        }

        std::vector<TPerson*> persons_;
        const std::string DEFAULT_INPUT_FILE_HANDLER = "temp.dat";
        const std::string DEFAULT_OUTPUT_FILE_HANDLER = "result.txt";

};

#endif // TSPISOK_H

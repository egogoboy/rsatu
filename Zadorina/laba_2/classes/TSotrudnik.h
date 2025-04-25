#ifndef TSOTRUDNIK_H
#define TSOTRUDNIK_H

#include "TPerson.h"
#include <algorithm>
#include <string>


class TSotrudnik: public TPerson {
    
    public:

        TSotrudnik(std::string fileHandler): TPerson(fileHandler) {
            std::ifstream fin;
            fin.open(fileHandler);
            if (fin.is_open()) {
                fin >> _tabelNumber;
                fin.close();
            }
            else {
                throw "error when opening file";
            }
        }

        TSotrudnik(std::string name, std::string surname, std::string patronymic, std::string tabelNumber): 
                                                                    TPerson{surname, name, patronymic} {
 
            setTabelNumber(tabelNumber);
            
        }

        void setTabelNumber(std::string tabelNumber) {
            _tabelNumber = tabelNumber;
        }

        std::string getFullData() override {
            return TPerson::getFullData() + " " + _tabelNumber;
        }

        std::string getTableNumber() {
            return _tabelNumber;
        }

        void writeData(std::string fileHandler) override {
            TPerson::writeData(fileHandler);
            std::ofstream fout(fileHandler, std::ios::app);
            fout << _tabelNumber;
            std::cout << "student data is writed sucessfullly!\n";
            fout.close();
        }

    private:
        
        std::string _tabelNumber;
};

#endif // TSOTRUDNIK_H

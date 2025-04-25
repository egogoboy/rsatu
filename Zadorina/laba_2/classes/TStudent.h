#ifndef TSTUDENT_H
#define TSTUDENT_H

#include "TPerson.h"
#include <algorithm>
#include <string>

class TStudent : public TPerson {
    
    public:

        TStudent(std::string fileHandler): TPerson(fileHandler) {
            std::ifstream fin;
            fin.open(fileHandler);
            if (fin.is_open()) {
                fin >> _group >> _course;
                fin.close();
            }
            else {
                std::cerr << "error when opening file";
            }
        }

        TStudent(std::string name, std::string surname, std::string patronymic, std::string group, std::string course): 
                                                                    TPerson{surname, name, patronymic} {
 
            setGroup(group);
            setCourse(course);
            
        }

        std::string getFullData() override {
            return TPerson::getFullData() + " " + _group + " " + _course;
        }

        void writeData(std::string fileHandler) override {
            TPerson::writeData(fileHandler);
            std::ofstream fout(fileHandler, std::ios::app);
            fout << _course << " " << _group;
            std::cout << "student data is writed sucessfullly!\n";
            fout.close();
        }

        void setGroup(std::string group) {
            _group = group;
            std::transform(_group.begin(), _group.end(), _group.begin(), ::toupper);
        }

        void setCourse(std::string course) {
            if (std::stoi(course) >= 1 && std::stoi(course) <= 5) {
                _course = course;
            }
            else {
                std::cerr << "Курс должен находиться в диапазоне от 1 до 5!\n";
                _course = '0';
                return;
            }
        }
        
        std::string getCourse() {
            return _course;
        }

        std::string getGroup() {
            return _group;
        }

    private:

        std::string _group;
        std::string _course;
};

#endif // TSTUDENT_H

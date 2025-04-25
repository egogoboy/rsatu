#ifndef TPERSON_H
#define TPERSON_H

#include <cctype>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

class TPerson {
    
    public:

        TPerson() {

        }

        TPerson(std::string f, std::string n, std::string o) {
            setFam(f);
            setName(n);
            setOtch(o);
        }

        TPerson(std::string fileHandler) {
            std::ifstream fin;
            fin.open(fileHandler);
            std::string f, n, o;
            fin >> f >> n >> o;
            fin.close();
            setFam(f);
            setName(n);
            setOtch(o);
        }

        void writeData(std::string fileHandler) {
            std::ofstream fout;
            fout.open(fileHandler, std::ios::app);
            fout << fam_ << " " << name_ << " " << otch_ << std::endl;
            std::cout << "data is writed sucessfully!\n";
            fout.close();
        }
  
        virtual std::string getFullData() {
            return fam_ + " " + name_ + " " + otch_;
        }

        std::string getFam() {
            return fam_;
        }

        std::string getName() {
            return name_;
        }

        std::string getOtch() {
            return otch_;
        }

        void setFam(std::string fam) {
            for (int i = 0; i < fam.size(); i++) {
                fam[i] = std::toupper(fam[i]);
            }
            fam_ = fam;
        }

        void setName(std::string name) {
            for (int i = 0; i < name.size(); i++) {
                name[i] = std::tolower(name[i]);
            }
            name_ = name;
        }

        void setOtch(std::string otch) {
            for (int i = 0; i < otch.size(); i++) {
                otch[i] = std::tolower(otch[i]);
            }
            otch_ = otch;
        }

    private:
        std::string fam_, 
                    name_, 
                    otch_;
};

#endif // TPERSON_H

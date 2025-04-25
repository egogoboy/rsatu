#ifndef ANGEL_H
#define ANGEL_H

#include <string>
#include "Person.h"
class Angel : public Person {
    
    private:
        std::string _kasta;

    public:
        
        Angel(std::string name, std::string surname, int age, std::string kasta) : Person(name, surname, age) {
            _kasta = kasta;
            _name = "Angel1";
        }

        ~Angel() {
            std::cout << "Упала благодать\n";
        }

        void setKasta(std::string kasta) {
            _kasta = kasta;
        }

        std::string getFullData() {
            return _name + " " + std::to_string(_age) + " " + _kasta;
        }

        std::string getKasta() {
            return _kasta;
        }
};

#endif // ANGEL_H

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>


class Person {
    protected:
        std::string _name;
        int _age;

    private:
        std::string _surname;

        static inline int count = 0;
        
        std::string ImNotDemon() {
            return "bebebe? i'm not demon";
        }

    public:

        Person(std::string name, std::string surname, int age) {
            _name = name;
            _surname = surname;
            _age = age;
            count++;
        }
        
        ~Person() {
            std::cout << _name << " has been killed\n";
            count--;
        }

        void setName(std::string name) {
            _name = name;
        }

        std::string getName() {
            return _name;
        }

        void setAge(int age) {
            _age = age;
        }

        int getAge() {
            return _age;
        }

        virtual std::string getFullData() {
            return _name + " " + _surname + " " + std::to_string(_age);
        }

        static int getCount() {
            return count;
        }
};

#endif //PERSON_H

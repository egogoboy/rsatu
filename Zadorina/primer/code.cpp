#include <iostream>
#include "Person.h"
#include "Angel.h"

int main() {

    Person bob("Bobby", "Singer", 50);

    std::cout << bob.getName() << " " << bob.getAge() << std::endl;
    std::cout << Person::getCount() << std::endl;

    Person din("Dean", "Winchester", 30);
    std::cout << din.getFullData() << std::endl;
    std::cout << Person::getCount() << std::endl;

    for (int i = 0; i < 5; i++) {
        Angel angel("Angel", "Angelovich", 100000, "Blatnoy");
        std::cout << angel.getFullData() << std::endl;
        //std::cout << Angel::getCount() << std::endl;
    }
    
    Angel angel("Kaz", "Loh", 5, "V_Chechne");
    Person* person = &angel;
    std::cout << person->getFullData() << std::endl;

    person = &din;
    std::cout << person->getFullData() << std::endl;

}

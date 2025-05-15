#pragma once

#include <string>

#define RESET "\33[0m"
#define RED "\33[31m" 
#define GREEN "\33[32m"

class Colors {
public:
    static std::string red() {
        return RED;
    }

    static std::string green() {
        return GREEN;
    }

    static std::string reset() {
        return RESET;
    }
};

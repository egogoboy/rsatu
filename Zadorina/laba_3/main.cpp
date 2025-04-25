#include <iostream>

#include "classes/MyException.h"
#include "classes/TDat.h"
#include "classes/TDatLinInt.h"
#include "classes/TDatSplInt.h"

int main() {

    std::cout << "Лабораторная работа 3\n";
    
    try {
        TDat* points = new TDat("input.txt");
        TDat* pointsLin = new TDatLinInt("input.txt");
        TDat* pointsSpl = new TDatSplInt("input.txt");

        //std::cout << "TDat: " << points->getY(4) << "\n";
        std::cout << "TDatSplInt: " << pointsSpl->getY(4) << "\n";
        std::cout << "TDatLinInt: " << pointsLin->getY(4) << "\n";
    }
    catch (MyException e) {
        std::cout << e.getMessage() << "\n";
        return 0;
    }

    return 0;
}

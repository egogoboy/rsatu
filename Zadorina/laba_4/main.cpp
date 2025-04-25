#include "MyException.h"
#include "Matrix.h"
#include <iostream>

int main() {
    
    std::cout << "Перегрузка операторов\n";

    try {
        
        Matrix m1;
        m1.setMatrixSize(2, 3);
        m1.setMatrix();
        std::cout << "m1 = 3\n";
        m1 = 3;
        m1.printMatrix();

        Matrix m2;
        m2.setMatrixSize(2, 3);
        m2.setMatrix();
        
        std::cout << "m1 + m2\n";
        Matrix m3 = m1 + m2;
        m3.printMatrix();

        Matrix m4;
        m4.setMatrixSize(2, 3);
        m4.setMatrix();
        std::cout << "m4++\n";
        m4++;
        m4.printMatrix();


        Matrix m5;
        m5.setMatrixSize(2, 3);
        m5.setMatrix();

        //std::cout << m4.getMatrixSize() << " " << m5.getMatrixSize();

        std::cout << "m4 * m6\n";
        Matrix m6;
        m6 = m4 * m5;
        m6.printMatrix();
        
        std::cout << "m1 == m2: " << (m1 == m2 ? "true\n" : "false\n");
        std::cout << "m4 == m5: " << (m4 == m5 ? "true\n" : "false\n");
    } catch (MyException e) {
        std::cerr << "Error: " << e.getMessage() << "\n";
        return 0;
    }

    return 0;
}

#include <cctype>
#include <fstream>
#include <iostream>

int main() {
    std::ifstream fin("in.txt");
    
    while (!fin.eof()) {
        std::string c;
        for (int i = 0; i < 3; ++i) {
        fin >> c;
            if (std::isalpha(c[0])) {
                std::cout << c[0] - 'a' << " ";
            } else {
                std::cout << c << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}

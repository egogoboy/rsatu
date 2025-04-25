#include <iostream>

int main() {

    std::string c = "а";
    for (int i = 0; i < 34; i++) {
        std::cout << "'" << c << "', ";
        c[0]++;
    }

    return 0;
}

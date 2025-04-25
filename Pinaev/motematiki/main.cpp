#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

int main() {

    std::cout << "Введите диапазон значений (m < n):\n";
    int n, m;
    std::cout << "m = ";
    std::cin >> m;
    std::cout << "n = ";
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> table(n + 1, std::vector<std::pair<int, int>> (n + 1));

    std::string s = "";
    for (int i = m; i <= n; i++) {
        std::cout << s;
        for (int j = i; j <= n; j++) {
            table[i][j].first = i + j;
            table[i][j].second = i * j;
            std::string out = std::to_string(i + j) + "/" + std::to_string(i * j);
            std::cout << std::setw(8) << std::left << out;
        }
        std::cout << "\n";
        s += "        ";
    }

    std::string replic;

    do {
        std::cin >> replic;

        case replic
    } while (replic != "stop");

}

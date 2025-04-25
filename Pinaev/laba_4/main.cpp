#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>


int main() {

    int n, k;
    std::cout << "Введите количество операций: ";
    std::cin >> n;
    std::cout << "Введите количество связей: ";
    std::cin >> k;

    std::vector<int> countOfParents(n, 0);
    std::vector<std::vector<int>> operations(n, std::vector<int> (0));

    std::cout << "Введите n пар связей между операциями:\n";
    for (int i = 0; i < k; i++) {
        int a, b;
        std::cin >> a >> b;
        countOfParents[b - 1]++;
        operations[a - 1].push_back(b - 1);
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++)
        if (countOfParents[i] == 0) 
            q.push(i);

    std::queue<int> result;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < operations[current].size(); i++) {
            int child = operations[current][i];
            countOfParents[child]--;
            if (countOfParents[child] == 0)
               q.push(child);
        }

        result.push(current);
    }

    if (result.size() != n) {
        std::cout << "Частичное решение: ";
    }
    else {
        std::cout << "Полное решение: ";
    }
    while (!result.empty()) {
        std::cout << result.front() + 1 << " ";
        result.pop();
    }

    std::cout << std::endl;

    return 0;
}

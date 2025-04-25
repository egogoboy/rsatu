#include <iomanip>
#include <iostream>
#include <fstream>

void dfs(int from, int* color, int* n_number, int* m_number, 
         int* head, int* adj, int* next, int& cur_m, int& cur_n) {
    if (from == 0) {
        return;
    }

    int cur = head[from];
    color[from] = 1;
    m_number[from] = cur_m++;

    while (cur != 0) {
        if (color[adj[cur]] == 0) {
            dfs(adj[cur], color, n_number, m_number, head, adj, next, cur_m, cur_n);
        }
        cur = next[cur];
    }

    color[from] = 2;
    n_number[from] = cur_n--;
}

void printArray(int* arr, int size) {
    for (int i = 1; i <= size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    
    std::cout << "Enter filename: ";
    std::string filename;
    std::cin >> filename;

    std::ifstream fin(filename);
    if (!fin.is_open()) {
        return 1;
    }
    
    int n, m;
    fin >> n >> m;
    
    int head[n + 1];
    int adj[m + 1];
    int next[m + 1];
    int n_number[n + 1];
    int m_number[n + 1];
    int color[n + 1];

    for (int i = 1; i <= n; ++i) {
        head[i] = 0;
        n_number[i] = 0;
        m_number[i] = 0;
        color[i] = 0;
    }
    for (int i = 0; i <= m; ++i) {
        adj[i] = 0;
        next[i] = 0;
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        int from, to;
        fin >> from >> to;
        ++count;
        adj[count] = to;
        next[count] = head[from];
        head[from] = count;
    }

    int n_num = n;
    int m_num = 1;
    for (int i = 0; i <= n; ++i) {
        if (color[i] == 0) {
            dfs(i, color, n_number, m_number, head, adj, next, m_num, n_num);
        }
    }

    std::cout << std::setw(15) << std::left << "n numeration";
    printArray(n_number, n);

    std::cout << std::setw(15) << "m numeration";
    printArray(m_number, n);

    return 0;
}

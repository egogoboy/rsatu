#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <fstream>

int toNumber(char c);

int main() {

    int number_of_vertexes = 0;
    int number_of_edges = 0;
    std::cout << "Enter filename: ";
    std::string filename;
    std::cin >> filename;
    std::ifstream fin(filename);

    fin >> number_of_vertexes;

    fin >> number_of_edges;

    std::vector<std::pair<char, char>> edges(number_of_edges);
    std::vector<bool> uses(number_of_edges, false);
    std::vector<std::vector<int>> adj(27);
    std::vector<int> degree(27);

    for (int i = 0; i < number_of_edges; ++i) {
        fin >> edges[i].first >> edges[i].second;
        adj[toNumber(edges[i].first)].push_back(i);
        adj[toNumber(edges[i].second)].push_back(i);
        ++degree[toNumber(edges[i].first)];
        ++degree[toNumber(edges[i].second)];
    }

    char start = 0;
    int odd_count = 0;

    for (int i = 0; i < static_cast<int>(degree.size()); ++i) {
        if (degree[i] % 2 == 1) {
            odd_count++;
            start = 'a' + i;
        }
        if (degree[i] > 0 && start == 0) {
            start = 'a' + i;
        }
    }

    if (odd_count != 0 && odd_count != 2) {
        return 0;
    }

    std::stack<char> s;
    s.push(start);

    std::string res = "";

    while (!s.empty()) {
        char vertex = s.top();
        
        for (int i = 0; i < static_cast<int>(adj[toNumber(vertex)].size()); ++i) {
            if (!uses[adj[toNumber(vertex)][i]]) {
                std::pair<char, char> edge = edges[adj[toNumber(vertex)][i]];
                uses[adj[toNumber(vertex)][i]] = true;
                s.push(edge.first == vertex ? edge.second : edge.first);
                break;
            }
        }

        if (s.top() == vertex) {
            res.push_back(vertex);
            s.pop();
        }
    }

    std::reverse(res.begin(), res.end());

    std::cout << res << std::endl;

    return 0;
}

int toNumber(char c) {
    return c - 'a';
}

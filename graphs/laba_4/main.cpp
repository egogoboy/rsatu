#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

std::vector<std::vector<int>> Floyd(std::vector<std::vector<int>> weights);
void printMinimalPaths(const std::vector<std::vector<int>>& weights, const std::vector<std::vector<int>>& edges);
int main() {
    std::cout << "Floyd\n";
    std::ifstream fin("test.txt");
    int n;
    int m;
    fin >> n >> m;

    std::vector<std::vector<int>> weights(n, std::vector<int> (n, std::numeric_limits<int>::max() / 2 - 1));
    std::vector<std::vector<int>> edges(n, std::vector<int> (n, -1));

    for (int i = 0; i < n; ++i) {
        weights[i][i] = 0;
    }

    char from, to;
    int weight;
    for (int i = 0; i < m; ++i) {
        fin >> from >> to >> weight;
        from -= 'a';
        to -= 'a';
        if (weights[from][to] > weight) {
            weights[from][to] = weight;
            edges[from][to] = weight;
        }
        if (weights[to][from] > weight) {
            weights[to][from] = weight;
            edges[to][from] = weight;
        }
    }

    weights = Floyd(std::move(weights));
    printMinimalPaths(weights, edges);

    return 0;
}

std::vector<std::vector<int>> Floyd(std::vector<std::vector<int>> weights) {
    for (int k = 0; k < weights.size(); ++k) {
        for (int i = 0; i < weights.size(); ++i) {
            for (int j = 0; j < weights.size(); ++j) {
                weights[i][j] = std::min(weights[i][j], weights[i][k] + weights[k][j]);
            }
        }
    }

    return weights;
}

void printMinimalPaths(const std::vector<std::vector<int>>& weights, const std::vector<std::vector<int>>& edges) {
    for (int i = 0; i < weights.size(); ++i) {
        for (int j = i + 1; j < weights.size(); ++j) {
            if (weights[i][j] == edges[i][j]) {
                continue;
            }
            std::cout << static_cast<char>(i + 'a') << "-" << static_cast<char>(j + 'a') << "(" << weights[i][j] << "): ";
            int t = i;
            while (weights[t][j] > 0) {
                std::cout << static_cast<char>(t + 'a') << " ";
                int temp = 0;
                for (int x = 0; x < weights.size(); ++x) {
                    if (x != t && weights[t][j] == edges[t][x] + weights[x][j]) {
                        temp = x;
                    }
                }
                t = temp;
            }
            std::cout << static_cast<char>(t + 'a') << std::endl;
        }
    }
}

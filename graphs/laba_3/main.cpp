#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Trans.h"

//MST
//Minimal Spanning Tree

struct Edge {
    int start;
    int finish;
    int weight;
};

class SDS {
public:
    SDS(int n) {
        parent.resize(n);
        parent.reserve(n);
        weight.resize(n, 1);
        weight.reserve(n);

        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
    }

    void Link(int first, int second) {

        if (weight[first] < weight[second]) {
            parent[first] = second;
            weight[second] += weight[first];
        } else {
            parent[second] = first;
            weight[first] += weight[second];
        }
    }

    int GetRep(int i) {
        if (parent[i] != i) {
            parent[i] = GetRep(parent[i]);
        }

        return parent[i];
    }

    bool SameSet(int first, int second) {
        return GetRep(first) == GetRep(second);
    }

private:
    std::vector<int> parent;
    std::vector<int> weight;
};

int Kruscal(const std::vector<Edge>& edges, int n) {
    int cost = 0;
    int i = 0;
    SDS sds(n);

    while (i < n) {
        int r1 = sds.GetRep(edges[i].start);
        int r2 = sds.GetRep(edges[i].finish);

        if (r1 != r2) {
            std::cout << static_cast<char>(edges[i].start + 'a') << " " 
                      << static_cast<char>(edges[i].finish + 'a') << " " 
                      << edges[i].weight << std::endl;

            cost += edges[i].weight;
            sds.Link(r1, r2);
        }

        ++i;
    }

    return cost;
}

int main() {
    
    Trans::TranslateInput("test.txt");

    std::ifstream fin("test.txt");

    if (!fin.is_open()) {
        std::cerr << "File doesn't exist\n";
        return 0;
    }

    int n, m;
    fin >> n >> m;
    
    std::vector<Edge> edges(m);
    edges.reserve(m);

    for (int i = 0; i < m; ++i) {
        fin >> edges[i].start >> edges[i].finish >> edges[i].weight;
    }

    std::sort(edges.begin(), edges.end(), 
            [] (auto& lhs, auto& rhs) {
                return lhs.weight < rhs.weight;
            });

    std::cout << std::endl;
    int res = Kruscal(edges, m);
    std::cout << std::endl << res << std::endl;

    return 0;
}

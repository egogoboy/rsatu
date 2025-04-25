#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

const int INFINITE = std::numeric_limits<int>::max();
const int WHITE = -1;
const int BLACK = -2;

struct Edge {
    int to;
    int weight;
};

std::vector<std::vector<Edge>> graph;
std::vector<int> d, p, heap, inHeap;
int count = 0;

void swap(int i, int j);
void goDown(int i);
void goUp(int i);
void relax(int u, int v, int weight);

int getMinimal();
void dijkstra(int s);

void printPath(int v, int start, std::ostream& out);

int main() {
    std::ifstream fin("input.txt");
    if (!fin) {
        std::cerr << "File input.txt doesn't exist\n";
        return 1;
    }

    int n, m;
    char start;
    fin >> n >> m >> start;
    start -= 'a';

    graph.resize(n);
    int index = 0;

    for (int i = 0; i < m; ++i) {
        char u, v;
        int w;
        fin >> u >> v >> w;

        graph[u - 'a'].push_back({v - 'a', w});
        graph[v - 'a'].push_back({u - 'a', w});
    }
    fin.close();

    dijkstra(start);

    for (int i = 0; i < n; ++i) {
        if (i == start) {
            continue;
        }

        std::cout << static_cast<char>(start + 'a') << "-" << static_cast<char>(i + 'a') << "(";
        if (d[i] == INFINITE) {
            std::cout << "infinite): no path";
        } else {
            std::cout << d[i] << "): ";
            printPath(i, start, std::cout);
        }
        std::cout << std::endl;
    }

    return 0;
}

void swap(int i, int j) {
    std::swap(heap[i], heap[j]);

    inHeap[heap[i]] = i;
    inHeap[heap[j]] = j;
}

void goDown(int i) {
    while (2 * i <= count) {
        int minIdx = i;
        if (d[heap[i]] > d[heap[2 * i]]) {
            minIdx = 2 * i;
        }

        if (2 * i + 1 <= count && d[heap[minIdx]] > d[heap[2 * i + 1]]) {
            minIdx = 2 * i + 1;
        }
        if (minIdx == i) {
            return;
        }

        swap(i, minIdx);
        i = minIdx;
    }
}

void goUp(int i) {
    int j = i / 2;

    while (i > 1 && d[heap[i]] < d[heap[j]]) {
        swap(i, j);
        i = j;
        j = i / 2;
    }
}

void relax(int u, int v, int weight) {
    if (d[v] <= d[u] + weight) {
        return;
    }

    d[v] = d[u] + weight;
    p[v] = u;
    if (inHeap[v] == WHITE) {
        ++count;
        heap[count] = v;
        inHeap[v] = count;
    }
    goUp(inHeap[v]);
}

int getMinimal() {
    int result = heap[1];
    swap(1, count);
    inHeap[result] = BLACK;
    --count;
    goDown(1);
    return result;
}

void dijkstra(int s) {
    int n = graph.size();
    d.assign(n, INFINITE);
    p.assign(n, -1);

    inHeap.assign(n, WHITE);
    heap.resize(n + 1);

    count = 1;
    d[s] = 0;
    heap[1] = s;
    inHeap[s] = 1;

    while (count > 0) {
        int u = getMinimal();
        for (const Edge& edge : graph[u]) {
            relax(u, edge.to, edge.weight);
        }
    }
}

void printPath(int v, int start, std::ostream& out) {
    if (v == start) {
        out << static_cast<char>(start + 'a');
        return;
    }

    printPath(p[v], start, out);
    out << " " << static_cast<char>(v + 'a');
}

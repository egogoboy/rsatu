#pragma once

#include <vector>

class Heap {
public:
    Heap(size_t size = 0)
        : body_{std::vector<int>(size + 1)},
          size_{size} {}

    void Insert(int key);
    void Delete(int key);

    int GetMinimal();
    size_t Size();

    void Relax(int u, int v);
    
private:
    void GoDown(int i);
    void GoUp(int i);
    void Swap(int first, int second);

    std::vector<int> body_;
    std::vector<int> weight_;
    std::vector<int> inHeap_;
    size_t size_;
};

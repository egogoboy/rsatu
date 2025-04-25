#include "Heap.h"

void Heap::Insert(int key) {
    body_.push_back(key);
    ++size_;
}

size_t Heap::Size() {
    return size_;
}

void Heap::GoDown(int i) {
    while (i * 2 <= Size()) {
        int minIdx = i;
        if (weight_[body_[i]] > weight_[body_[2 * i]]) {
            minIdx = 2 * i;
        }
        if (2 * i < Size() && (weight_[body_[minIdx]] > weight_[body_[2 * i + 1]])) {
            minIdx = 2 * i + 1;
        }
        if (minIdx == i) {
            return;
        }
        Swap(i, minIdx);
        i = minIdx;
    }
}

void Heap::GoUp(int i) {
    int j = i / 2;
    while (i > 1) {
        if (weight_[body_[i]] >= weight_[body_[j]]) {
            return;
        }
        Swap(i, j);
        i = j;
        j = i / 2;
    }
}

void Heap::Swap(int first, int second) {
    std::swap(body_[first], body_[second]);

    inHeap_[body_[first]] = first;
    inHeap_[body_[second]] = second;
}

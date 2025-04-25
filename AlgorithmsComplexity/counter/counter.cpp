#include <iostream>

struct Node {
    int val;
    Node *prev;
    Node *next;
    Node(int val = 0, 
         Node *prev = nullptr, 
         Node *next = nullptr)
        : val{val}, 
          prev{prev}, 
          next{next} {}
};

int listSolution(int n, int k);
int recSolution(int n, int k);
int iterSolution(int n, int k);
int binSolution(int n);

int main() {
    std::cout << "Enter n and k: ";
    int n, k;
    std::cin >> n >> k;

    std::cout << "Circular list: " << listSolution(n, k) << std::endl;
    std::cout << "Recursion: " << recSolution(n, k) << std::endl;
    std::cout << "Iteration: " << iterSolution(n, k) << std::endl;
    std::cout << "Bit (k = 2): " << binSolution(n) << std::endl;

    return 0;
}

int listSolution(int n, int k) {
    if (n <= 0 || k <= 0) {
        return 0;
    }

    Node *list = new Node(1);
    list->prev = list;
    list->next = list;

    Node *cur = list;
    for (int i = 2; i <= n; ++i) {
        Node *newNode = new Node(i);

        newNode->prev = cur;
        newNode->next = list;
        cur->next = newNode;
        list->prev = newNode;

        cur = newNode;
    }

    cur = list;

    int count = 1;
    int i = 0;

    while (i < (n - 1) * k) {
        if (count != k) {
            ++count;
            ++i;
            cur = cur->next;
            continue;
        }
        count = 1;

        Node *prevNode = cur->prev;
        Node *nextNode = cur->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        Node *toDelete = cur;
        cur = nextNode;
        delete toDelete;
        ++i;
    }

    int result = cur->val;
    delete cur;

    return result;
}

int recSolution(int n, int k) {
    if (n <= 0 || k <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    } else {
        return (recSolution(n - 1, k) + k - 1) % n + 1;
    }
}

int iterSolution(int n, int k) {
    if (n <= 0 || k <= 0) {
        return 0;
    }

    int res = 0;

    for (int i = 1; i <= n; ++i) {
        res = (res + k) % i;
    }

    return res + 1;
}

int binSolution(int n) {
    if (n <= 0) {
        return 0;
    }
/*
    asm (
        "roll %%cl, %1\n\t"   // Rotate %1 left by value in CL register
        "movl %1, %0\n\t"     // Move rotated result into output
        : "=r" (n)       // output
        : "r" (value), "c" (count) // inputs: value to rotate, count in CL
        : "cc"                // clobbers: condition codes
    );
*/
    int bits = 0;
    int temp = n;

    while (temp > 0) {
        ++bits;
        temp >>= 1;
    }

    int firstBit = 1 << (bits - 1);
    int shifted = (n - firstBit) << 1;

    return shifted + 1;
}

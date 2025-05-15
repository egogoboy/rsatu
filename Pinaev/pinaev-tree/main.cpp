#include <iostream>
#include <iomanip>
#include "Node.h"

int getMin(Node* node);
bool isLeaf(Node* node);

Node* makeTree(int k, int h, int& count) {
    if (h == 1 || (h > 1 && k == 0)) {
        ++count;
        return new Node();
    }

    return new Node(makeTree(k - 1, h - 1, count), makeTree(k, h - 1, count));
}

Node* growTree(Node* node, int k, int max_k, int& count, int max_n) {
    if (k == max_k || count == max_n) {
        return node;
    }
    if (isLeaf(node)) {
        node->left = new Node();
        node->right = new Node();
        count++;
        return node;
    }
    
    node->left = growTree(node->left, k + 1, max_k, count, max_n);
    node->right = growTree(node->right, k, max_k, count, max_n);

    return node;
}

Node* fillTree(Node* node, int& depth) {
    if (node == nullptr) {
        return nullptr;
    }

    node->left = fillTree(node->left, depth);
    node->right = fillTree(node->right, depth);
    if (isLeaf(node)) {
        node->key = depth++;
    } else {
        node->key = getMin(node->right);
    }

    return node;
}

void printTree(Node* node, int width) {
    if (node == nullptr) {
        return;
    }
    printTree(node->right, width + 5);
    std::cout << std::string(width, ' ') << node->key << std::endl;
    printTree(node->left, width + 5);
}

Node* buildTree(int k, int n) {

    int count = 0;
    Node* head = makeTree(k, 1, count);
    while (count != n + 1) {
        head = growTree(head, 0, k, count, n + 1);
    }

    int depth = 0;
    head = fillTree(head, depth);

    printTree(head, 0);

    return head;
} 

int main() {
    int k, n;
    std::cin >> k >> n;
    
    Node* tree = buildTree(k, n);

    bool exit = false;

    while (!exit) {
        if (isLeaf(tree)) {
            std::cout << "Орех не разбился на ступеньке " << tree->key << std::endl;
            exit = true;
            break;
        }

        printTree(tree, 0);
        
        std::cout << "Обезьяна кинула орех на ступеньку " << tree->key << std::endl;
        std::cout << "Он разбился? y/n\n";
        char choise;
        std::cin >> choise;

        if (choise == 'y') {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }

    return 0;
}

bool isLeaf(Node* node) {
    return node->left == nullptr && node->right == nullptr;
}

int getMin(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    if (node->left == nullptr) {
        return node->key;
    }

    return getMin(node->left);
}

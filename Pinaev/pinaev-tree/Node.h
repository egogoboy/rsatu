#pragma once

class Node {
public:
    Node* left;
    Node* right;
    int key;

    Node(Node* left = nullptr,
         Node* right = nullptr,
         int key = 0)
        : left{left},
          right{right},
          key{key} {}
};

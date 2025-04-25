#pragma once

#include <cstdint>

class Node {
public:
    Node(int key = 0, 
         int val = 0, 
         Node* left = nullptr, 
         Node* right = nullptr): 
                            key{key}, 
                            val{val}, 
                            left{left}, 
                            right{right} {}

    int key;
    int val;
    int height;
    Node* left;
    Node* right;

};

#pragma once

class TreeNode {
public:
    TreeNode(int x = 0, 
             TreeNode* left = nullptr, 
             TreeNode* right = nullptr, 
             int bal = 0): key{x},
                              left{left},
                              right{right},
                              balance{bal} {}

    int key;
    int balance;
    TreeNode* left;
    TreeNode* right;

};

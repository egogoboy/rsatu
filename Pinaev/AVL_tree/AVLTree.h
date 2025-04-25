#pragma once

#include "TreeNode.h"
#include <fstream>
#include <stdexcept>

class AVLTree {
public:
    AVLTree(): head_{nullptr} {};

    int getHeight(TreeNode* node) const;
    void insert(int key);

    void printSortedBST(TreeNode* node) const;
    void printRealBST(TreeNode* node) const;

    void BuildWithN(int n) {
        for (int i = 1; i <= n; ++i) {
            insert(i);
        }
    }

    void BuildFromFile(const std::string& s) {
        std::ifstream fin(s);

        if (!fin.is_open()) {
            throw std::runtime_error("File does not exist");
        }

        while (!fin.eof()) {
            int x;
            fin >> x;
            insert(x);
        }
    }

    void WriteTree(const std::string& s) {
        std::ofstream fout(s);
    }

    void Print();

    
private:
    TreeNode* head_;

    void PrintTree(TreeNode* node, int deep);
    //void updateHeight(TreeNode*& node);
    int getBalance(TreeNode* node) const;

    TreeNode* rightRotate(TreeNode* node);
    TreeNode* leftRotate(TreeNode* node);

    TreeNode* balance(TreeNode* node, bool& heightIncreased);
    TreeNode* insert(TreeNode* node, int key, bool& heightIncreased);
};

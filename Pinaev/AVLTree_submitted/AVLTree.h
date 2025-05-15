#pragma once

#include "TreeNode.h"

#include <fstream>
#include <stdexcept>

class AVLTree {
public:
    AVLTree(): head_{nullptr} {};
    AVLTree(TreeNode* root): head_{root} {}
    ~AVLTree();

    void save(const std::string& filename);

    void load(const std::string& filename);
    void buildWithN(int n);

    TreeNode* getRoot() const;
    void setRoot(TreeNode* root);

    bool find(int data);
    void insert(int data);

    void print() const;
    void display() const;
    int depth() const;
    int countTreeNodes() const;

private:
    TreeNode* head_;

    TreeNode* load(std::ifstream& in);
    void save(TreeNode* root, std::ofstream& out);

    void updateBalance(TreeNode* node);

    void destroy(TreeNode* root);
    void insert(TreeNode*& node, int data, bool& h);
    bool find(TreeNode* node, int data);

    void balanceL(TreeNode*& node, bool& h);
    void balanceR(TreeNode*& node, bool& h);

    void inOrder(TreeNode* node) const;
    void treeLike(TreeNode* node, int depth) const;
    int depth(TreeNode* node) const;

    int getDepth(TreeNode* node) const;
    int countNodes(TreeNode* node) const;
};

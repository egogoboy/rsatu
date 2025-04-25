#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Node.h"

class Tree {
public:
    Tree(int n): count_of_nodes{n},
                 head_{MakeTree(n, 0)} {}

    void Print();
    void PrintStatistics();

    double GetAverageInternalPathLength() const;
    double GetAverageExternalPathLength() const;
    size_t GetNodesCount() const;
    size_t GetTreeHeight() const;

    void WriteTree(const std::string& filename) const;
    void BuildFromFile(const std::string& filename);
    void BuildWithN(int n);

    void Insert(int key);
    void Delete(int key);
    std::string Find(int key);

    bool CheckKeys();

    std::string GetCopyright();

private:

    Node* MakeTree(std::ifstream& fin);
    Node* MakeTree(int n, int left_n);

    double GetAverageInternalPathLength(Node* root) const;
    double GetAverageExternalPathLength(Node* root) const;
    int GetDepth(Node* root);
    int GetHeight(Node* node);

    void PrintTree(Node* node, int deep);
    std::vector<int> GetPreorder(Node* node, std::vector<int> vec) const;
    std::vector<int> GetInorder(Node* node, std::vector<int> vec) const;

    Node* Insert(int key, Node* root);
    Node* Delete(int key, Node* root);
    std::string Find(int key, Node* root);
    
    Node* GetMinNode(Node* root);//bibibi

    Node* head_;
    int count_of_nodes;
};

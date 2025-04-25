#include <iostream>
#include <algorithm>
#include "AVLTree.h"
#include "TreeNode.h"

/*
void AVLTree::updateBalance(TreeNode*& node) {
    node->height = std::max(getHeight(node->left), getHeight(node->right));
}
*/

void AVLTree::Print() {
    PrintTree(head_, 0);
}

void AVLTree::PrintTree(TreeNode* node, int deep) {
    if (node != nullptr) {
        PrintTree(node->right, deep + 4);
        std::cout << std::string(deep, ' ') << node->key << "-" << node->balance << std::endl;
        PrintTree(node->left, deep + 4);
    }
}


int AVLTree::getBalance(TreeNode* node) const {
    return (node == nullptr ? 0 : node->balance);
}

TreeNode* AVLTree::rightRotate(TreeNode* node) {
    TreeNode* newRoot = node->left;

    if (getBalance(newRoot) == 0) {
        node->balance = -1;
    } else {
        node->balance = 0;
    }

    newRoot->balance += 1;
    node->left = newRoot->right;
    newRoot->right = node;
 
    //updateHeight(node);
    //updateHeight(newRoot);

    std::cout << "right rotate\n";
    return newRoot;
}

TreeNode* AVLTree::leftRotate(TreeNode* node) {
    TreeNode* newRoot = node->right;

    if (getBalance(newRoot) == 0) {
        node->balance = 1;
    } else {
        node->balance = 0;
    }

    newRoot->balance -= 1;
    node->right = newRoot->left;
    newRoot->left = node;

    //updateHeight(node);
    //updateHeight(newRoot);

    std::cout << "left rotate\n";
    
    return newRoot;
}

TreeNode* AVLTree::balance(TreeNode* node, bool& heightIncreased) {
    //updateHeight(node);   

    switch(getBalance(node)) {
        case 2:
            if (getBalance(node->right) < 0) {
                node->right = rightRotate(node->right);
            }
            node = leftRotate(node);
            heightIncreased = false;
            break;

        case -2:
            if (getBalance(node->left) > 0) {
                node->left = leftRotate(node->left);
            }
            node = rightRotate(node);
            heightIncreased = false;
            break;
    }

    return node;
}

void AVLTree::insert(int key) {
    bool heightIncreased = false;
    head_ = insert(head_, key, heightIncreased);
}

TreeNode* AVLTree::insert(TreeNode* node, int key, bool& heightIncreased) {
    if (node == nullptr) {
        heightIncreased = true;
        return new TreeNode(key);
    }

    if (key >= node->key) {
        node->right = insert(node->right, key, heightIncreased);
        if (heightIncreased) {
            if (node->balance == 1) {
                node->balance = 0;
                heightIncreased = false;
            } else if (node->balance == 0) {
                node->balance = 1;
            } else {
                TreeNode *temp = node->right;
                if (temp->balance == 1) {
                    node->right = temp->left;
                    temp->left = node;
                    node->balance = 0;
                    node = temp;
                } else {
                    TreeNode *temp2 = temp->left;
                    temp->left = temp2->right;
                    temp2->right = temp;
                    node->right = temp2->left;
                    temp2->left = node;
                    if (temp2->balance == 1) {
                        node->balance = -1;
                    } else {
                        node->balance = 0;
                    }
                    if (temp2->balance == -1) {
                        temp->balance = 1;
                    } else {
                        temp->balance = 0;
                    }
                }
                node->balance = 0;
                heightIncreased = false;
            }
        }
    }
    else {
        node->left = insert(node->left, key, heightIncreased);
        if (heightIncreased) {
            if (node->balance == 1) {
                node->balance = 0;
                heightIncreased = false;
            } else if (node->balance == 0) {
                node->balance = -1;
            } else {
                TreeNode *temp = node->left;
                if (temp->balance == -1) {
                    node->left = temp->right;
                    temp->right = node;
                    node->balance = 0;
                    node = temp;
                } else {
                    TreeNode *temp2 = temp->right;
                    temp->right = temp2->left;
                    temp2->left = temp;
                    node->left = temp2->right;
                    temp2->right = node;
                    if (temp2->balance == -1) {
                        node->balance = 1;
                    } else {
                        node->balance = 0;
                    }
                    if (temp2->balance == 1) {
                        temp->balance = -1;
                    } else {
                        temp->balance = 0;
                    }
                }
                node->balance = 0;
                heightIncreased = false;
            }
        }
    }

    return node;
}

void AVLTree::LL(Node*& node, Node*& p1, bool& h) {
    std::cout << "LL rotation\n";
    node->left = p1->right;
    p1->right = node;
    
    // Обновление балансов
    node->balance = (p1->balance == -1) ? 0 : -1;
    p1->balance = (p1->balance == 0) ? 1 : 0;
    
    node = p1;
    h = false;
}

void AVLTree::LR(Node*& node, Node*& p1, Node*& p2, bool& h) {
    std::cout << "LR rotation\n";
    p2 = p1->right;
    p1->right = p2->left;
    p2->left = p1;
    node->left = p2->right;
    p2->right = node;

    // Обновление балансов
    if (p2->balance == -1) {
        node->balance = 1;
        p1->balance = 0;
    } else if (p2->balance == 0) {
        node->balance = 0;
        p1->balance = 0;
    } else {
        node->balance = 0;
        p1->balance = -1;
    }
    
    p2->balance = 0;
    node = p2;
    h = false;
}

void AVLTree::RR(Node*& node, Node*& p1, bool& h) {
    std::cout << "RR rotation\n";
    node->right = p1->left;
    p1->left = node;
    
    // Обновление балансов
    node->balance = (p1->balance == 1) ? 0 : 1;
    p1->balance = (p1->balance == 0) ? -1 : 0;
    
    node = p1;
    h = false;
}

void AVLTree::RL(Node*& node, Node*& p1, Node*& p2, bool& h) {
    std::cout << "RL rotation\n";
    p2 = p1->left;
    p1->left = p2->right;
    p2->right = p1;
    node->right = p2->left;
    p2->left = node;

    // Обновление балансов
    if (p2->balance == 1) {
        node->balance = -1;
        p1->balance = 0;
    } else if (p2->balance == 0) {
        node->balance = 0;
        p1->balance = 0;
    } else {
        node->balance = 0;
        p1->balance = 1;
    }
    
    p2->balance = 0;
    node = p2;
    h = false;
}

bool AVLTree::insert(TreeNode*& node, int data, bool& h) {
    if (node == nullptr) {
        node = new TreeNode(data);
        h = true;
        return false;
    }

    bool found;
    if (data < node->data) {
        found = find(node->left, data, h);
        if (h) {
            node->balance--;
            if (node->balance == -2) {
                TreeNode* p1 = node->left;
                if (p1->balance == -1) {
                    LL(node, p1, h);
                } else {
                    TreeNode* p2;
                    LR(node, p1, p2, h);
                }
            } else if (node->balance == 0) {
                h = false;
            }
        }
    } 
    else if (data > node->data) {
        found = find(node->right, data, h);
        if (h) {
            node->balance++;
            if (node->balance == 2) {
                TreeNode* p1 = node->right;
                if (p1->balance == 1) {
                    RR(node, p1, h);
                } else {
                    TreeNode* p2;
                    RL(node, p1, p2, h);
                }
            } else if (node->balance == 0) {
                h = false;
            }
        }
    } 
    else {
        h = false;
        return true;
    }

    return found;
}

void AVLTree::printSortedBST(TreeNode* node) const {
    if (node == nullptr)
        return;

    printSortedBST(node->left);
    std::cout << node->key << " ";
    printSortedBST(node->right);
}

void AVLTree::printRealBST(TreeNode* node) const {
    if (node == nullptr) {
        std::cout << "null ";
        return;
    }
    std::cout << node->key << " ";
    printRealBST(node->left);
    printRealBST(node->right);
}

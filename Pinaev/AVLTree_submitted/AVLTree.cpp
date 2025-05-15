#include "AVLTree.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

AVLTree::~AVLTree() {
    destroy(head_);
}

void AVLTree::save(const std::string& filename) {
    std::ofstream fout(filename);

    save(head_, fout);
}

void AVLTree::save(TreeNode* root, std::ofstream& out) {
    if (root == nullptr) {
        out << "NULL ";
        return;
    }
    out << root->key << " ";
    save(root->left, out);
    save(root->right, out);
}

void AVLTree::load(const std::string& filename) {
    std::ifstream fin(filename);

    if (!fin.is_open()) {
        throw std::runtime_error("Error while openning file " + filename);
    }

    head_ = load(fin);
}

void AVLTree::buildWithN(int n) {
    destroy(head_);
    head_ = nullptr;
    
    for (int i = 1; i <= n; ++i) {
        insert(i);
    }

    return;
}

TreeNode* AVLTree::load(std::ifstream& in) {
    std::string token;
    in >> token;
    if (token == "NULL") {
        return nullptr;
    }
    TreeNode* root = new TreeNode(std::stoi(token));
    root->left = load(in);
    root->right = load(in);
    updateBalance(root);
    return root;
}

TreeNode* AVLTree::getRoot() const {
    return head_;
}

void AVLTree::setRoot(TreeNode* root) {
    if (head_ != nullptr) {
        destroy(head_);
    }
    head_ = root;
}

void AVLTree::insert(int data) {
    bool h = false; 
    insert(head_, data, h);
}

bool AVLTree::find(int data) {
    return find(head_, data);
}

bool AVLTree::find(TreeNode* node, int data) {
    if (node == nullptr) {
        return false;
    }

    if (data == node->key) {
        return true;
    }

    return find(node->left, data) || find(node->right, data);
}

void AVLTree::print() const {
    treeLike(head_, 0);
    std::cout << std::endl;
}

void AVLTree::display() const {
    treeLike(head_, 0);
}

int AVLTree::depth() const {
    return depth(head_);
}

int AVLTree::countTreeNodes() const {
    return countNodes(head_);
}

void AVLTree::destroy(TreeNode* root) {
    if (root != nullptr) {
        destroy(root->left);
        destroy(root->right);
        delete root;
    }
}

int AVLTree::getDepth(TreeNode* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + std::max(getDepth(node->left), getDepth(node->right));
}

void AVLTree::updateBalance(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    node->balance = getDepth(node->right) - getDepth(node->left);
}


void AVLTree::balanceL(TreeNode*& node, bool& h) {
    TreeNode *p1, *p2;
    if (node->balance == -1) {
        node->balance = 0;
    } else if (node->balance == 0) {
        node->balance = 1;
        h = false;
    } else {
        std::cout << "RR rotate\n";
        p1 = node->right;
        if (p1->balance >= 0) {
            node->right = p1->left;
            p1->left = node;
            if (p1->balance == 0) {
                node->balance = 1;
                p1->balance = -1;
                h = false;
            } else {
                node->balance = 0;
                p1->balance = 0;
            }
            node = p1;
        } else {
            std::cout << "RL rotate\n";
            p2 = p1->left;
            p1->left = p2->right;
            p2->right = p1;
            node->right = p2->left;
            p2->left = node;
            if (p2->balance == 1) {
                node->balance = -1; 
            } else {
                node->balance = 0;
            }
            if (p2->balance == -1) { 
                p1->balance = 1; 
            } else {
                p1->balance = 0;
            }
            node = p2;
            node->balance = 0;
        }
    }
}

void AVLTree::balanceR(TreeNode*& node, bool& h) {
    TreeNode *p1, *p2;
    if (node->balance == 1) {
        node->balance = 0;
    } else if (node->balance == 0) {
        node->balance = -1;
        h = false;
    } else {
        p1 = node->left;
        if (p1->balance <= 0) {
            std::cout << "LL rotate\n";
            node->left = p1->right;
            p1->right = node;
            if (p1->balance == 0) {
                node->balance = -1;
                p1->balance = 1;
                h = false;
            } else {
                node->balance = 0;
                p1->balance = 0;
            }
            node = p1;
        } else {
            std::cout << "LR rotate\n";
            p2 = p1->right;
            p1->right = p2->left;
            p2->left = p1;
            node->left = p2->right;
            p2->right = node;
            if (p2->balance == -1) {
                node->balance = 1;
            } else {
                node->balance = 0;
            }
            if (p2->balance == 1) {
                p1->balance = -1;
            } else {
                p1->balance = 0;
            }

            node = p2;
            node->balance = 0;
        }
    }
}

void AVLTree::insert(TreeNode*& node, int data, bool& h) {
    TreeNode *p1, *p2;
    if (node == nullptr) {
        node = new TreeNode(data);
        h = true;
    } else if (data < node->key) {
        insert(node->left, data, h);
        if (h) {
            if (node->balance == 1) {
                node->balance = 0;
                h = false;
            } else if (node->balance == 0) {
                node->balance = -1;
            } else {
                // Left rotates
                p1 = node->left;
                if (p1->balance == -1) {
                    // LL rotate
                    std::cout << "LL rotate\n";
                    node->left = p1->right;
                    p1->right = node;
                    node->balance = 0;
                    node = p1;
                } else {
                    // LR rotate
                    std::cout << "LR rotate\n";
                    p2 = p1->right;
                    p1->right = p2->left;
                    p2->left = p1;
                    node->left = p2->right;
                    p2->right = node;

                    node->balance = (p2->balance == -1) ? 1 : 0;
                    p1->balance = (p2->balance == 1) ? -1 : 0;
                    node = p2;
                }
                node->balance = 0;
                h = false;
            }
        }
    } else if (data > node->key) {
        insert(node->right, data, h);
        if (h) {
            if (node->balance == -1) {
                node->balance = 0;
                h = false;
            } else if (node->balance == 0) {
                node->balance = 1;
            } else {
                // Right rotates
                p1 = node->right;
                if (p1->balance == 1) {
                    // RR rotate
                    std::cout << "RR rotate\n";
                    node->right = p1->left;
                    p1->left = node;
                    node->balance = 0;
                    node = p1;
                } else {
                    // RL rotate
                    std::cout << "RL rotate\n";
                    p2 = p1->left;
                    p1->left = p2->right;
                    p2->right = p1;
                    node->right = p2->left;
                    p2->left = node;

                    node->balance = (p2->balance == 1) ? -1 : 0;
                    p1->balance = (p2->balance == -1) ? 1 : 0;

                    node = p2;
                }
                node->balance = 0;
                h = false;
            }
        }
    } else {
        h = false;
    }
}

void AVLTree::inOrder(TreeNode* node) const {
    if (node) {
        inOrder(node->left);
        std::cout << node->key << " ";
        inOrder(node->right);
    }
}

void AVLTree::treeLike(TreeNode* node, int depth) const {
    if (node) {
        treeLike(node->right, depth + 2);
        std::cout << std::string(depth * 4, ' ') << node->key << "(" << node->balance << ")\n";
        treeLike(node->left, depth + 2);
    }
}

int AVLTree::depth(TreeNode* node) const {
    if (!node) {
        return 0;
    }
    return 1 + std::max(depth(node->left), depth(node->right));
}

int AVLTree::countNodes(TreeNode* node) const {
    if (!node) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}

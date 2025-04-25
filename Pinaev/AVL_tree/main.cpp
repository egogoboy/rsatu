#include <iostream>
#include "AVLTree.h"

int main() {
    AVLTree tree;
    bool exit = false;
    while (!exit) {
        std::cout << "Select option:\n"
            << "1 - Make tree with N\n"
            << "2 - Make tree from file\n"
            << "3 - Write tree to file\n"
            << "4 - Add a key\n"
            << "5 - Print tree\n"
            << "6 - Exit\n";

        std::cout << ">>";
        int choise;
        std::cin >> choise;

        std::string filename;

        switch (choise) {
            case 1:
                std::cout << "Enter n: ";
                int n;
                std::cin >> n;
                tree.BuildWithN(n);
                break;
            case 2:
                std::cout << "Enter filename: ";
                std::cin >> filename;
                tree.BuildFromFile(filename);
                break;
            case 3:
                std::cout << "Enter filename: ";
                std::cin >> filename;
                tree.WriteTree(filename);
                break;
            case 4: {
                        std::cout << "Enter the key: ";
                        int key;
                        std::cin >> key;
                        tree.insert(key);
                        break;
                    }
            case 5:
                    tree.Print();
                    break;
            case 6:
                    exit = true;
                    break;
            default:
                    std::cout << "Unknown operation\n";
                    break;
        }
    }

    return 0;
}


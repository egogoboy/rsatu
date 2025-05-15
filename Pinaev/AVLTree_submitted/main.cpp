#include <iostream>
#include <fstream>
#include <stdexcept>
#include "AVLTree.h"

int main() {
    AVLTree tree;
    bool exit = false;
    while (!exit) {
        std::cout << "Select option:\n"
                  << "1 - build tree with N\n"
                  << "2 - build tree from file\n"
                  << "3 - save to the file\n"
                  << "4 - find element\n"
                  << "5 - insert element\n"
                  << "6 - exit\n"
                  << ">> ";
        
        char choise;
        std::cin >> choise;

        switch (choise) {
            case '1': {
                std::cout << "Enter n: ";
                int n;
                std::cin >> n;

                tree.buildWithN(n);
                tree.print();
                std::cout << "Tree has been built with n = " << n << std::endl;
                break;
            }
            case '2': {
                std::cout << "Enter filename: ";
                std::string filename;
                std::cin >> filename;

                try {
                    tree.load(filename);
                    tree.print();
                    std::cout << "Tree has been loaded from file\n";
                } catch (const std::runtime_error& err) {
                    std::cerr << err.what() << std::endl;
                }

                break;
            }
            case '3': {
                std::cout << "Enter filename: ";
                std::string filename;
                std::cin >> filename;
                
                tree.save(filename);

                std::cout << "Tree has been saved to the file " << filename << std::endl;
                break;
            }
            case '4': {
                std::cout << "Enter value: ";
                int n;
                std::cin >> n;

                if (tree.find(n)) {
                    std::cout << "Value found\n";
                } else {
                    std::cout << "There is no same element\n";
                }

                break;
            }
            case '5': {
                std::cout << "Enter value: ";
                int n;
                std::cin >> n;
                
                tree.insert(n);
                tree.print();
                std::cout << "Inserted\n";

                break;
            }
            case '6': {
                exit = true;
                break;
            }
            default:
                std::cout << "Unknown command\n";
        }


    }

    return 0;
}


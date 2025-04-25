#include <iostream>
#include "Tree.h"

int main() {
    bool exit = false;
    Tree tree(0);
    while (!exit) {
        std::cout << "Select option:\n"
                  << "1 - Make tree with N\n"
                  << "2 - Make tree from file\n"
                  << "3 - Write tree to file\n"
                  << "4 - Add a key\n"
                  << "5 - Delete a key\n"
                  << "6 - Find a key\n"
                  << "7 - Print statistic\n"
                  << "8 - Print tree\n"
                  << "9 - Exit\n";
        
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
                tree.Insert(key);
                break;
            }
            case 5: {
                std::cout << "Enter the key to delete: ";
                int key;
                std::cin >> key;
                tree.Delete(key);
                break;
            }
            case 6: {
                std::cout << "Enter the key to find: ";
                int key;
                std::cin >> key;
                std::cout << "Path to key: " << tree.Find(key) << std::endl;
                break;
            }
            case 7:
                std::cout << "Statistic:\n";
                tree.PrintStatistics();
            break;
            case 8:
                tree.Print();
            break;
            case 9:
                exit = true;
            break;
            default:
                std::cout << "Unknown operation\n";
            break;
        }
    }

    std::cout << tree.GetCopyright();
    return 0;
}

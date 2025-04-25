#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <utility>
#include <vector>

class Dictionary {

    public:
        Dictionary(std::string filename) {
            processText_(filename);
        }

        ~Dictionary() {
            std::ofstream fout(DEFAULT_OUTPUT_FILENAME);

            for (auto x : dictionary_)
                fout << x.first << ": " << x.second << "\n";

            fout.close();
        }

        void printDictionaryByAlphabet() {
            for (auto x : dictionary_)
                std::cout << x.first << ": " << x.second << "\n";
        }

        void printDictionaryByFrequency() {
            std::vector<std::pair<int, std::string>> out;

            for (auto x : dictionary_) {
                out.push_back({ x.second, x.first });
            }

            std::sort(out.begin(), out.end(), [] (auto& lhs, auto& rhs) {return lhs.first > rhs.first; });

            for (auto x : out)
                std::cout << x.first << ": " << x.second << "\n";
        }

        void printTheMostFrequentWord() {
            int max = dictionary_.begin()->second;
            
            for (auto x : dictionary_) {
                if (x.second == max)
                    std::cout << x.first << ";\n";
                else
                    break;
            }
        }

        void printTheMostUnfrequentWord() {
            int min = dictionary_.begin()->second;

            std::vector<std::string> minWords;
            for (auto x : dictionary_) {
                if (x.second < min) {
                    minWords.clear();
                    min = x.second;
                }
                minWords.push_back(x.first);
            }
            
            std::cout << "Частота: " << min << std::endl;
            for (auto x : minWords)
                std::cout << x << std::endl;
        }

        void printWordsOnLetter(char c) {
            for (auto x : dictionary_) {
                if (x.first[0] == c) {
                    std::cout << x.first << ": " << x.second << "\n";
                }
            }
        }

    private:
        void processText_(std::string filename) {
            std::ifstream fin(filename);

            std::string word = "";
            char c;
            while (!fin.eof()) {
                fin.get(c);
                c = std::tolower(c);
  
                if (alphabet.count(c)) {
                    word += c;
                }
                else if (!word.empty()){
                    dictionary_[word]++;
                    word.clear();
                }
            }

            if (word != "")
                dictionary_[word]++;

            fin.close();
        }
        
        std::set<char> alphabet = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        std::map<std::string, int> dictionary_;
        const std::string DEFAULT_OUTPUT_FILENAME = "output.txt";

};

#endif

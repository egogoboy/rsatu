#pragma once

#include <set>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include "CustomExceptionHandler.h"

class Anagram {
    
    public:
        Anagram(const std::string& inputFile);

        bool isAnagram(const std::pair<std::string, std::string>& words);
 
        void printAllAnagrams();
        void printWordsWithoutAnagrams();

        std::vector<std::string> findAnagrams(const std::string& word);

    private:
        void processInputData(const std::string& inputFile);
        void addWordToDictionary(std::string& word);

        bool checkFrequency(const std::map<char, int>& m);

        std::map<std::string, std::set<std::string>> dictionary_;
        std::set<std::string> words_;
        static inline const std::set<char> alphabet_ = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
};

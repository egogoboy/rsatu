#include "Anagram.h"
#include "CustomExceptionHandler.h"
#include <cctype>

Anagram::Anagram(const std::string& inputFile) {
    processInputData(inputFile);
}

void Anagram::printAllAnagrams() {
    int number = 0;
    for (const auto& anagrams : dictionary_) {
        if (anagrams.second.size() > 1) {
            number++;
            std::cout << number << ". ";
            
            for (const std::string& word : anagrams.second) {
                std::cout << word << " ";
            }
            std::cout << std::endl;
        }
    }
}

void Anagram::printWordsWithoutAnagrams() {
    int number = 0;
    for (const auto& anagrams : dictionary_) {
        if (anagrams.second.size() == 1) {
            number++;
            std::cout << number << ". " << *anagrams.second.begin() << std::endl;
        }
    }
}

std::vector<std::string> Anagram::findAnagrams(const std::string& word) {
    std::string sortedWord = word;
    std::sort(sortedWord.begin(), sortedWord.end());

    std::vector<std::string> res(0);
    auto anagrams = dictionary_.find(sortedWord);
    if (anagrams != dictionary_.end()) {
        for (const auto& word : anagrams->second) {
            res.push_back(word);
        }
    }
    
    return res;
}

void Anagram::processInputData(const std::string& inputFile) {
    std::ifstream fin(inputFile);

    if (!fin.is_open())
        throw FileOpeningException("File " + inputFile + " does not exist");

    std::string word = "";
    char c;
    while (!fin.eof()) {
        fin.get(c);
        c = std::tolower(c); 

        if (alphabet_.count(c)) {
            word += c;
        }
        else if (!word.empty()){
            addWordToDictionary(word);
        }
    }
    if (!word.empty()) {
        addWordToDictionary(word);
    }

    fin.close();
}

void Anagram::addWordToDictionary(std::string& word) {

    std::string sortedWord = word;
    std::sort(sortedWord.begin(), sortedWord.end());

    words_.insert(word);
    dictionary_[sortedWord].insert(word);

    word.clear();
}

bool Anagram::isAnagram(const std::pair<std::string, std::string>& words) {
    if (words.first.size() != words.second.size()) {
        return false;
    }

    std::map<char, int> lettersFrequency;

    for (auto x: words.first) {
        lettersFrequency[x]++;
    }

    for (auto x : words.second) {
        lettersFrequency[x]--;
    }

    return checkFrequency(lettersFrequency);
    
}

bool Anagram::checkFrequency(const std::map<char, int>& m) {

    for (auto x : m) {
        if (x.second != 0)
            return false;
    }

    return true;

}

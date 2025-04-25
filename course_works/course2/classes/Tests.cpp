#include "Tests.h"

void Tests::generateTestText(int textLength, const std::string& outputFileName) {

    std::string text;
    for (size_t i = 0; i < textLength; ++i) {
        const std::string& word = randomIndex(4) == 0 ? uniqueWords[randomIndex(uniqueWords.size())] : defaultWordList[randomIndex(defaultWordList.size())];
        if (std::find(uniqueWords.begin(), uniqueWords.end(), word) != uniqueWords.end()) {
            // Add a unique word without anagrams
            text += word + " ";
        } else {
            if (randomIndex(2)) {
                // Add an anagram of the word
                std::string anagram = word;
                std::random_device rd;
                std::mt19937 g(rd());
                std::shuffle(anagram.begin(), anagram.end(), g);
                if (anagram != word) {
                    text += anagram + " ";
                } else {
                    text += word + " ";
                }
            } else {
                // Add the original word
                text += word + " ";
            }
        }
    }

    std::ofstream fout(outputFileName);
    fout << text;
    fout.close();
}

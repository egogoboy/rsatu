#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

class Tests {
public:

    static void generateTestText(int textLength, const std::string& outputFileName);

private:
    const static inline std::vector<std::string> defaultWordList = {
        "listen", "silent", "part", "trap", "stop", "pots", "earth", "heart",
        "save", "vase", "note", "tone", "stare", "rates", "stone", "tones",
        "angel", "glean", "brag", "grab", "dusty", "study", "evil", "vile",
        "god", "dog", "loop", "pool", "night", "thing", "scar", "cars",
        "elbow", "below", "stressed", "desserts", "teacher", "cheater",
        "cinema", "iceman", "pat", "tap", "rat", "tar"
    };
    const static inline std::vector<std::string> uniqueWords = {
        "unique", "simple", "complex", "algorithm", "example", "coding", "programming"
    };

    static inline size_t randomIndex(size_t max) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<size_t> dist(0, max - 1);
        return dist(gen);
    }
};

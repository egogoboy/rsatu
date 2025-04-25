#include <map>
#include <string>
#include <cmath>
class inf {

    public:
        static double calcInf(std::string text) {
            std::map<char, int> letters;
            for (char c : text) {
                letters[c]++;
            }

            std::map<char, double> infOfLetters;
            for (auto element : letters) {
                infOfLetters[element.first] = (double)element.second / text.size();
            }

            double informative = 0;
            for (auto i : infOfLetters) {
                informative += i.second * std::log2(i.second);
            }
            informative *= -1;
            return informative;
        }
};

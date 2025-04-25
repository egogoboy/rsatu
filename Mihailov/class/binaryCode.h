#include <vector>
#include <algorithm>

class binaryCode {
    
    public:
     
        static std::vector<int> binCode(int x) {
            std::vector<int> result;
            int temp_x = x;
            if (temp_x < 0)
                temp_x *= -1;
            while (temp_x != 0) {
                result.push_back(temp_x % 2);
                temp_x /= 2;
            }
            result.push_back(0);
            result.push_back(x < 0 ? 1 : 0);
            std::reverse(result.begin(), result.end());
            return result;
        }

        static std::vector<int> reverseCode(int x) {
            std::vector<int> result = binCode(x);
            if (x < 0)
                for (int i = 1; i < result.size(); i++) {
                    if (result[i] == 1)
                        result[i] = 0;
                    else 
                        result[i] = 1;
                }
            return result;
        }

        static std::vector<int> additionalCode(int x) {
            std::vector<int> result = reverseCode(x);
            if (x < 0) {
                bool carry = true;
                for (int i = result.size() - 1; i > 0; i--) {
                    if (result[i] == 1 && carry) {
                        result[i] = 0;
                    }
                    else if (carry) {
                        result[i] = 1;
                        carry = false;
                    }
                }
            }
            return result;
        } 

        static std::vector<int> modAdditionalCode(int x) {
            std::vector<int> result = additionalCode(x);
            std::reverse(result.begin(), result.end());
            result.push_back(result[result.size() - 1]);
            std::reverse(result.begin(), result.end());
            return result;
        }

};

#include <iostream>
#include <vector>

void shellSort(std::vector<int> m);

int main() {
    


    return 0;
}

void shellSort(std::vector<int> m) {
    
    if (m.size() > 1) {
        int d[] = {1750, 701, 301, 132, 57, 23, 10, 4, 1};
        int cur_d = 0;
        while (d[cur_d] > m.size()) {
            cur_d--;
        }

        for (int i = 0; i < d[cur_d]; i++) {
            std::vector<int> temp_m;
            for (int j = i; j < m.size(); j += d[cur_d]) {
                temp_m.push_back(m[j]);
            }
            shellSort(temp_m);
        }
        
    }
}

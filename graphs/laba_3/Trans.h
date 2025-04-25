#pragma once

#include <iostream>
#include <fstream>

class Trans {
public:

    static void TranslateInput(const std::string& filename) {
        int n, m;
        std::cin >> n >> m;
        std::ofstream fout(filename);
        fout << n << " " << m << std::endl;

        for (int i = 0; i < m; ++i) {
            char s, f;
            int w;
            std::cin >> s >> f >> w;
            fout << s - 'a' << " " << f - 'a' << " " << w << std::endl;
        }
    }

};

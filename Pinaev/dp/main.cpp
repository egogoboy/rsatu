#include <algorithm>
#include <iostream>
#include <vector>

void fst();
void snd();
void printMatrix(const std::vector<std::vector<int>>& dp, const std::vector<int>& seq1, const std::vector<int>& seq2);

int main() {

    int choice;
    std::cout << "Task: ";
    std::cin >> choice;
    switch (choice) {
        case 1:
            fst();
            break;
        case 2:
            snd();
            break;
        default:
            break;
    } 

    return 0;    
}

void fst() {
    int n;
    std::cin >> n;

    std::vector<int> seq(n);
    std::vector<int> dp(n, 1);
    std::vector<int> prev(n, -1);

    for (int& x : seq) {
        std::cin >> x;
    }

    int max_len = 0;
    int last = -1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (seq[i] >= seq[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            last = i;
        }
    }

    for (int val : dp) {
        std::cout << val << "\t";
    }
    std::cout << std::endl;

    for (int val : prev) {
        std::cout << val << "\t";
    }
    std::cout << std::endl;

    std::vector<int> sub;

    while (last != -1) {
        sub.push_back(seq[last]);
        last = prev[last];
    }

    std::reverse(sub.begin(), sub.end());
    std::cout << "Subsequence: ";
    for (int val : sub) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void snd() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    std::vector<int> seq1(n);
    std::vector<int> seq2(m);

    for (int& x : seq1) {
        std::cin >> x;
    }

    for (int& x : seq2) {
        std::cin >> x;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++ j) {
            if (seq2[i - 1] == seq1[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    std::vector<int> path;

    int i = m;
    int j = n;
    while (i > 0 && j > 0) {
        if (seq2[i - 1] == seq1[j - 1]) {
            path.push_back(seq2[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    printMatrix(dp, seq1, seq2);

    std::reverse(path.begin(), path.end());
    std::cout << "Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i] << " ";
    }
    std::cout << std::endl;
}

void printMatrix(const std::vector<std::vector<int>>& dp, const std::vector<int>& seq1, const std::vector<int>& seq2) {
    std::cout << "\t\t";
    for (int x : seq1) {
        std::cout << x << "\t";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < dp.size(); ++i) {
        if (!i) {
            std::cout << "\t";
        }
        else {
            std::cout << seq2[i - 1] << "\t";
        }
        for (size_t j = 0; j < dp[i].size(); ++j) {
            std::cout << dp[i][j] << "\t"; 
        }
        std::cout << std::endl;
    }
}

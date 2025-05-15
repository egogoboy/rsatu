#include <fstream>
#include <iostream>
#include <vector>
#include "Colors.h"

std::vector<std::vector<int>> moves = {
    {2, 1}, {2, -1}, {1, 2}, {1, -2}, 
    {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}
};

bool isValid(const std::vector<std::vector<int>> &board);

int main() {
    std::cout << "Enter filename: ";
    std::string filename;
    std::cin >> filename;

    std::ifstream fin(filename);

    if (!fin.is_open()) {
        std::cerr << "File " << filename << " doesn't exist\n";
        return 0;
    }

    int n;
    fin >> n;
    std::vector<std::vector<int>> board(n, std::vector<int> (n));

    for (auto& line : board) {
        for (auto& cell : line) {
            fin >> cell;
        }
    }

    if (isValid(board)) {
        std::cout << Colors::green() << "correct" << Colors::reset() << std::endl;
        return 0;
    }

    std::cout << Colors::red() << "wrong" << Colors::reset() << std::endl;
    return 0;
}

bool isValid(const std::vector<std::vector<int>> &board) {
    std::vector<bool> usedCell(board.size() * board.size(), false);

    std::pair<int, int> start_pos;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (!usedCell[board[i][j]]) {
                usedCell[board[i][j]] = true;
            } else {
                return false;
            }
            if (board[i][j] == 0) {
                start_pos = {i, j};
            }
        }
    }
    
    bool correct = true;
    while (correct) {
        if (board[start_pos.first][start_pos.second] == board.size() * board.size() - 1) {
            return true;
        }
        correct = false;
        for (auto move : moves) {
            int nx = start_pos.first + move[0];
            int ny = start_pos.second + move[1];
            if (nx >= 0 && nx < board.size()
             && ny >= 0 && ny < board.size()
             && board[nx][ny] == board[start_pos.first][start_pos.second] + 1) {
                start_pos = {nx, ny};
                correct = true;
            }
        }
    }

    return false;
}

#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

#define RESET "\33[0m"
#define RED "\33[31m" 
#define GREEN "\33[32m"

std::vector<std::vector<int>> moves = {
    {2, 1}, {2, -1}, {1, 2}, {1, -2}, 
    {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}
};

int countMoves(const std::vector<std::vector<int>> &board, int x, int y);

bool findPath(std::vector<std::vector<int>> &board, int x, int y, int step);
bool optimizedFindPath(std::vector<std::vector<int>> &board, int x, int y, int step);
bool randomFindPath(std::vector<std::vector<int>> &board, int x, int y, int step);

void clearBoard(std::vector<std::vector<int>> &board, int x, int y);
void printBoard(const std::vector<std::vector<int>> &board);

int main() {
    
    bool exit = false;
    std::vector<std::vector<int>> board(8, std::vector<int> (8, -1));
    int start_x = 0;
    int start_y = 0;

    while (!exit) {

        std::cout << "Select option:\n"
                  << "1 - standart reqursion\n"
                  << "2 - optimized\n"
                  << "3 - set board size\n"
                  << "4 - exit\n"
                  << ">> ";
        char choise;
        std::cin >> choise;

        switch (choise) {
            case '1': {
                std::cout << "Enter start position: "
                          << ">> ";
                std::cin >> start_x >> start_y;
                --start_x;
                --start_y;

                clearBoard(board, start_x, start_y);
                bool isPath = findPath(board, start_x, start_y, 0);

                if (isPath) {
                    printBoard(board);
                } else {
                    std::cout << "There is no path\n";
                }

                break;
            }
            case '2': {
                std::cout << "Enter start position: "
                          << ">> ";
                std::cin >> start_x >> start_y;
                --start_x;
                --start_y;
                
                clearBoard(board, start_x, start_y);
                bool isPath = optimizedFindPath(board, start_x, start_y, 0);

                if (isPath) {
                    printBoard(board);
                } else {
                    std::cout << "There is no path\n";
                }

                break;
            }
            case '3': {
                std::cout << "Current board size: " << board.size() << "\n"
                          << "Enter new board size:\n"
                          << ">> ";

                int n;
                std::cin >> n;

                board = std::vector<std::vector<int>> (n, std::vector<int> (n, -1));
                break;
            }
            case '4': {
                exit = true;
            }
        }
    }

    return 0;
}

bool findPath(std::vector<std::vector<int>> &board, int x, int y, int step) {
    int n = board.size();

    if (step == n * n - 1) {
        return true;
    }

    for (auto& move: moves) {
        int nx = move[0] + x;
        int ny = move[1] + y;
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == -1) {
            board[nx][ny] = step + 1;
            if (findPath(board, nx, ny, step + 1)) {
                return true;
            }
            board[nx][ny] = -1;

        }
    }

    return false;
}

bool optimizedFindPath(std::vector<std::vector<int>> &board, int x, int y, int step) {
    int n = board.size();

    if (step == n * n - 1) {
        return true;
    }

    std::vector<std::tuple<int, int, int>> next_moves;
    for (auto move : moves) {
        int nx = x + move[0];
        int ny = y + move[1];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == -1) {
            int degree = countMoves(board, nx, ny);
            next_moves.emplace_back(degree, nx, ny);
        }
    }
    std::sort(next_moves.begin(), next_moves.end());

    for (auto& [_, nx, ny]: next_moves) {
        board[nx][ny] = step + 1;
        if (optimizedFindPath(board, nx, ny, step + 1)) {
            return true;
        }
        board[nx][ny] = -1;
    }

    return false;
}

bool canMove(int move, int x, int y, int boardSize) {
    int nx = x + moves[move][0];
    int ny = y + moves[move][1];

    return nx >= 0 && nx < boardSize && ny >= 0 && ny <= boardSize;
}

bool randomFindPath(std::vector<std::vector<int>> &board, int x, int y, int step) {
   int visited = 1;
   bool exit = false;

   while (visited != board.size() * board.size() && !exit) {
        int move = std::rand() % 8;
        while (!canMove(move, x, y, static_cast<int>(board.size()))) {
            move = std::rand() % 8;
        }

        int nx = x + moves[move][0];
        int ny = y + moves[move][1];

        if (board[nx][ny] == -1) {
            ++visited;
        }

        x = nx;
        y = ny;
   }

   return true;
}

int countMoves(const std::vector<std::vector<int>> &board, int x, int y) {
    int res = 0;
    
    for (auto& move : moves) {
        int nx = x + move[0];
        int ny = y + move[1];

        if (nx >= 0 && nx < board.size()
         && ny >= 0 && ny < board.size()
         && board[nx][ny] == -1) {
            ++res;
        }
    }

    return res;
}

void clearBoard(std::vector<std::vector<int>> &board, int x, int y) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            board[i][j] = -1;
        }
    }

    board[x][y] = 0;
}

void printBoard(const std::vector<std::vector<int>> &board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            std::cout << (board[i][j] == 0 ? GREEN : board[i][j] == board.size() * board.size() - 1 ? RED : RESET) << std::left << std::setw(3) << board[i][j] << RESET;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

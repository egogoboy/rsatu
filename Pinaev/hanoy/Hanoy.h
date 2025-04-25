#pragma once

#include <vector>

class Hanoy {
public:
    static std::vector<char> recursive(int n, int p);
    static std::vector<char> iteration(int n, int p);
    static std::vector<char> lineal(int n, int p);

private:
    static void recursive_move(int n, char from, char to, char aux, int max_moves, int& moves_done, std::vector<char>& positions);

    static int getDiskIndex(int move);
    static int getDirection(int disk, int totalDisks);
};

#include "Hanoy.h"
#include <stack>

std::vector<char> Hanoy::recursive(int n, int p) {
    std::vector<char> result(n, 'A');
    int moves_done = 0;

    recursive_move(n, 'A', 'C', 'B', p, moves_done, result);
    return result;
}

void Hanoy::recursive_move(int n, 
                           char from, 
                           char to, 
                           char aux, 
                           int max_moves, 
                           int& moves_done, 
                           std::vector<char>& positions) {
    if (n == 0 || moves_done >= max_moves) {
        return;
    }

    recursive_move(n - 1, from, aux, to, max_moves, moves_done, positions);

    if (moves_done < max_moves) {
        positions[n - 1] = to;
        moves_done++;
    }

    recursive_move(n - 1, aux, to, from, max_moves, moves_done, positions);
}

std::vector<char> Hanoy::iteration(int n, int p) {
    std::vector<char> result(n, 'A');
    std::vector<std::stack<int>> pegs(3);
    char names[3] = {'A', 'B', 'C'};

    for (int i = n; i >= 1; --i) {
        pegs[0].push(i);
    }

    int total_moves = 0;
    int from = 0, to = 0, aux = 0;

    if (n % 2 == 0) {
        to = 1; aux = 2;
    } else {
        to = 2; aux = 1;
    }

    auto move_disk = [&](int from, int to) {
        if (pegs[from].empty() && pegs[to].empty()) return;
        if (pegs[from].empty()) {
            int disk = pegs[to].top(); pegs[to].pop();
            pegs[from].push(disk);
            result[disk - 1] = names[from];
        } else if (pegs[to].empty()) {
            int disk = pegs[from].top(); pegs[from].pop();
            pegs[to].push(disk);
            result[disk - 1] = names[to];
        } else {
            int topFrom = pegs[from].top();
            int topTo = pegs[to].top();
            if (topFrom < topTo) {
                pegs[from].pop();
                pegs[to].push(topFrom);
                result[topFrom - 1] = names[to];
            } else {
                pegs[to].pop();
                pegs[from].push(topTo);
                result[topTo - 1] = names[from];
            }
        }
    };

    while (total_moves < p) {
        int step = total_moves % 3;
        if (step == 0)
            move_disk(0, to);
        else if (step == 1)
            move_disk(0, aux);
        else
            move_disk(aux, to);
        total_moves++;
    }

    return result;
}




std::vector<char> Hanoy::lineal(int n, int p) {
    std::vector<char> positions(n, 'A');

    for (int move = 1; move <= p; ++move) {
        int disk = getDiskIndex(move);
        int from = positions[disk] - 'A';
        int dir = getDirection(disk, n);
        int to = (from + dir + 3) % 3;
        positions[disk] = to + 'A';

    }
    return positions;
}

int Hanoy::getDiskIndex(int move) {
    return __builtin_ctz(move);
}

int Hanoy::getDirection(int disk, int totalDisks) {
    return ((totalDisks % 2 == 0) ^ (disk % 2 == 0)) ? -1 : 1;
}

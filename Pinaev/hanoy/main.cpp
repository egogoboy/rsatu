#include <cmath>
#include <iostream>
#include <vector>
#include "Hanoy.h"

//3 варианта
//1 - рекурсивный
//2 - итерационный
//  нечётный ход - ход первым диском всегда
//  первый диск имеет 2 варината движения:
//    1) A->B->C->A->B->C
//  для четного: (?)
//    2) A->C->B->A->C->B
//  чётный ход:
//    выбора вообще нет
//    первый диск лежит на A:
//      двигаюсь слева на право и пропускаю все буквы А
//      следующая буква B и она соответсвует 3-ему диску
//
//      отыскиваем первую букву, не совпадающую с ппервым диском.
//      как только нашли диск, который может быть перемещён:
//      чётный ход выполняется единственно возможным образом.
//
//3 - линейный алгоритм (O(n)) (самое главное, самое основное)
//  нам дают число ходов
//  я представлю его в двоичном виде
//  я пишу наугад
//  10111011 - число ходов в двоичном виде
//  минимальный ход - 0, а максимальным 2^n - 1
//  1111111111 - максимальных ход, который может быть задан для n = 10
//  
//  чтобы переместить все эти диски на b, надо взять макушку и переместить её на c, для этого надо 2^(n-1) - 1
//  ещё один ход отвечает за перемещение самого большого диска у этого хода номер 2^(n - 1)

void printResult(const std::vector<char>& result) {
    for (auto c : result) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}

int main() {
    int disks_count = 0;
    int steps_count = 0;
    std::cout << "Enter count of disks: ";
    std::cin >> disks_count;
    while (steps_count < 1 || steps_count > std::pow(2, disks_count) - 1) {
        std::cout << "Enter count of steps: ";
        std::cin >> steps_count;
    }

    std::vector<char> result = Hanoy::recursive(disks_count, steps_count);
    std::cout << "recursive: ";
    printResult(result);
    result = Hanoy::iteration(disks_count, steps_count);

    std::cout << "iterative: ";
    printResult(result);
    result = Hanoy::lineal(disks_count, steps_count);

    std::cout << "lineal:    ";
    printResult(result);

    return 0;
}

#include <iostream>
#include <vector>

#define fin std::cin;

std::vector<int> calcD(std::vector<std::pair<int, int>>& pairs, int l);
int calcA(std::vector<std::pair<int, int>> &pairs, std::vector<int>& d, int A1);
int getOperation();
void writeByIndex(std::vector<char>& mass, std::vector<int>& d);
int getIndex(int n, std::vector<int>& d);
std::string readByIndex(std::vector<char>& mass, std::vector<int>& d, int l);
void writeByAdress(std::vector<char>& mass, int l);
char readByAdress(std::vector<char>& mass, int l);
std::vector<std::pair<int, int>> pairs;
int A0;

int main() {

    int n, l, A1;
    std::cout << "Введите n: ";
    std::cin >> n;

    std::cout << "Введите l: ";
    std::cin >> l;

    std::cout << "Введите A1: ";
    std::cin >> A1;
    
    std::cout << "Введите " << n << " граничн" << (n == 1 ? "ую" : "ых") << " пар" << (n == 1 ? "у" : "") << ":\n";

    for (int i = 0; i < n; i++) {
        std::pair<int, int> inputPair;
        std::cout << "Введите " << i + 1 << "-ю граничную пару: ";
        std::cin >> inputPair.first >> inputPair.second;
        if (inputPair.first > inputPair.second) {
            std::cout << "Ошибка ввода граничной пары\n";
            i--;
        }
        else {
            pairs.push_back(inputPair);
        }
    }
    std::cout << "Введённые данные\n";
    std::cout << "n = " << n << std::endl;
    std::cout << "l = " << l << std::endl;
    std::cout << "A1 = " << A1 << std::endl;
    
    std::vector<int> d = calcD(pairs, l);
    A0 = calcA(pairs, d, A1);
    

    std::cout << "Дескриптор:\n";
    std::cout << "   A1 = " << A1 << "\n";
    std::cout << "   A0 = " << A0 << "\n";
    std::cout << "   l = " << l << "\n";
    std::cout << "   n = " << n << "\n";

    std::cout << "Граничные пары:\n";

    int counter = 1;
    for (auto i : pairs) {
        std::cout << counter << ". " << i.first << " " << i.second << std::endl;
        counter++;
    }

    std::cout << "Индексные множители:\n";
    for (int i = 0; i < d.size(); i++) {
        std::cout << " D" << i + 1 << " = " << d[i] << std::endl;
    }
 
    std::vector<char> mass(15000, 0);

    int operation = getOperation();
    while (operation != 5) {
        switch (operation) {
            case 1: 
                writeByIndex(mass, d);
                break;
            case 2:
                std::cout  << readByIndex(mass, d, l) << std::endl;
                break;
            case 3:
                writeByAdress(mass, l);
                break;
            case 4:
                std::cout << readByAdress(mass, l) << std::endl;
                break;
        }
        operation = getOperation();
    }
    
    return 0;
}

void writeByAdress(std::vector<char>& mass, int l) {
    std::cout << "Введите адресс: ";
    int adress; std::cin >> adress;
    std::string val;
    std::cout << "Введите значение: ";
    std::cin >> val;
    mass[adress] = val[0];
}

char readByAdress(std::vector<char>& mass, int l) {
    std::cout << "Введите адресс: ";
    int adress; std::cin >> adress;
    std::string res = "";
    
    return mass[adress];
}

std::string readByIndex(std::vector<char>& mass, std::vector<int>& d, int l) {
    
    int idx = getIndex(d.size(), d);

    std::string res = "";
    for (int i = idx; i < idx + l; i++)
        res += mass[i];
    
    std::cout << idx << std::endl;

    return res;

}

void writeByIndex(std::vector<char>& mass, std::vector<int>& d) {
    
    int idx = getIndex(d.size(), d);

    std::string val = "";
    bool correct = true;
    std::cout << "Введите значение.\n";
    do {
        if (!correct) {
            std::cout << "Длина значения должна быть равна 3\n";
        }
        std::cin >> val;
        if (val.size() != 3)
            correct = false;
        else 
            correct = true;
    } while (!correct);

    for (auto i : val) {
        mass[idx] = i;
        idx++;
    }
    
}

int getIndex(int n, std::vector<int>& d) {
    std::cout << "Введите последовательно индексы:\n";
    std::vector<int> index(n);
    int idx = A0;
    for (int i = 0; i < index.size(); i++) {
        int curIndex;
        std::cin >> curIndex;
        idx += d[i] * curIndex;
    }
    return idx;
}

int getOperation() {
    int n;
    bool correctInput = true;
    do {
        if (!correctInput) {
            std::cout << "Неверное значение номера операции\n";
        }
        correctInput = true;
        std::cout << "Введите номер операции для выполнения: \n";
        std::cout << "1. Запись по индексу\n";
        std::cout << "2. Чтение по индексу\n";
        std::cout << "3. Запись по адресу\n";
        std::cout << "4. Чтение по адресу\n";
        std::cout << "5. Выход\n";
        std::cin >> n;

        if (n < 0 || n > 5)
            correctInput = false;
    } while (!correctInput);

    return n;
}

std::vector<int> calcD(std::vector<std::pair<int, int>>& pairs, int l) {
    std::vector<int> d(pairs.size(), 0);
    d[d.size() - 1] = l;
    for (int i = d.size() - 2; i >= 0; i--)
        d[i] = (pairs[i + 1].second - pairs[i + 1].first + 1) * d[i + 1];
    return d;
}

int calcA(std::vector<std::pair<int, int>> &pairs, std::vector<int>& d, int A1) {
    int A0 = A1;
    for (int i = 0; i < d.size(); i++) {
        std::cout << A0 << std::endl;
        A0 = A0 - (d[i] * pairs[i].first);    
    }
    return A0;
}

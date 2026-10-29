#include <iostream>
#include <fstream>
#include <clocale>
#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::ifstream fin("bilety.txt");
    if (!fin.is_open()) {
        std::cout << "Файл bilety.txt не найден!\n";
        return 1;
    }

    int n = 0;
    fin >> n;
    if (n <= 0) {
        std::cout << "Некорректное количество записей в файле.\n";
        fin.close();
        return 0;
    }

    Ticket* arr = new Ticket[n];

    for (int i = 0; i < n; i++) {
        if (!arr[i].read(fin)) {
            std::cout << "Ошибка чтения билета №" << i + 1 << "\n";
            fin.close();
            delete[] arr;
            return 1;
        }
    }
    fin.close();

    std::cout << "--- ВСЕ БИЛЕТЫ ---\n";
    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << ". ";
        arr[i].show();
    }

    std::cout << "\n--- БИЛЕТЫ СИДОРОВА ---\n";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i].isSidorov()) {
            arr[i].show();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Билетов на фамилию Сидоров нет.\n";
    }

    delete[] arr;
    return 0;
}
#include <iostream>
#include "lab9.h"

using namespace std;

int main() {
    int choice;
    do {
        // Організація меню (п. 3)
        cout << "\n===== МЕНЮ ЛАБОРАТОРНОЇ №9 =====";
        cout << "\n1. Завдання 1 (Метод replace)";
        cout << "\n2. Завдання 2 (String 33 - обробка файлу)";
        cout << "\n0. Вихід";
        cout << "\nВаш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                task1_demo(); 
                break;
            case 2: 
                task2_file_demo(); 
                break;
            case 0: 
                cout << "Роботу завершено.\n"; 
                break;
            default: 
                cout << "Невірний вибір!\n";
        }
    } while (choice != 0);

    return 0;
}
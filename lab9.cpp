#include "lab9.h"
#include <iostream>
#include <fstream>

using namespace std;

// --- Завдання 1 ---
void my_replace(char* target, int pos, int len, const char* source, int subpos, int sublen) {
    int target_len = 0, source_len = 0;
    while (target[target_len] != '\0') target_len++;
    while (source[source_len] != '\0') source_len++;

    char temp[2000];
    int k = 0;

    for (int i = 0; i < pos && i < target_len; i++) {
        temp[k++] = target[i];
    }
    for (int i = subpos; i < subpos + sublen && i < source_len; i++) {
        temp[k++] = source[i];
    }
    for (int i = pos + len; i < target_len; i++) {
        temp[k++] = target[i];
    }
    temp[k] = '\0';

    for (int i = 0; i <= k; i++) {
        target[i] = temp[i];
    }
}

void task1_demo() {
    string s_std;
    char s_my[1000];
    string s_source;
    int pos, len, subpos, sublen;

    // Введення одного рядка і збереження в обох типах (згідно п. 1.С)
    cout << "\nВведіть цільовий рядок: ";
    cin.ignore();
    getline(cin, s_std);
    
    // Копіюємо у масив символів вручну
    int i = 0;
    for (i = 0; i < s_std.length(); i++) {
        s_my[i] = s_std[i];
    }
    s_my[i] = '\0';

    cout << "Введіть рядок-джерело для вставки: ";
    getline(cin, s_source);

    cout << "Введіть параметри (pos len subpos sublen): ";
    cin >> pos >> len >> subpos >> sublen;

    // Виклик стандартного методу
    s_std.replace(pos, len, s_source, subpos, sublen);
    
    // Виклик власної функції
    my_replace(s_my, pos, len, s_source.c_str(), subpos, sublen);

    cout << "\nРезультат std::string::replace : " << s_std;
    cout << "\nРезультат власної my_replace   : " << s_my << endl;
}

// --- Завдання 2 ---
bool task2_is_valid(const string& str) {
    return !str.empty();
}

string task2_process_string(string s1, const string& s2) {
    size_t found = s1.find(s2);
    if (found != string::npos) {
        s1.erase(found, s2.length());
    }
    return s1;
}

void task2_file_demo() {
    string s2;
    cout << "\nВведіть підрядок S2 для видалення: ";
    cin.ignore();
    getline(cin, s2);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open()) {
        cout << "Помилка: файл input.txt не знайдено!" << endl;
        return;
    }

    string line;
    int count = 0;
    
    // Обробка файлу рядок за рядком (п. 2.D)
    while (getline(fin, line)) {
        if (task2_is_valid(line)) {
            string result = task2_process_string(line, s2);
            fout << result << "\n"; // Запис у вихідний файл (п. 2.Е)
            count++;
        }
    }

    cout << "Оброблено рядків: " << count << ". Результат записано у output.txt\n";
    
    fin.close();
    fout.close();
}
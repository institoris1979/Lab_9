#ifndef LAB9_H
#define LAB9_H

#include <string>

// Завдання 1
void my_replace(char* target, int pos, int len, const char* source, int subpos, int sublen);
void task1_demo(); // Функція без параметрів для меню

// Завдання 2
std::string task2_process_string(std::string s1, const std::string& s2);
bool task2_is_valid(const std::string& str);
void task2_file_demo(); // Функція без параметрів для меню

#endif // LAB9_H
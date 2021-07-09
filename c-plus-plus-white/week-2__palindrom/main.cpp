/*
 * Напишите функцию, которая
 * называется IsPalindrom
 * возвращает bool
 * принимает параметр типа string и возвращает, является ли переданная строка палиндромом
 * Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево.
 * Пустая строка является палиндромом.
 */

#include <iostream>
using namespace std;

bool IsPalindrom(string str) {
    int halfLen = str.size() / 2;
    for (int i = 0; i < halfLen; ++i) {
        if (str[i] != str[str.size()-1-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    cin >> str;

    cout << IsPalindrom(str) << endl;
    return 0;
}

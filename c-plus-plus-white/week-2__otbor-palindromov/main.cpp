/*
 * Напишите функцию, которая
 * называется PalindromFilter
 * возвращает vector<string>
 * принимает vector<string> words и int minLength и возвращает все строки из вектора words,
 * которые являются палиндромами и имеют длину не меньше minLength
 * Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.
 */

#include <iostream>
#include <vector>
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

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> filtered = {};
    for (auto w : words) {
        if (w.size() < minLength) {
            continue;
        }
        if (IsPalindrom(w)) {
            filtered.push_back(w);
        }
    }
    return filtered;
}

int main() {
    vector<string> words = {"abacaba", "aba"};
    int minLength = 2;
    vector<string> filtered = PalindromFilter(words, minLength);
    for (auto f : filtered) {
        cout << f << ' ';
    }
    cout << endl;
    return 0;
}

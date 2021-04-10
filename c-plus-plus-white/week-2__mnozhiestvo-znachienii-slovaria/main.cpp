/*
 * Напишите функцию BuildMapValuesSet, принимающую на вход словарь map<int, string>
 * и возвращающую множество значений этого словаря.
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> values;
    for (auto& item : m) {
        values.insert(item.second);
    }

    return values;
}

int main() {
    set<string> values = BuildMapValuesSet({
        {1, "odd"},
        {2, "even"},
        {3, "odd"},
        {4, "even"},
        {5, "odd"}
    });

    for (const string& value : values) {
        cout << value << endl;
    }

    return 0;
}

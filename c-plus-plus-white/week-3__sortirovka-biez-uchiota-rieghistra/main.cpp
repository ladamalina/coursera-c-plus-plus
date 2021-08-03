/*
 * В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S.
 * Между собой число и строки разделены пробелом.
 * Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв,
 * и выведите их в стандартный поток вывода.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

bool compareNormalised(const string& i, const string& j) {
    string c1 = i;
    for_each(c1.begin(), c1.end(), [](char& c){ c = tolower(c); });
    string c2 = j;
    for_each(c2.begin(), c2.end(), [](char& c){ c = tolower(c); });

    return (c1 < c2);
}

int main() {
    int n;
    cin >> n;
    vector<string> strs;
    string tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        strs.push_back(tmp);
    }
    sort(strs.begin(), strs.end(), compareNormalised);
    for (auto& s : strs) {
        cout << s << ' ';
    }
    cout << endl;

    return 0;
}

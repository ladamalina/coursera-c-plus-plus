/*
 * В стандартном потоке дана одна строка, состоящая из N + 1 целых чисел. Первым числом идёт само число N.
 * Далее следуют ещё N чисел, обозначим их за массив A. Между собой числа разделены пробелом.
 * Отсортируйте массив А по модулю и выведите его в стандартный поток.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compareAbs(const int& i, const int& j) {
    return (abs(i) < abs(j));
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    string tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        nums.push_back(stoi(tmp));
    }
    sort (nums.begin(), nums.end(), compareAbs);
    for (auto& num : nums) {
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}

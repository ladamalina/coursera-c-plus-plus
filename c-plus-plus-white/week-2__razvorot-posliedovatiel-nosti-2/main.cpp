/*
 * Напишите функцию UpdateIfGreater, которая принимает два целочисленных аргумента: first и second.
 * Если first оказался больше second, Ваша функция должна записывать в second значение параметра first.
 * При этом указанная функция не должна ничего возвращать, а изменение параметра second должно быть
 * видно на вызывающей стороне.
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> v2 = {};
    for (int i = v.size()-1; i >= 0; --i) {
        v2.push_back(v[i]);
    }
    return v2;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    vector<int> numbers2 = {2, 4, 3, 5, 1};
    if (Reversed(numbers) == numbers2) {
        cout << true;
    }

    return 0;
}

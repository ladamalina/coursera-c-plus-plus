/*
 * Напишите функцию UpdateIfGreater, которая принимает два целочисленных аргумента: first и second.
 * Если first оказался больше second, Ваша функция должна записывать в second значение параметра first.
 * При этом указанная функция не должна ничего возвращать, а изменение параметра second должно быть
 * видно на вызывающей стороне.
 */

#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
    if (v.size() <= 1) {
        return;
    }
    int halfLen = v.size() / 2;
    for (int i = 0; i < halfLen; ++i) {
        auto tmp = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = tmp;
    }
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    return 0;
}

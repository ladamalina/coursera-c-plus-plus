/*
 * Реализуйте функцию void Reverse(vector<int>& v), которая переставляет элементы вектора в обратном порядке.
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

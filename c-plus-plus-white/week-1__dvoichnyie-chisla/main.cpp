/*
 * На вход дано целое положительное число N. Выведите его в двоичной системе счисления без ведущих нулей.
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v = {};
    while (n > 0) {
        int next_v = n % 2;
        v.push_back(next_v);

        n = n / 2;
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[v.size()-1-i];
    }
    cout << endl;
    return 0;
}

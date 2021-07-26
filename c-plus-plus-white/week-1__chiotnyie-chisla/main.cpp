/*
 * Дано два целых числа A и B (A <= B, A >= 1, B <= 30000).
 * Выведите через пробел все чётные числа от A до B (включительно).
 */

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int i;
    if (a % 2 == 0) {
        i = a;
    } else {
        i = a + 1;
    }

    while (i <= b) {
        cout << i << ' ';
        i += 2;
    }
    cout << endl;

    return 0;
}

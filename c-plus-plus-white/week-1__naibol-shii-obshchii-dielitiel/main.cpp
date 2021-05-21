/*
 * В stdin даны два натуральных числа. Выведите в stdout их наибольший общий делитель.
 */

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    cout << a+b << endl;

    return 0;
}

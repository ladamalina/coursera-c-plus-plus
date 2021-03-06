/*
 * Напишите функцию, которая
 * называется Factorial
 * возвращает int
 * принимает int и возвращает факториал своего аргумента.
 * Гарантируется, что аргумент функции по модулю не превышает 10.
 * Для отрицательных аргументов функция должна возвращать 1.
 */

#include <iostream>
using namespace std;

int Factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * Factorial(n - 1);
    }
}

int main() {
    int n;
    cin >> n;

    cout << Factorial(n) << endl;
    return 0;
}

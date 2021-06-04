/*
 * На вход вашей программы в стандартном потоке ввода подаются действительные коэффициенты
 * A, B и C уравнения Ax² + Bx + C = 0. Выведите все его различные действительные корни в поток вывода
 * в любом порядке, при этом разделяя корни пробелами. Гарантируется, что хотя бы один из коэффициентов уравнения
 * не равен нулю.
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0.0) {
        if (b == 0.0) {
            return 0;
        } else {
            double x1 = (-1*c) / b;
            cout << x1 << endl;
            return 0;
        }
    }

    double d = b*b - 4*a*c;
    if (d < 0) {
        return 0;
    } else if (d == 0) { // d==0, 1 корень
        double x1 = (-1*b) / (2*a);
        cout << x1 << endl;
    } else { // d>0, 2 корня
        double x1 = ((-1*b) + sqrt(d)) / (2*a);
        double x2 = ((-1*b) - sqrt(d)) / (2*a);
        cout << x1 << ' ' << x2 << endl;
    }
    return 0;
}

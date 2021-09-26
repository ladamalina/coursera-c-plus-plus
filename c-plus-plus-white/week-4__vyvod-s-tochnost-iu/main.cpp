/*
 * В файле input.txt записаны вещественные числа, по одному на строчку. На стандартный вывод напечатайте эти числа
 * в том же порядке, по одному на строке, но сделайте так, чтобы у каждого из них было ровно три знака
 * после десятичной точки.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    const string inPath = "input.txt";
    ifstream input(inPath);
    if (input) {
        string line;
        cout << fixed << setprecision(3);
        while (getline(input, line)) {
            double d = stod(line);
            cout << d << endl;
        }
    }
    return 0;
}

/*
 * Снова считайте все содержимое файла input.txt, но на этот раз выведите его в файл output.txt .
 * Точно так же гарантируется, что содержимое файла input.txt заканчивается переводом строки.
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

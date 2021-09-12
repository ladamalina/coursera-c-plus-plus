/*
 * Ваша программа должна считать содержимое файла input.txt и напечатать его на экран без изменений.
 * Гарантируется, что содержимое файла input.txt заканчивается переводом строки.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    const string path = "input.txt";
    ifstream input(path);
    if (input) {
        string line;
        while (getline(input, line)) {
            cout << line << endl;
        }
    }
    return 0;
}

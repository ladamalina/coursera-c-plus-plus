/*
 * Снова считайте все содержимое файла input.txt, но на этот раз выведите его в файл output.txt .
 * Точно так же гарантируется, что содержимое файла input.txt заканчивается переводом строки.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    const string inPath = "input.txt";
    const string outPath = "output.txt";

    ifstream input(inPath);
    ofstream output(outPath);
    if (input && output) {
        string line;
        while (getline(input, line)) {
            output << line << endl;
        }
    }
    return 0;
}

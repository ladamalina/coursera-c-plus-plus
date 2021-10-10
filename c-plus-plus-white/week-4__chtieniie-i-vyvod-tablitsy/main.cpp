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
    if (!input) {
        return 1;
    }

    int rowsNum, columnsNum;
    input >> rowsNum >> columnsNum;

    // перебираем строки
    for (int i = 0; i < rowsNum; ++i) {
        // перебираем столбцы
        for (int j = 0; j < columnsNum; ++j) {
            // считываем очередное число
            int x;
            input >> x;
            // пропускаем следующий символ
            input.ignore(1);
            // выводим число в поле ширины 10
            cout << setw(10) << x;
            // выводим пробел, если только этот столбец не последний
            if (j != columnsNum - 1) {
                cout << " ";
            }
        }
        // выводим перевод строки, если только эта строка не последняя
        if (i != rowsNum - 1) {
            cout << endl;
        }
    }

    return 0;
}

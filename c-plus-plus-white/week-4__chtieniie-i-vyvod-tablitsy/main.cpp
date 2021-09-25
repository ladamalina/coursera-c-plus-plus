/*
 * В первой строке файла input.txt записаны два числа N и M. Далее в файле находится таблица из N строк и M столбцов,
 * представленная в формате CSV (comma-separated values). Такой формат часто используется для текстового представления
 * таблиц с данными: в файле несколько строк, значения из разных ячеек внутри строки отделены друг от друга запятыми.
 * Ваша задача — вывести данные на экран в виде таблицы.
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

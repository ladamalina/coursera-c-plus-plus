/*
 * Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
 * Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.
 * Гарантируется, что среднее арифметическое значений температуры является целым числом.
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> temp;
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        temp.push_back(t);
    }

    int sum;
    for (int i = 0; i < n; ++i) {
        sum += temp[i];
    }
    int avg;
    avg = sum / n;

    vector<int> high;
    for (int i = 0; i < n; ++i) {
        if (temp[i] > avg) {
            high.push_back(i);
        }
    }

    cout << high.size() << endl;
    for (int h : high) {
        cout << h << ' ';
    }
    cout << endl;

    return 0;
}

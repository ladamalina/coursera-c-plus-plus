/*
 * Дана строка. Найдите в этой строке второе вхождение буквы f и выведите  индекс этого вхождения.
 * Если буква f в данной строке встречается только  один раз, выведите число -1,
 * а если не встречается ни разу, выведите  число -2. Индексы нумеруются с нуля.
 */

#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;

    int i1 = -2;
    int i2 = -1;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'f') {
            if (i1 < 0) {
                i1 = i;
                continue;
            }
            if (i2 < 0) {
                i2 = i;
                break;
            }
        }
    }

    if (i2 >= 0) {
        cout << i2 << endl;
    } else if (i1 >= 0) {
        cout << -1 << endl;
    } else {
        cout << -2 << endl;
    }

    return 0;
}

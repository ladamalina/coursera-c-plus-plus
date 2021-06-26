/*
 * В стандартном потоке даны три строки, разделённые пробелом.
 * Каждая строка состоит из строчных латинских букв и имеет длину не более 30 символов.
 * Выведите в стандартный вывод лексикографически минимальную из них.
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vector<string> strings = {s1, s2, s3};
    string min_str = s1;
    for (string s : strings) {
        if (s < min_str) {
            min_str = s;
        }
    }
    cout << min_str;

    return 0;
}
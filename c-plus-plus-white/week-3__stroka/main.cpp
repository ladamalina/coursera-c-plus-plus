/*
 * Реализуйте класс ReversibleString, хранящий строку и поддерживающий методы Reverse для переворота строки
 * и ToString для получения строки.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class ReversibleString {
public:
    ReversibleString() {
        src_str = "";
    }
    explicit ReversibleString(const string& str) {
        src_str = str;
    }
    void Reverse() {
        reverse(src_str.begin(), src_str.end());
    }
    string ToString() const {
        return src_str;
    }
private:
    string src_str;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}

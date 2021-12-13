#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> v;
    auto current_it = begin(s);
    auto last_space_it = begin(s)-1;
    while (current_it < end(s)) {
        current_it = find_if(last_space_it+1, end(s),
                             [](char c){return c == ' ';}
                             );
        string word = string(last_space_it + 1, current_it);
        v.push_back(word);
        last_space_it = current_it;
    }

    return v;
}

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}

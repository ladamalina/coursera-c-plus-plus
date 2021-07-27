/*
 * Слова называются анаграммами друг друга, если одно из них можно получить перестановкой букв в другом.
 * Например, слово «eat» можно получить перестановкой букв слова «tea»,
 * поэтому эти слова являются анаграммами друг друга. Даны пары слов, проверьте для каждой из них,
 * являются ли слова этой пары анаграммами друг друга.
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;

vector<string> SplitLine(const string& str) {
    istringstream iss(str);
    string sub;
    vector<string> subs;
    while (iss >> sub)
        subs.push_back(sub);
    return subs;
}

map<char, int> BuildCharCounters(const string& str) {
    map<char, int> chMap;
    for (char ch : str) {
        chMap[ch] += 1;
    }
    return chMap;
}

int main() {
    int n_ops;
    cin >> n_ops;
    vector<string> cmds;
    string cmd;
    while (cmds.size() < n_ops) {
        getline(cin, cmd);
        if (cmd.empty())
            continue;
        cmds.push_back(cmd);
    }

    for (const string& c : cmds) {
        vector<string> cmd_parts = SplitLine(c);
        if (BuildCharCounters(cmd_parts[0]) == BuildCharCounters(cmd_parts[1])) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

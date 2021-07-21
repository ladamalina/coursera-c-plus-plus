/*
 * Два слова называются синонимами друг друга, если они имеют похожие значения.
 * Реализуйте следующие операции над словарём синонимов:
 *
 * ADD word1 word2 — добавить в словарь пару синонимов (word1, word2).
 * COUNT word — узнать количество синонимов слова word.
 * CHECK word1 word2 — проверить, являются ли слова word1 и word2 синонимами.
 * Слова word1 и word2 считаются синонимами, если среди запросов ADD был хотя бы один запрос
 * ADD word1 word2 или ADD word2 word1.
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
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

    map<string, set<string>> words;
    for (const string& c : cmds) {
        vector<string> cmd_parts = SplitLine(c);
        if (cmd_parts[0] == "ADD") {
            words[cmd_parts[1]].insert(cmd_parts[2]);
            words[cmd_parts[2]].insert(cmd_parts[1]);
        } else if (cmd_parts[0] == "COUNT") {
            int cnt = words[cmd_parts[1]].size();
            cout << cnt << endl;
        } else if (cmd_parts[0] == "CHECK") {
            if (words[cmd_parts[1]].count(cmd_parts[2]) == 1
                    || words[cmd_parts[2]].count(cmd_parts[1]) == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}

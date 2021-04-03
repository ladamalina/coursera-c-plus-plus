/*
 * Дан набор строк. Найдите количество уникальных строк в этом наборе.
 */

#include <iostream>
#include <vector>
#include <string>
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

    set<string> strs(cmds.begin(), cmds.end());
    cout << strs.size() << endl;

    return 0;
}

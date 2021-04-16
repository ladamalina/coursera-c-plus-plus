/*
 * В этой задаче вам нужно присваивать номера автобусным маршрутам.
 * А именно, для каждого маршрута, заданного множеством названий остановок, нужно либо выдать новый номер
 * (первому маршруту — 1, второму — 2 и т. д.), либо вернуть номер существующего маршрута,
 * которому соответствует такое множество остановок.
 * В отличие от задачи «Автобусные остановки — 2», наборы остановок, которые можно получить друг из друга
 * перестановкой элементов или добавлением/удалением повторяющихся, следует считать одинаковыми.
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

    map<set<string>, int> routeToBus;
    for (const string& c : cmds) {
        vector<string> cmd_parts = SplitLine(c);
        int newBusStopsCount = stoi(cmd_parts[0]);
        set<string> newBusStops(cmd_parts.begin()+1, cmd_parts.begin()+1+newBusStopsCount);
        if (routeToBus.count(newBusStops) == 1) {
            cout << "Already exists for " << routeToBus[newBusStops] << endl;
        } else {
            int newBusNumber = routeToBus.size() + 1;
            routeToBus[newBusStops] = newBusNumber;
            cout << "New bus " << newBusNumber << endl;
        }
    }

    return 0;
}

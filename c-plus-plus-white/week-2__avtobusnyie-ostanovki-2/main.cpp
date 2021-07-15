/*
 * В этой задаче вам нужно присваивать номера автобусным маршрутам.
 * А именно, для каждого маршрута, заданного набором названий остановок, нужно либо выдать новый номер
 * (первому маршруту — 1, второму — 2 и т. д.), либо вернуть номер существующего маршрута,
 * которому соответствует такой набор остановок.
 * Наборы остановок, полученные друг из друга перестановкой остановок, считаются различными (см. пример).
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

    map<vector<string>, int> routeToBus;
    for (const string& c : cmds) {
        vector<string> cmd_parts = SplitLine(c);
        int newBusStopsCount = stoi(cmd_parts[0]);
        vector<string> newBusStops(cmd_parts.begin()+1, cmd_parts.begin()+1+newBusStopsCount);
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

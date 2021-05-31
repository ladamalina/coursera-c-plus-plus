/*
 * У каждого из нас есть повторяющиеся ежемесячные дела, каждое из которых нужно выполнять
 * в конкретный день каждого месяца: оплата счетов за электричество, абонентская плата за связь и пр.
 * Вам нужно реализовать работу со списком таких дел на месяц.
 */

#include <iostream>
#include <vector>
#include <string>
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

int GetNextMonthIdx(int currentMonthIdx) {
    if (currentMonthIdx == 11) {
        return 0;
    } else {
        return currentMonthIdx + 1;
    }
}

void Add(vector<vector<string>>& toDoList, int i, const string& s) {
    toDoList[i-1].push_back(s);
}

void Dump(const vector<vector<string>>& toDoList, int i) {
    cout << toDoList[i-1].size() << ' ';
    for (const auto& toDo : toDoList[i-1]) {
        cout << toDo << ' ';
    }
    cout << endl;
}

void Next(vector<vector<string>>& toDoList, int& currentMonthIdx, const vector<int>& daysInMonth) {
    int nextMonthIdx = GetNextMonthIdx(currentMonthIdx);
    int currentMonthDays = daysInMonth[currentMonthIdx];
    int nextMonthDays = daysInMonth[nextMonthIdx];

    if (nextMonthDays < currentMonthDays) {
        for (int dayIdx = nextMonthDays; dayIdx < currentMonthDays; ++dayIdx) {
            for (const string& toDo : toDoList[dayIdx]) {
                toDoList[nextMonthDays - 1].push_back(toDo);
            }
        }
    }
    toDoList.resize(nextMonthDays);
    currentMonthIdx = nextMonthIdx;
}

int main() {
    int n_ops;
    cin >> n_ops;
    vector<string> cmds;
    string cmd;
    while (cmds.size() < n_ops) {
        getline(cin, cmd);
        if (cmd.size() < 1)
            continue;
        cmds.push_back(cmd);
    }

    const vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
    int currentMonthIdx = 0;
    vector<vector<string>> toDoList(daysInMonth[currentMonthIdx]);

    for (string cmd : cmds) {
        vector<string> cmd_parts = SplitLine(cmd);
        if (cmd_parts[0] == "ADD") {
            int i = stoi(cmd_parts[1]);
            Add(toDoList, i, cmd_parts[2]);
        } else if (cmd_parts[0] == "DUMP") {
            int i = stoi(cmd_parts[1]);
            Dump(toDoList, i);
        } else if (cmd_parts[0] == "NEXT") {
            Next(toDoList, currentMonthIdx, daysInMonth);
        }
    }

    return 0;
}

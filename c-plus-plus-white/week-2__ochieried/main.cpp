/*
 * Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда.
 * Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.
 * Будем считать, что люди в очереди нумеруются целыми числами, начиная с 0.
 * Реализуйте обработку следующих операций над очередью:
 *
 * WORRY i: пометить i-го человека с начала очереди как беспокоящегося;
 * QUIET i: пометить i-го человека как успокоившегося;
 * COME k: добавить k спокойных человек в конец очереди;
 * COME -k: убрать k человек из конца очереди;
 * WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
 *
 * Изначально очередь пуста.
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void Worry(vector<bool>& v, int i) {
    v[i] = false;
}

void Quiet(vector<bool>& v, int i) {
    v[i] = true;
}

void Come(vector<bool>& v, int k) {
    v.resize(v.size() + k, true);
}

int WorryCount(const vector<bool>& v) {
    int wc = 0;
    for (bool is_quiet : v) {
        if (!is_quiet) {
            ++wc;
        }
    }
    return wc;
}

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
        if (cmd.size() < 1)
            continue;
        cmds.push_back(cmd);
    }

    vector<bool> queue(0, true);
    for (string cmd : cmds) {
        vector<string> cmd_parts = SplitLine(cmd);
        if (cmd_parts[0] == "WORRY") {
            int i = stoi(cmd_parts[1]);
            Worry(queue, i);
        } else if (cmd_parts[0] == "QUIET") {
            int i = stoi(cmd_parts[1]);
            Quiet(queue, i);
        } else if (cmd_parts[0] == "COME") {
            int i = stoi(cmd_parts[1]);
            Come(queue, i);
        } else if (cmd_parts[0] == "WORRY_COUNT") {
            cout << WorryCount(queue) << endl;
        }
    }

    return 0;
}

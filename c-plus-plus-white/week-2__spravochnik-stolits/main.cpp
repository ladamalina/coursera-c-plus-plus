/*
 * Реализуйте справочник столиц стран.
 * На вход программе поступают следующие запросы:
 *
 * CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital,
 * либо добавление такой страны с такой столицей, если раньше её не было.
 * RENAME old_country_name new_country_name — переименование страны из old_country_name в new_country_name.
 * ABOUT country — вывод столицы страны country.
 * DUMP — вывод столиц всех стран.
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

void ChangeCapital(map<string, string>& registry, const string& country, const string& capital) {
    if (registry.count(country) == 1) {
        if (registry[country] == capital) {
            cout << "Country " << country << " hasn't changed its capital" << endl;
        } else {
            cout << "Country " << country << " has changed its capital from " << registry[country]
                << " to " << capital << endl;
        }
    } else {
        cout << "Introduce new country " << country << " with capital " << capital << endl;
    }
    registry[country] = capital;
}

void RenameCountry(map<string, string>& registry, const string& oldName, const string& newName) {
    if (oldName == newName || registry.count(oldName) == 0 || registry.count(newName) == 1) {
        cout << "Incorrect rename, skip" << endl;
        return;
    }
    registry[newName] = registry[oldName];
    registry.erase(oldName);
    cout << "Country " << oldName << " with capital " << registry[newName] << " has been renamed to "
        << newName << endl;
}

void AboutCountry(map<string, string>& registry, const string& country) {
    if (registry.count(country) == 0) {
        cout << "Country " << country << " doesn't exist" << endl;
    } else {
        cout << "Country " << country << " has capital " << registry[country] << endl;
    }
}

void Dump(map<string, string>& registry) {
    if (registry.empty()) {
        cout << "There are no countries in the world" << endl;
    } else {
        for (const auto& item : registry) {
            cout << item.first << "/" << item.second << endl;
        }
    }
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

    map<string, string> registry;
    for (const string& c : cmds) {
        vector<string> cmd_parts = SplitLine(c);
        if (cmd_parts[0] == "CHANGE_CAPITAL") {
            ChangeCapital(registry, cmd_parts[1], cmd_parts[2]);
        } else if (cmd_parts[0] == "RENAME") {
            RenameCountry(registry, cmd_parts[1], cmd_parts[2]);
        } else if (cmd_parts[0] == "ABOUT") {
            AboutCountry(registry, cmd_parts[1]);
        } else if (cmd_parts[0] == "DUMP") {
            Dump(registry);
        }
    }

    return 0;
}

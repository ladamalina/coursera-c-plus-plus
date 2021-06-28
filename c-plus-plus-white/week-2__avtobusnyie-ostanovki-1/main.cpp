/*
 * Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:
 * NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками
 * с названиями stop1, stop2, ...
 * BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
 * STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов,
 * на которые можно пересесть на каждой из остановок.
 * ALL_BUSES — вывести список всех маршрутов с остановками.
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

void NewBus(map<string, vector<string>>& buses, map<string, vector<string>>& stops, const string& newBus,
            const vector<string>& newBusStops) {
    buses[newBus] = newBusStops;
    for (auto& newBusStop : newBusStops) {
        stops[newBusStop].push_back(newBus);
    }
}

void BusesForStop(map<string, vector<string>>& buses, map<string, vector<string>>& stops, const string& stop) {
    if (stops.count(stop) == 0) {
        cout << "No stop" << endl;
        return;
    }
    for (auto& bus : stops[stop]) {
        cout << bus << ' ';
    }
    cout << endl;
}

void StopsForBus(map<string, vector<string>>& buses, map<string, vector<string>>& stops, const string& bus) {
    if (buses.count(bus) == 0) {
        cout << "No bus" << endl;
        return;
    }
    for (auto& stop : buses[bus]) {
        cout << "Stop " << stop << ':';
        vector<string> intercharges;
        for (auto& intercharge : stops[stop]) {
            if (intercharge != bus) {
                intercharges.push_back(intercharge);
            }
        }
        if (!intercharges.empty()) {
            for (auto& intercharge : intercharges) {
                cout << ' ' << intercharge;
            }
        } else {
            cout << " no interchange";
        }
        cout << endl;
    }
}

void AllBuses(map<string, vector<string>>& buses) {
    if (buses.empty()) {
        cout << "No buses" << endl;
        return;
    }

    for (auto& item : buses) {
        cout << "Bus " << item.first << ':';
        for (auto& stop : item.second) {
            cout << ' ' << stop;
        }
        cout << endl;
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

    map<string, vector<string>> buses;
    map<string, vector<string>> stops;
    for (const string& c : cmds) {
        vector<string> cmd_parts = SplitLine(c);
        if (cmd_parts[0] == "NEW_BUS") {
            int newBusStopsCount = stoi(cmd_parts[2]);
            vector<string> newBusStops(cmd_parts.begin()+3, cmd_parts.begin()+3+newBusStopsCount);
            NewBus(buses, stops, cmd_parts[1], newBusStops);
        } else if (cmd_parts[0] == "BUSES_FOR_STOP") {
            BusesForStop(buses, stops, cmd_parts[1]);
        } else if (cmd_parts[0] == "STOPS_FOR_BUS") {
            StopsForBus(buses, stops, cmd_parts[1]);
        } else if (cmd_parts[0] == "ALL_BUSES") {
            AllBuses(buses);
        }
    }

    return 0;
}

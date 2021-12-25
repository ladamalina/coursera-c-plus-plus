#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;
using SToList = map<string, vector<string>>;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string operation_code;
    is >> operation_code;

    if (operation_code == "NEW_BUS") {
        q.type = QueryType::NewBus;
        cin >> q.bus;
        int stop_count;
        cin >> stop_count;
        q.stops = {};
        for (int i = 0; i < stop_count; ++i) {
            string stop;
            cin >> stop;
            q.stops.push_back(stop);
        }

    } else if (operation_code == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        cin >> q.stop;

    } else if (operation_code == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        cin >> q.bus;

    } else if (operation_code == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }

    return is;
}

struct BusesForStopResponse {
    bool stop_found;
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (!r.stop_found) {
        cout << "No stop";
    } else {
        for (const string& bus : r.buses) {
            cout << bus << " ";
        }
    }
    return os;
}

struct StopsForBusResponse {
    bool bus_found;
    string bus;
    vector<string> stops;
    SToList stops_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (!r.bus_found) {
        cout << "No bus";
    } else {
        size_t stops_count = r.stops.size();
        size_t i = 0;
        for (const string& stop : r.stops) {
            cout << "Stop " << stop << ": ";
            if (r.stops_to_buses.at(stop).size() == 1) {
                cout << "no interchange";
            } else {
                for (const string& other_bus : r.stops_to_buses.at(stop)) {
                    if (r.bus != other_bus) {
                        cout << other_bus << " ";
                    }
                }
            }
            if (i+1 < stops_count) {
                cout << endl;
            }
            ++i;
        }
    }
    return os;
}

struct AllBusesResponse {
    bool buses_found;
    SToList buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (!r.buses_found) {
        cout << "No buses";
    } else {
        size_t buses_count = r.buses_to_stops.size();
        size_t i = 0;
        for (const auto& bus_item : r.buses_to_stops) {
            cout << "Bus " << bus_item.first << ": ";
            for (const string& stop : bus_item.second) {
                cout << stop << " ";
            }
            if (i+1 < buses_count) {
                cout << endl;
            }
            ++i;
        }
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        buses_to_stops[bus] = stops;
        for (const string& stop : stops) {
            stops_to_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        if (stops_to_buses.count(stop) == 0) {
            return BusesForStopResponse{false, {}};
        }
        return BusesForStopResponse{true, stops_to_buses.at(stop)};
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        if (buses_to_stops.count(bus) == 0) {
            return StopsForBusResponse{false, "", {}};
        }
        StopsForBusResponse r{true, bus, buses_to_stops.at(bus)};
        for (const string& stop : buses_to_stops.at(bus)) {
            r.stops_to_buses[stop] = stops_to_buses.at(stop);
        }
        return r;
    }

    AllBusesResponse GetAllBuses() const {
        if (buses_to_stops.empty()) {
            return AllBusesResponse{false, {}};
        }
        return AllBusesResponse{true, buses_to_stops};
    }

private:
    SToList buses_to_stops;
    SToList stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}

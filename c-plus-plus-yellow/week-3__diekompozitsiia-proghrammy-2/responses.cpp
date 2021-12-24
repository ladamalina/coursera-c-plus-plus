#include "iostream"
#include "string"
#include "vector"
#include "responses.h"

using namespace std;

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
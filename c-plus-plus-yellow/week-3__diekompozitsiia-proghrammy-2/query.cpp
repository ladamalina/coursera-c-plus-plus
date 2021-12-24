#include <iostream>
#include <string>
#include <vector>
#include "query.h"

using namespace std;

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

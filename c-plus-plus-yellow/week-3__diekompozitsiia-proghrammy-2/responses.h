#pragma once
#include "map"
#include "string"
#include "vector"

using namespace std;

using SToList = map<string, vector<string>>;

struct BusesForStopResponse {
    bool stop_found;
    vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    bool bus_found;
    string bus;
    vector<string> stops;
    SToList stops_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    bool buses_found;
    SToList buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);

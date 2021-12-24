#pragma once
#include "map"
#include "string"
#include "vector"
#include "responses.h"

using namespace std;

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops);

    BusesForStopResponse GetBusesForStop(const string& stop) const;

    StopsForBusResponse GetStopsForBus(const string& bus) const;

    AllBusesResponse GetAllBuses() const;

private:
    SToList buses_to_stops;
    SToList stops_to_buses;
};

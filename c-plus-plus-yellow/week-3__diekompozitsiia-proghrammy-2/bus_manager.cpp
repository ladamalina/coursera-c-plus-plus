#include "vector"
#include "bus_manager.h"

using namespace std;


void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    buses_to_stops[bus] = stops;
    for (const string& stop : stops) {
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    if (stops_to_buses.count(stop) == 0) {
        return BusesForStopResponse{false, {}};
    }
    return BusesForStopResponse{true, stops_to_buses.at(stop)};
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    if (buses_to_stops.count(bus) == 0) {
        return StopsForBusResponse{false, "", {}};
    }
    StopsForBusResponse r{true, bus, buses_to_stops.at(bus)};
    for (const string& stop : buses_to_stops.at(bus)) {
        r.stops_to_buses[stop] = stops_to_buses.at(stop);
    }
    return r;
}

AllBusesResponse BusManager::GetAllBuses() const {
    if (buses_to_stops.empty()) {
        return AllBusesResponse{false, {}};
    }
    return AllBusesResponse{true, buses_to_stops};
}

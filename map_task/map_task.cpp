#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

template<typename BusName, typename StopName>
class BusSystem {
private:
    map<BusName, vector<StopName>> buses;
    map<StopName, vector<BusName>> stops;

public:
    void newBus(const BusName& bus, const vector<StopName>& route) {
        buses[bus] = route;
        for (const auto& stop : route) {
            stops[stop].push_back(bus);
        }
    }

    void busesForStop(const StopName& stop) const {
        auto it = stops.find(stop);
        if (it == stops.end()) {
            cout << "No stop" << endl;
            return;
        }
        const auto& busList = it->second;
        for (size_t i = 0; i < busList.size(); ++i) {
            if (i > 0) cout << " ";
            cout << busList[i];
        }
        cout << endl;
    }

    void stopsForBus(const BusName& bus) const {
        auto it = buses.find(bus);
        if (it == buses.end()) {
            cout << "No bus" << endl;
            return;
        }
        const auto& route = it->second;
        for (const auto& stop : route) {
            cout << "Stop " << stop << ": ";
            const auto& allBuses = stops.at(stop);
            vector<BusName> others;
            for (const auto& b : allBuses) {
                if (b != bus) others.push_back(b);
            }
            if (others.empty()) {
                cout << "no interchange";
            } else {
                for (size_t i = 0; i < others.size(); ++i) {
                    if (i > 0) cout << " ";
                    cout << others[i];
                }
            }
            cout << endl;
        }
    }

    void allBuses() const {
        if (buses.empty()) {
            cout << "No buses" << endl;
            return;
        }
        for (const auto& [bus, route] : buses) {
            cout << "Bus " << bus << ": ";
            for (size_t i = 0; i < route.size(); ++i) {
                if (i > 0) cout << " ";
                cout << route[i];
            }
            cout << endl;
        }
    }
};

template<typename BusName, typename StopName>
void processCommand(BusSystem<BusName, StopName>& system, const string& line) {
    istringstream iss(line);
    string command;
    iss >> command;

    if (command == "NEW_BUS") {
        BusName bus;
        int stopCount;
        iss >> bus >> stopCount;
        vector<StopName> route(stopCount);
        for (int i = 0; i < stopCount; ++i) {
            iss >> route[i];
        }
        system.newBus(bus, route);
    }
    else if (command == "BUSES_FOR_STOP") {
        StopName stop;
        iss >> stop;
        system.busesForStop(stop);
    }
    else if (command == "STOPS_FOR_BUS") {
        BusName bus;
        iss >> bus;
        system.stopsForBus(bus);
    }
    else if (command == "ALL_BUSES") {
        system.allBuses();
    }
}

int main() {
    BusSystem<string, string> system;
    int Q;
    cin >> Q;
    cin.ignore();
    for (int i = 0; i < Q; ++i) {
        string line;
        getline(cin, line);
        processCommand(system, line);
    }
    return 0;
}
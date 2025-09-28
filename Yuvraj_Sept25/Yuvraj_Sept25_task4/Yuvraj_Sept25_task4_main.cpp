#include <iostream>
#include "Yuvraj_Sept25_task4_Flight.h"

int main() {
    std::cout << "Air Traffic Control Simulator\n\n";

    Flight flight1("Delta", "DL123", "Boeing 737", "ATL", "LAX",
                   "10:00", "12:30", 0, 0, 0, FlightStatus::PARKED);

    Flight flight2("United", "UA456", "Airbus A320", "ORD", "JFK",
                   "11:15", "14:00", 0, 30, 90, FlightStatus::WAITING_TAKEOFF);

    Flight flight3("American", "AA789", "Boeing 777", "DFW", "LHR",
                   "18:45", "07:15", 35000, 500, 45, FlightStatus::CRUISING);

    std::cout << flight1.toString() << "\n";
    std::cout << flight2.toString() << "\n";
    std::cout << flight3.toString() << "\n";

    std::cout << "\n--- Simulating Air Traffic Control Instructions ---\n\n";

    flight1.changeSpeed(20);
    flight2.changeAltitude(10000);
    flight3.beginLandingApproach();
    flight3.changeAltitude(12000);

    std::cout << "\n--- Updated Flight Status ---\n\n";
    std::cout << flight1.toString() << "\n";
    std::cout << flight2.toString() << "\n";
    std::cout << flight3.toString() << "\n";

    return 0;
}

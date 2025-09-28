#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <iostream>

enum FlightStatus {
    PARKED,
    TAXIING,
    WAITING_TAKEOFF,
    TAKING_OFF,
    CLIMBING,
    CRUISING,
    DESCENDING,
    LANDING,
    AT_GATE,
    CHANGING_ALTITUDE,
    CHANGING_SPEED,
    CHANGING_DIRECTION
};


class Flight {
private:
    std::string airline;
    std::string flightNumber;
    std::string makeModel;
    std::string origin;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;

    int currentAltitude;
    int targetAltitude;
    int currentSpeed;
    int direction; // in degrees 0–359
    FlightStatus status;

public:
    Flight(const std::string& airline,
           const std::string& flightNumber,
           const std::string& makeModel,
           const std::string& origin,
           const std::string& destination,
           const std::string& departureTime,
           const std::string& arrivalTime,
           int currentAltitude = 0,
           int currentSpeed = 0,
           int direction = 0,
           FlightStatus status = FlightStatus::PARKED);

    // getters and setters
    std::string getAirline() const { return airline; }
    std::string getFlightNumber() const { return flightNumber; }
    int getAltitude() const { return currentAltitude; }
    int getSpeed() const { return currentSpeed; }
    FlightStatus getStatus() const { return status; }

    // behaviors
    void changeAltitude(int newAltitude);
    void changeSpeed(int newSpeed);
    void changeDirection(int newDirection);
    void beginLandingApproach();

    std::string toString() const;
};

#endif

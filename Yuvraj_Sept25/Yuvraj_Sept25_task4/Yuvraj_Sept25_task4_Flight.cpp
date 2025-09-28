#include "Yuvraj_Sept25_task4_Flight.h"

Flight::Flight(const std::string& airline,
               const std::string& flightNumber,
               const std::string& makeModel,
               const std::string& origin,
               const std::string& destination,
               const std::string& departureTime,
               const std::string& arrivalTime,
               int currentAltitude,
               int currentSpeed,
               int direction,
               FlightStatus status)
    : airline(airline), flightNumber(flightNumber), makeModel(makeModel),
      origin(origin), destination(destination), departureTime(departureTime),
      arrivalTime(arrivalTime), currentAltitude(currentAltitude),
      targetAltitude(currentAltitude), currentSpeed(currentSpeed),
      direction(direction), status(status) {}

void Flight::changeAltitude(int newAltitude) {
    std::cout << airline << " " << flightNumber
              << " changing altitude from " << currentAltitude
              << " to " << newAltitude << " feet.\n";
    status = FlightStatus::CHANGING_ALTITUDE;
    targetAltitude = newAltitude;
    currentAltitude = newAltitude; // assume instantaneous
}

void Flight::changeSpeed(int newSpeed) {
    std::cout << airline << " " << flightNumber
              << " changing speed from " << currentSpeed
              << " to " << newSpeed << " knots.\n";
    status = FlightStatus::CHANGING_SPEED;
    currentSpeed = newSpeed;
}

void Flight::changeDirection(int newDirection) {
    std::cout << airline << " " << flightNumber
              << " changing direction from " << direction
              << "° to " << newDirection << "°.\n";
    status = FlightStatus::CHANGING_DIRECTION;
    direction = newDirection % 360;
}

void Flight::beginLandingApproach() {
    std::cout << airline << " " << flightNumber
              << " beginning landing approach.\n";
    status = FlightStatus::LANDING;
    targetAltitude = 0;
}

std::string Flight::toString() const {
    std::string statusStr;
    switch(status) {
        case FlightStatus::PARKED: statusStr = "Parked at gate"; break;
        case FlightStatus::TAXIING: statusStr = "Taxiing"; break;
        case FlightStatus::WAITING_TAKEOFF: statusStr = "Waiting for takeoff"; break;
        case FlightStatus::TAKING_OFF: statusStr = "Taking off"; break;
        case FlightStatus::CLIMBING: statusStr = "Climbing"; break;
        case FlightStatus::CRUISING: statusStr = "Cruising"; break;
        case FlightStatus::DESCENDING: statusStr = "Descending"; break;
        case FlightStatus::LANDING: statusStr = "Landing"; break;
        case FlightStatus::AT_GATE: statusStr = "Arrived at gate"; break;
        case FlightStatus::CHANGING_ALTITUDE: statusStr = "Changing altitude"; break;
        case FlightStatus::CHANGING_SPEED: statusStr = "Changing speed"; break;
        case FlightStatus::CHANGING_DIRECTION: statusStr = "Changing direction"; break;
    }

    return airline + " " + flightNumber + " (" + makeModel + ") from " +
           origin + " to " + destination + "\nDeparture: " + departureTime +
           " | Arrival: " + arrivalTime +
           "\nStatus: " + statusStr +
           "\nAltitude: " + std::to_string(currentAltitude) +
           " ft | Speed: " + std::to_string(currentSpeed) +
           " knots | Direction: " + std::to_string(direction) + "°\n";
}

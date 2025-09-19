#include <iostream>
using namespace std;

class TrackedVehicle {
private:
    unsigned int vehicle_id;
    float speed;
    float distance;
    static float min_recorded_distance;
    static int vehicle_count;

public:
    TrackedVehicle(unsigned int id = 0, float s = 0.0f, float d = 0.0f)
        : vehicle_id(id), speed(s), distance(d) {
        if (vehicle_count == 0 || d < min_recorded_distance) {
            min_recorded_distance = d;
        }
        vehicle_count++;
    }

    void display() const {
        cout << "Vehicle ID: " << vehicle_id
             << ", Speed: " << speed << " km/h"
             << ", Distance: " << distance << " m" << endl;
    }

    const TrackedVehicle* compareDistance(const TrackedVehicle& other) const {
        if (this->distance <= other.distance) return this;
        return &other;
    }

    static float getMinRecordedDistance() { return min_recorded_distance; }
    static int getVehicleCount() { return vehicle_count; }

    float getDistance() const { return distance; }
    unsigned int getId() const { return vehicle_id; }
};

// static members init
float TrackedVehicle::min_recorded_distance = 0;
int TrackedVehicle::vehicle_count = 0;

// Global functions
void printTrackedVehicle(const TrackedVehicle& v) { v.display(); }

void findLeadVehicle(TrackedVehicle* arr, unsigned int size, const TrackedVehicle*& lead) {
    if (size == 0) { lead = nullptr; return; }
    lead = &arr[0];
    for (unsigned int i = 1; i < size; i++) {
        if (arr[i].getDistance() < lead->getDistance())
            lead = &arr[i];
    }
}

void printLeadVehicle(const TrackedVehicle* lead) {
    if (lead) {
        cout << "Lead Vehicle -> ";
        lead->display();
    } else {
        cout << "No lead vehicle found.\n";
    }
}

int main() {
    TrackedVehicle* arr = new TrackedVehicle[4] {
        TrackedVehicle(501, 80, 60),
        TrackedVehicle(502, 78, 45),
        TrackedVehicle(503, 85, 100),
        TrackedVehicle(504, 76, 40)
    };

    const TrackedVehicle* lead = nullptr;
    findLeadVehicle(arr, 4, lead);

    cout << "All Tracked Vehicles:\n";
    for (int i = 0; i < 4; i++) printTrackedVehicle(arr[i]);

    printLeadVehicle(lead);

    cout << "Minimum recorded distance: " << TrackedVehicle::getMinRecordedDistance() << " m\n";
    cout << "Total vehicles created: " << TrackedVehicle::getVehicleCount() << endl;

    delete[] arr;
    return 0;
}

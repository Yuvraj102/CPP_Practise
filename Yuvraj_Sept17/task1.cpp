#include <iostream>
using namespace std;

class Pedestrian {
private:
    unsigned int pedestrian_id;
    float distance_from_vehicle;

public:
    Pedestrian(unsigned int id = 0, float d = 0.0f)
        : pedestrian_id(id), distance_from_vehicle(d) {}

    void updateDistance(float newDistance) { distance_from_vehicle = newDistance; }
    float getDistance() const { return distance_from_vehicle; }
    unsigned int getId() const { return pedestrian_id; }
};

// Global functions
void printPedestrianInfo(const Pedestrian& ped) {
    cout << "Pedestrian ID: " << ped.getId()
         << ", Distance: " << ped.getDistance() << " m" << endl;
}

void findClosestPedestrian(Pedestrian* array, unsigned int size, const Pedestrian*& closest) {
    if (size == 0) { closest = nullptr; return; }
    closest = &array[0];
    for (unsigned int i = 1; i < size; i++) {
        if (array[i].getDistance() < closest->getDistance()) {
            closest = &array[i];
        }
    }
}

void printClosestPedestrian(const Pedestrian* closest) {
    if (closest)
        cout << "Closest Pedestrian -> ID: " << closest->getId()
             << ", Distance: " << closest->getDistance() << " m" << endl;
    else
        cout << "No pedestrian found.\n";
}

int main() {
    Pedestrian* arr = new Pedestrian[3] {
        Pedestrian(101, 12.4f),
        Pedestrian(102, 8.7f),
        Pedestrian(103, 15.1f)
    };

    const Pedestrian* closest = nullptr;
    findClosestPedestrian(arr, 3, closest);

    cout << "All Pedestrians:\n";
    for (int i = 0; i < 3; i++) printPedestrianInfo(arr[i]);

    printClosestPedestrian(closest);

    delete[] arr;
    return 0;
}

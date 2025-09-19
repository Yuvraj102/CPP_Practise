#include <iostream>
using namespace std;

class TemperatureSensor {
private:
    unsigned int sensor_id;
    float readings[5];

public:
    TemperatureSensor(unsigned int id = 0) : sensor_id(id) {
        for (int i = 0; i < 5; i++) readings[i] = 0.0f;
    }

    void setReading(int index, float value) {
        if (index >= 0 && index < 5) readings[index] = value;
    }

    float getReading(int index) const {
        if (index >= 0 && index < 5) return readings[index];
        return 0.0f;
    }

    float calculateAverage() const {
        float sum = 0;
        for (int i = 0; i < 5; i++) sum += readings[i];
        return sum / 5.0f;
    }

    unsigned int getId() const { return sensor_id; }

    void display() const {
        cout << "Sensor ID: " << sensor_id << ", Readings: ";
        for (int i = 0; i < 5; i++) cout << readings[i] << " ";
        cout << " | Avg: " << calculateAverage() << endl;
    }
};

// Global functions
void printTemperatureSensor(const TemperatureSensor& s) { s.display(); }

const TemperatureSensor* findHottestSensor(const TemperatureSensor* arr, unsigned int size) {
    if (size == 0) return nullptr;
    const TemperatureSensor* hottest = &arr[0];
    for (unsigned int i = 1; i < size; i++) {
        if (arr[i].calculateAverage() > hottest->calculateAverage())
            hottest = &arr[i];
    }
    return hottest;
}

int main() {
    TemperatureSensor arr[3] = {
        TemperatureSensor(201),
        TemperatureSensor(202),
        TemperatureSensor(203)
    };

    // sample readings
    float r1[5] = {32.5, 34.0, 33.8, 35.1, 34.6};
    float r2[5] = {28.0, 29.5, 30.0, 29.8, 30.2};
    float r3[5] = {36.0, 35.8, 36.5, 37.1, 36.9};

    for (int i = 0; i < 5; i++) {
        arr[0].setReading(i, r1[i]);
        arr[1].setReading(i, r2[i]);
        arr[2].setReading(i, r3[i]);
    }

    cout << "All Sensors:\n";
    for (int i = 0; i < 3; i++) printTemperatureSensor(arr[i]);

    const TemperatureSensor* hottest = findHottestSensor(arr, 3);
    if (hottest) {
        cout << "Hottest Sensor is ID: " << hottest->getId()
             << " with avg temp " << hottest->calculateAverage() << endl;
    }

    return 0;
}

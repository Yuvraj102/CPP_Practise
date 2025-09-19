#include <iostream>
using namespace std;

class EgoVehicleData {
private:
    int num_lanes;
    float* lane_positions;
    float* sensor_confidence;

public:
    EgoVehicleData(int n, const float* lp, const float* sc) {
        num_lanes = n;
        lane_positions = new float[num_lanes];
        sensor_confidence = new float[num_lanes];
        for (int i = 0; i < num_lanes; i++) {
            lane_positions[i] = lp[i];
            sensor_confidence[i] = sc[i];
        }
    }

    ~EgoVehicleData() {
        delete[] lane_positions;
        delete[] sensor_confidence;
    }

    float getAverageLanePosition() const {
        float sum = 0;
        for (int i = 0; i < num_lanes; i++) sum += lane_positions[i];
        return sum / num_lanes;
    }

    void updateSensorConfidence(float factor) {
        for (int i = 0; i < num_lanes; i++) sensor_confidence[i] *= factor;
    }

    float totalConfidence() const {
        float sum = 0;
        for (int i = 0; i < num_lanes; i++) sum += sensor_confidence[i];
        return sum;
    }

    void print() const {
        cout << "Lane Positions: ";
        for (int i = 0; i < num_lanes; i++) cout << lane_positions[i] << " ";
        cout << "\nConfidences: ";
        for (int i = 0; i < num_lanes; i++) cout << sensor_confidence[i] << " ";
        cout << "\nAvg Lane Pos: " << getAverageLanePosition() << ", Total Confidence: " << totalConfidence() << "\n";
    }
};

// Globals
void printEgoVehicleData(const EgoVehicleData& d) { d.print(); }

void findHighestConfidenceVehicle(EgoVehicleData* arr, int size, const EgoVehicleData*& highest) {
    if (size == 0) { highest = nullptr; return; }
    highest = &arr[0];
    for (int i = 1; i < size; i++) if (arr[i].totalConfidence() > highest->totalConfidence()) highest = &arr[i];
}

void printHighestConfidenceVehicle(const EgoVehicleData* v) {
    if (!v) cout << "No vehicle.\n"; else v->print();
}

int main() {
    float lp1[3] = {3.2f, 3.0f, 3.4f};
    float sc1[3] = {0.95f, 0.97f, 0.93f};
    EgoVehicleData v1(3, lp1, sc1);

    float lp2[3] = {2.9f, 2.8f, 3.1f};
    float sc2[3] = {0.92f, 0.90f, 0.88f};
    EgoVehicleData v2(3, lp2, sc2);

    float lp3[3] = {3.4f, 3.5f, 3.6f};
    float sc3[3] = {0.99f, 0.98f, 0.97f};
    EgoVehicleData v3(3, lp3, sc3);

    EgoVehicleData arr[3] = {v1, v2, v3};

    arr[0].updateSensorConfidence(1.1f);
    arr[1].updateSensorConfidence(1.05f);
    arr[2].updateSensorConfidence(1.2f);

    const EgoVehicleData* best = nullptr;
    findHighestConfidenceVehicle(arr, 3, best);

    cout << "Vehicles:\n";
    for (int i = 0; i < 3; i++) printEgoVehicleData(arr[i]);

    cout << "\nHighest Confidence Vehicle:\n";
    printHighestConfidenceVehicle(best);
    return 0;
}

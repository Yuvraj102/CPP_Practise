#include <iostream>
using namespace std; 

class VehicleStatus {
private:
    int num_wheels;
    float* wheel_speed;
    int num_temps;
    float* engine_temp;

public:
    VehicleStatus(int nw, const float* ws, int nt, const float* et) {
        num_wheels = nw;
        wheel_speed = new float[num_wheels];
        for (int i = 0; i < num_wheels; i++) wheel_speed[i] = ws[i];

        num_temps = nt;
        engine_temp = new float[num_temps];
        for (int i = 0; i < num_temps; i++) engine_temp[i] = et[i];
    }

    ~VehicleStatus() {
        delete[] wheel_speed;
        delete[] engine_temp;
    }

    float averageWheelSpeed() const {
        float sum = 0;
        for (int i = 0; i < num_wheels; i++) {sum += wheel_speed[i];}
        return (sum / num_wheels);
    }

    float maxEngineTemp() const {
        float maxT = engine_temp[0];
        for (int i = 1; i < num_temps; i++)
            if (engine_temp[i] > maxT) maxT = engine_temp[i];
        return maxT;
    }

bool isWheelSpeedHigher(const VehicleStatus& other) const {
    float max1 = wheel_speed[0];
    for (int i = 1; i < num_wheels; i++)
        if (wheel_speed[i] > max1) max1 = wheel_speed[i];

    float max2 = other.wheel_speed[0];
    for (int i = 1; i < other.num_wheels; i++)
        if (other.wheel_speed[i] > max2) max2 = other.wheel_speed[i];

    return max1 > max2;
}


    void print() const {
        cout << "Wheel Speeds: ";
        for (int i = 0; i < num_wheels; i++) cout << wheel_speed[i] << " ";
        cout << "\nEngine Temps: ";
        for (int i = 0; i < num_temps; i++) cout << engine_temp[i] << " ";
        cout << "\nAvg Wheel Speed: " << averageWheelSpeed()
             << ", Max Engine Temp: " << maxEngineTemp() << "\n";
    }
};

// Global
void printVehicleStatus(const VehicleStatus& vs) { vs.print(); }

bool compareWheelSpeedGlobal(const VehicleStatus& v1, const VehicleStatus& v2) {
    return v1.isWheelSpeedHigher(v2);
}

int main() {
    float ws1[4] = {55.5f, 56.6f, 57.2f, 55.9f};
    float et1[2] = {90.5f, 88.9f};
    VehicleStatus v1(4, ws1, 2, et1);

    float ws2[4] = {50.0f, 51.2f, 49.8f, 50.4f};
    float et2[2] = {92.0f, 89.5f};
    VehicleStatus v2(4, ws2, 2, et2);

    std::cout << "Vehicle 1:\n"; printVehicleStatus(v1);
    std::cout << "Vehicle 2:\n"; printVehicleStatus(v2);

    std::cout << "Member comparison: " << (v1.isWheelSpeedHigher(v2) ? "V1 faster" : "V2 faster") << endl;
    std::cout << "Global comparison: " << (compareWheelSpeedGlobal(v1, v2) ? "V1 faster" : "V2 faster") << endl;
    return 0;
}

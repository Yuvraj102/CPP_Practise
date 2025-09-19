#include <iostream>
#include <string>
using namespace std;

enum SatelliteStatus { OPERATIONAL, MAINTENANCE, DECOMMISSIONED };

class SatelliteData {
private:
    int satellite_id;
    int num_antennas;
    float* signal_strength;
    float orbital_altitude;
    SatelliteStatus status;
    static int active_satellites;

public:
    SatelliteData(int id, int n, const float* sig, float alt, SatelliteStatus st) {
        satellite_id = id;
        num_antennas = n;
        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; i++) signal_strength[i] = sig[i];
        orbital_altitude = alt;
        status = st;
        active_satellites++;
    }

    SatelliteData(const SatelliteData& other) {
        satellite_id = other.satellite_id;
        num_antennas = other.num_antennas;
        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; i++) signal_strength[i] = other.signal_strength[i];
        orbital_altitude = other.orbital_altitude;
        status = other.status;
        active_satellites++;
    }

    ~SatelliteData() {
        delete[] signal_strength;
        active_satellites--;
    }

    float getAverageSignalStrength() const {
        float sum = 0;
        for (int i = 0; i < num_antennas; i++) sum += signal_strength[i];
        return sum / num_antennas;
    }

    void boostSignal(float factor) {
        for (int i = 0; i < num_antennas; i++) signal_strength[i] *= factor;
    }

    void boostSignal(float factor, float threshold) {
        for (int i = 0; i < num_antennas; i++)
            if (signal_strength[i] < threshold) signal_strength[i] *= factor;
    }

    static int getActiveSatelliteCount() { return active_satellites; }

    void setStatus(SatelliteStatus st) { status = st; }

    string getStatusString() const {
        switch (status) {
            case OPERATIONAL: return "Operational";
            case MAINTENANCE: return "Maintenance";
            case DECOMMISSIONED: return "Decommissioned";
        }
        return "Unknown";
    }

    void print() const {
        cout << "Satellite ID: " << satellite_id << ", Altitude: " << orbital_altitude
             << ", Status: " << getStatusString() << "\nSignals: ";
        for (int i = 0; i < num_antennas; i++) cout << signal_strength[i] << " ";
        cout << " | Avg Signal: " << getAverageSignalStrength() << endl;
    }
};
int SatelliteData::active_satellites = 0;

// Globals
void printSatelliteData(const SatelliteData& sd) { sd.print(); }

bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2) {
    return s1.getAverageSignalStrength() > s2.getAverageSignalStrength();
}

void cloneSatellite(const SatelliteData& source, SatelliteData*& target) {
    target = new SatelliteData(source);
}

void printActiveSatelliteCount() {
    cout << "Active satellites: " << SatelliteData::getActiveSatelliteCount() << endl;
}

void updateStatusIfWeak(SatelliteData& sd, float threshold) {
    if (sd.getAverageSignalStrength() < threshold) sd.setStatus(MAINTENANCE);
}

int main() {
    float s1[3] = {78.5f, 80.2f, 79.0f};
    SatelliteData sat1(101, 3, s1, 550.0f, OPERATIONAL);

    float s2[2] = {75.0f, 76.5f};
    SatelliteData sat2(102, 2, s2, 600.0f, MAINTENANCE);

    sat1.boostSignal(1.05f);
    sat2.boostSignal(1.1f, 76.0f);

    cout << "Satellites:\n";
    printSatelliteData(sat1);
    printSatelliteData(sat2);

    SatelliteData* satClone = nullptr;
    cloneSatellite(sat1, satClone);
    cout << "Cloned Satellite:\n"; printSatelliteData(*satClone);

    updateStatusIfWeak(sat2, 77.0f);

    printActiveSatelliteCount();

    delete satClone;
    printActiveSatelliteCount();

    return 0;
}

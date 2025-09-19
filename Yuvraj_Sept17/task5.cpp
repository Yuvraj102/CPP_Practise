#include <iostream>
using namespace std;

class Parcel {
private:
    unsigned int parcel_id;
    float weight;

public:
    Parcel(unsigned int id = 0, float w = 0.0f)
        : parcel_id(id), weight(w) {}

    unsigned int getId() const { return parcel_id; }
    float getWeight() const { return weight; }
    void setWeight(float w) { weight = w; }

    void display() const {
        cout << "Parcel ID: " << parcel_id
             << ", Weight: " << weight << " kg" << endl;
    }
};

// Global functions
void printParcel(const Parcel& p) { p.display(); }

const Parcel* findHeaviestParcel(const Parcel* arr, unsigned int size) {
    if (size == 0) return nullptr;
    const Parcel* heavy = &arr[0];
    for (unsigned int i = 1; i < size; i++) {
        if (arr[i].getWeight() > heavy->getWeight())
            heavy = &arr[i];
    }
    return heavy;
}

float calculateAverageWeight(const Parcel* arr, unsigned int size) {
    if (size == 0) return 0.0f;
    float sum = 0;
    for (unsigned int i = 0; i < size; i++) sum += arr[i].getWeight();
    return sum / size;
}

int main() {
    Parcel arr[4] = {
        Parcel(301, 12.5f),
        Parcel(302, 8.3f),
        Parcel(303, 15.7f),
        Parcel(304, 10.0f)
    };

    cout << "All Parcels:\n";
    for (int i = 0; i < 4; i++) printParcel(arr[i]);

    const Parcel* heavy = findHeaviestParcel(arr, 4);
    if (heavy) {
        cout << "Heaviest Parcel -> ID: " << heavy->getId()
             << " with weight " << heavy->getWeight() << " kg" << endl;
    }

    float avg = calculateAverageWeight(arr, 4);
    cout << "Average Parcel Weight: " << avg << " kg" << endl;

    return 0;
}

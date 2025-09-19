#include <iostream>
using namespace std;

class ObjectDistance {
private:
    float radar_distance;
    float camera_distance;

public:
    ObjectDistance(float r, float c) : radar_distance(r), camera_distance(c) {}

    void adjustDistancesByValue(ObjectDistance obj) {
        obj.radar_distance += 5.0f;
        obj.camera_distance += 5.0f;
        cout << "[Inside adjustByValue] Radar: " << obj.radar_distance
             << ", Camera: " << obj.camera_distance << endl;
    }

    void adjustDistancesByReference(ObjectDistance& obj) {
        obj.radar_distance += 5.0f;
        obj.camera_distance += 5.0f;
    }

    float getRadar() const { return radar_distance; }
    float getCamera() const { return camera_distance; }
};

// Global functions
void printObjectDistance(const ObjectDistance& obj) {
    cout << "Radar: " << obj.getRadar() << ", Camera: " << obj.getCamera() << endl;
}

ObjectDistance* createObjectDistanceOnHeap(float radar, float camera) {
    return new ObjectDistance(radar, camera);
}

int main() {
    ObjectDistance* obj = createObjectDistanceOnHeap(35.5f, 34.8f);

    cout << "Before adjustment: ";
    printObjectDistance(*obj);

    obj->adjustDistancesByValue(*obj); 
    cout << "After adjustByValue: ";
    printObjectDistance(*obj);

    obj->adjustDistancesByReference(*obj); // affcs original
    cout << "After adjustByReference: ";
    printObjectDistance(*obj);

    delete obj;
    return 0;
}

#include <iostream>
using namespace std;

class DetectedObject {
private:
    unsigned int object_id;
    float rel_speed;
    float distance;

public:
    DetectedObject(unsigned int id = 0, float rs = 0.0f, float d = 0.0f)
        : object_id(id), rel_speed(rs), distance(d) {}

    void display() const {
        cout << "Object ID: " << object_id
             << ", RelSpeed: " << rel_speed
             << ", Distance: " << distance << endl;
    }

    bool isHigherRisk(const DetectedObject& other) const {
        return (this->distance < other.distance && this->rel_speed > other.rel_speed);
    }

    void updateValuesByValue(DetectedObject obj) {
        obj.rel_speed += 2;
        obj.distance -= 5;
        cout << "[Inside updateByValue] RelSpeed: " << obj.rel_speed
             << ", Distance: " << obj.distance << endl;
    }

    void updateValuesByReference(DetectedObject& obj) {
        obj.rel_speed += 2;
        obj.distance -= 5;
    }

    float getRelSpeed() const { return rel_speed; }
    float getDistance() const { return distance; }
    unsigned int getId() const { return object_id; }
};

// Global functions
void printDetectedObject(const DetectedObject& obj) { obj.display(); }

void printHighestRiskObject(const DetectedObject* obj) {
    if (obj) {
        cout << "Highest Risk Object -> ";
        obj->display();
    } else {
        cout << "No risk object found.\n";
    }
}

void updateObjectValuesByValueGlobal(DetectedObject obj) {
    obj.updateValuesByValue(obj);
}

void updateObjectValuesByReferenceGlobal(DetectedObject& obj) {
    obj.updateValuesByReference(obj);
}

void findHighestRiskObject(DetectedObject* arr, unsigned int size, const DetectedObject*& riskObj) {
    if (size == 0) { riskObj = nullptr; return; }
    riskObj = &arr[0];
    for (unsigned int i = 1; i < size; i++) {
        if (arr[i].isHigherRisk(*riskObj)) {
            riskObj = &arr[i];
        }
    }
}

int main() {
    DetectedObject* arr = new DetectedObject[3] {
        DetectedObject(701, 15, 55),
        DetectedObject(702, 20, 35),
        DetectedObject(703, 10, 30)
    };

    cout << "All Objects:\n";
    for (int i = 0; i < 3; i++) printDetectedObject(arr[i]);

    cout << "\n--- Update Tests ---\n";
    updateObjectValuesByValueGlobal(arr[0]);
    updateObjectValuesByReferenceGlobal(arr[1]);
    cout << "After updateByReference on Object 2:\n";
    printDetectedObject(arr[1]);

    const DetectedObject* riskObj = nullptr;
    findHighestRiskObject(arr, 3, riskObj);
    printHighestRiskObject(riskObj);

    delete[] arr;
    return 0;
}

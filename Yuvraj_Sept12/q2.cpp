#include<bits/stdc++.h>


class Sensor {
private:
    int id;
    float value;
    int priority;
    std::string status;

public:

    Sensor(int _id, float _value, int _priority)
        : id(_id), value(_value), priority(_priority), status("OK") {}

    
    void updateValue(float v) {
        value = v;
        status = "Updated";
    }

    
    int getId() const { return id; }
    float getValue() const { return value; }
    int getPriority() const { return priority; }
    std::string getStatus() const { return status; }
};


void rebindCriticalSensor(Sensor*& ref, Sensor* list[], int size) {
    if (size <= 0) {
        ref = nullptr;
        return;
    }
    
    Sensor* highestPrioritySensor = list[0];
    for (int i = 1; i < size; ++i) {
        if (list[i] != nullptr && list[i]->getPriority() > highestPrioritySensor->getPriority()) {
            highestPrioritySensor = list[i];
        }
    }
    
    ref = highestPrioritySensor;
    std::cout << "Global Function: Critical sensor re-bound to ID " << ref->getId() << " (Priority: " << ref->getPriority() << ")." << std::endl;
}


void printSensorMap(Sensor* list[], int size) {
    std::cout << "\n--- Sensor Grid Map ---" << std::endl;
    for (int i = 0; i < size; ++i) {
        if (list[i] != nullptr) {
            std::cout << "Sensor ID: " << list[i]->getId()
                      << ", Value: " << list[i]->getValue()
                      << ", Priority: " << list[i]->getPriority()
                      << ", Status: " << list[i]->getStatus() << std::endl;
        }
    }
    std::cout << "-----------------------" << std::endl;
}


class SensorDiagnostics {
public:
    
    std::string checkHealth(Sensor& s) {
        if (s.getValue() > 90.0) {
            return "Health: Critical";
        } else if (s.getValue() > 70.0) {
            return "Health: Warning";
        } else {
            return "Health: OK";
        }
    }
};


class Controller {
private:
    
    Sensor* sensorList[10];
    int listSize;

    
    Sensor& criticalSensor;

public:
    
    Controller(Sensor* firstSensor) : criticalSensor(*firstSensor) {
        for (int i = 0; i < 10; ++i) {
            sensorList[i] = nullptr;
        }
        listSize = 0;
    }

    
    void addSensor(Sensor* s) {
        if (listSize < 10) {
            sensorList[listSize++] = s;
        }
    }

    
    void bindCriticalSensor() {
        if (listSize == 0) return;

        Sensor* highestPrioritySensor = sensorList[0];
        for (int i = 1; i < listSize; ++i) {
            if (sensorList[i] != nullptr && sensorList[i]->getPriority() > highestPrioritySensor->getPriority()) {
                highestPrioritySensor = sensorList[i];
            }
        }
        
    }
};


class ControllerWithPointer {
private:
    Sensor* sensorList[10];
    int listSize;
    Sensor* criticalSensor;

public:
    ControllerWithPointer() : listSize(0), criticalSensor(nullptr) {}

    void addSensor(Sensor* s) {
        if (listSize < 10) {
            sensorList[listSize++] = s;
        }
    }

    // Find and bind the highest priority sensor
    void bindCriticalSensor() {
        if (listSize == 0) {
            criticalSensor = nullptr;
            return;
        }
        Sensor* highestPrioritySensor = sensorList[0];
        for (int i = 1; i < listSize; ++i) {
            if (sensorList[i] != nullptr && sensorList[i]->getPriority() > highestPrioritySensor->getPriority()) {
                highestPrioritySensor = sensorList[i];
            }
        }
        criticalSensor = highestPrioritySensor;
        std::cout << "Controller: Critical sensor bound to ID " << criticalSensor->getId() << "." << std::endl;
    }
    
    
    Sensor* getCriticalSensor() const {
        return criticalSensor;
    }

    Sensor** getSensorList() {
        return sensorList;
    }
    
    int getListSize() const {
        return listSize;
    }

    // Update the critical sensor using the global function
    void updateCriticalSensor() {
        rebindCriticalSensor(criticalSensor, sensorList, listSize);
    }

    void printStatus() {
        if (criticalSensor) {
            std::cout << "\n--- Controller Status ---" << std::endl;
            std::cout << "Critical Sensor ID: " << criticalSensor->getId() << std::endl;
            std::cout << "Value: " << criticalSensor->getValue() << std::endl;
            std::cout << "Health: " << SensorDiagnostics().checkHealth(*criticalSensor) << std::endl;
        } else {
            std::cout << "Controller Status: No critical sensor bound." << std::endl;
        }
    }

    
    ~ControllerWithPointer() {
        for (int i = 0; i < listSize; ++i) {
            delete sensorList[i];
        }
    }
};


int main() {
    
    ControllerWithPointer controller;
    controller.addSensor(new Sensor(1, 75.0, 3));
    controller.addSensor(new Sensor(2, 60.0, 5));
    controller.addSensor(new Sensor(3, 90.0, 2));
    controller.addSensor(new Sensor(4, 45.0, 8)); // Highest priority initially
    controller.addSensor(new Sensor(5, 80.0, 1));

    
    printSensorMap(controller.getSensorList(), controller.getListSize());

    
    controller.bindCriticalSensor();
    controller.printStatus();

    // Modify a sensor's value via the critical sensor reference and observe changes
    std::cout << "\n--- Modifying sensor 4's value indirectly ---" << std::endl;
    Sensor* tempCritical = controller.getCriticalSensor();
    if (tempCritical) {
        tempCritical->updateValue(105.0);
        controller.printStatus();
        std::cout << "Health check on critical sensor: " << SensorDiagnostics().checkHealth(*tempCritical) << std::endl;
    }

    
    std::cout << "\n--- Updating critical sensor via global function ---" << std::endl;
    
    controller.addSensor(new Sensor(6, 65.0, 10)); // New highest priority
    controller.updateCriticalSensor();
    controller.printStatus();

    
    printSensorMap(controller.getSensorList(), controller.getListSize());

    return 0;
}

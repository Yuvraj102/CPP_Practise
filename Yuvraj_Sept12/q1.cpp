
#include<bits/stdc++.h>


class Sensor {
protected:
    int id;
    float value;
    float threshold;
    std::string status;

public:
    
    Sensor(int _id, float _value, float _threshold)
        : id(_id), value(_value), threshold(_threshold), status("Normal") {}

    
    virtual void simulateFault() = 0;

    
    bool isFaulty() {
        return value > threshold;
    }

    
    int getId() const { return id; }
    float getValue() const { return value; }
    float getThreshold() const { return threshold; }
    std::string getStatus() const { return status; }

    
    void setThreshold(float newThreshold) {
        threshold = newThreshold;
    }

    
    virtual ~Sensor() {}
};


class TemperatureSensor : public Sensor {
public:
    TemperatureSensor(int _id, float _value, float _threshold)
        : Sensor(_id, _value, _threshold) {}

    
    void simulateFault() override {
        value = 150.5; 
        status = "Faulty - High Temp";
        std::cout << "Temperature Sensor " << id << " fault injected. New value: " << value << std::endl;
    }
};


class PressureSensor : public Sensor {
public:
    PressureSensor(int _id, float _value, float _threshold)
        : Sensor(_id, _value, _threshold) {}

    
    void simulateFault() override {
        value = -10.0;  // negt value
        status = "Faulty - Low Pressure";
        std::cout << "Pressure Sensor " << id << " fault injected. New value: " << value << std::endl;
    }
};


class Actuator {
private:
    int id;
    std::string state;
    int responseTime;

public:
    
    Actuator(int _id, std::string _state, int _responseTime)
        : id(_id), state(_state), responseTime(_responseTime) {}

    
    void triggerAction() {
        std::cout << "Actuator " << id << " is now " << state << "." << std::endl;
    }

    
    void setResponseTime(int newTime) {
        responseTime = newTime;
    }

    
    int getId() const { return id; }
    std::string getState() const { return state; }
    int getResponseTime() const { return responseTime; }
};


class ConfigManager {
public:
    
    void updateThreshold(Sensor& s, float newThreshold) {
        s.setThreshold(newThreshold);
        std::cout << "ConfigManager: Sensor " << s.getId() << " threshold updated to " << newThreshold << "." << std::endl;
    }
};


class FaultInjector {
private:
    std::vector<Sensor*> sensors;
    std::vector<Actuator*> actuators;

public:
    
    void addSensor(Sensor* s) {
        sensors.push_back(s);
    }

    
    void addActuator(Actuator* a) {
        actuators.push_back(a);
    }

    
    Sensor* getSensor(size_t index) {
        if (index < sensors.size()) {
            return sensors[index];
        }
        return nullptr;
    }

    
    Actuator* getActuator(size_t index) {
        if (index < actuators.size()) {
            return actuators[index];
        }
        return nullptr;
    }

    
    void injectSensorFault(Sensor* s) {
        s->simulateFault();
    }

    
    void injectActuatorDelay(Actuator& a) {
        a.setResponseTime(300); 
        std::cout << "FaultInjector: Actuator " << a.getId() << " delayed. New response time: " << a.getResponseTime() << "ms." << std::endl;
    }

    
    void injectAllFaults() {
        for (Sensor* s : sensors) {
            if (s->isFaulty()) {
                s->simulateFault();
            }
        }
    }

    
    void reportStatus() {
        std::cout << "\n--- System Status Report ---" << std::endl;
        for (const auto& s : sensors) {
            std::cout << "Sensor " << s->getId() << ": Value=" << s->getValue()
                      << ", Status: " << s->getStatus() << std::endl;
        }
        for (const auto& a : actuators) {
            std::cout << "Actuator " << a->getId() << ": State=" << a->getState()
                      << ", Response Time: " << a->getResponseTime() << "ms" << std::endl;
        }
        std::cout << "--------------------------" << std::endl;
    }

    
    ~FaultInjector() {
        for (auto s : sensors) {
            delete s;
        }
        for (auto a : actuators) {
            delete a;
        }
    }
};


void logFault(Sensor* s) {
    if (s && s->isFaulty()) {
        std::cout << "Global Log: Fault detected on Sensor " << s->getId() << "." << std::endl;
    }
}


void analyzeSystem(FaultInjector* fi) {
    if (fi) {
        std::cout << "\nGlobal Analysis: Running system check..." << std::endl;
        fi->reportStatus();
        std::cout << "Analysis complete." << std::endl;
    }
}

int main() {
    
    ConfigManager* config = new ConfigManager();
    FaultInjector* injector = new FaultInjector();

    
    injector->addSensor(new TemperatureSensor(101, 95.0, 90.0));
    injector->addSensor(new PressureSensor(102, 45.0, 50.0));
    injector->addSensor(new TemperatureSensor(103, 70.0, 80.0));
    injector->addActuator(new Actuator(201, "Idle", 120));
    injector->addActuator(new Actuator(202, "Off", 90));

    
    


    injector->reportStatus();

    
    
    Sensor* sensor0 = injector->getSensor(0);
    if (sensor0) {
        config->updateThreshold(*sensor0, 100.0);
    }
    injector->reportStatus();

    
    std::cout << "\n--- Injecting sensor fault ---" << std::endl;
    Sensor* pressureSensor = injector->getSensor(1);
    if (pressureSensor) {
        injector->injectSensorFault(pressureSensor); 
        if (pressureSensor->isFaulty()) {
            logFault(pressureSensor);
        }
    }
    injector->reportStatus();

    
    std::cout << "\n--- Injecting actuator delay via reference ---" << std::endl;
    Actuator* actuator = injector->getActuator(0);
    if (actuator) {
        injector->injectActuatorDelay(*actuator);
        actuator->triggerAction();
    }
    injector->reportStatus();

    
    std::cout << "\n--- Running global system analysis ---" << std::endl;
    analyzeSystem(injector);

    //cleanup
    delete config;
    delete injector;

    std::cout << "\n--- Simulation ended, memory cleaned up. ---" << std::endl;
    return 0;
}

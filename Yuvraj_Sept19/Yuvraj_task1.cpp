#include <iostream>
#include <string>

using namespace std;


class ServiceRecord {
private:
    string date_;
    int mileage_;
    string description_;

public:
    // Default constructor
    ServiceRecord() : date_(""), mileage_(0), description_("") {}

    // Full initializer
    ServiceRecord(const string& date, int mileage, const string& desc)
        : date_(date), mileage_(0), description_(desc) {
        if (mileage < 0) throw invalid_argument("Mileage cannot be negative.");
        mileage_ = mileage;
    }

    // Copy constructor
    ServiceRecord(const ServiceRecord& other)
        : date_(other.date_), mileage_(other.mileage_), description_(other.description_) {}

    // Assignment
    ServiceRecord& operator=(const ServiceRecord& other) {
        if (this != &other) {
            date_ = other.date_;
            mileage_ = other.mileage_;
            description_ = other.description_;
        }
        return *this;
    }

    // Getters
    const string& getDate() const { return date_; }
    int getMileage() const { return mileage_; }
    const string& getDescription() const { return description_; }

    // Print
    void print() const {
        cout << date_ << " | " << mileage_ << " km | " << description_ << endl;
    }
};


class Car {
private:
    string vin_;
    string make_;
    string model_;
    double price_;

    ServiceRecord* serviceHistory_;
    size_t serviceCount_;
    size_t serviceCap_;

    int* damageCodes_;
    size_t damageCount_;
    size_t damageCap_;

    static size_t totalCars_;

    void reserveService(size_t newCap) {
        if (newCap <= serviceCap_) return;
        ServiceRecord* newArr = new ServiceRecord[newCap];
        for (size_t i = 0; i < serviceCount_; i++) newArr[i] = serviceHistory_[i];
        delete[] serviceHistory_;
        serviceHistory_ = newArr;
        serviceCap_ = newCap;
    }

    void reserveDamage(size_t newCap) {
        if (newCap <= damageCap_) return;
        int* newArr = new int[newCap];
        for (size_t i = 0; i < damageCount_; i++) newArr[i] = damageCodes_[i];
        delete[] damageCodes_;
        damageCodes_ = newArr;
        damageCap_ = newCap;
    }

public:
    // Default constructor
    Car()
        : vin_(""), make_(""), model_(""), price_(0.0),
          serviceHistory_(nullptr), serviceCount_(0), serviceCap_(0),
          damageCodes_(nullptr), damageCount_(0), damageCap_(0) {
        totalCars_++;
    }

    // Param constructor
    Car(const string& vin, const string& make, const string& model, double price)
        : vin_(vin), make_(make), model_(model), price_(0.0),
          serviceHistory_(nullptr), serviceCount_(0), serviceCap_(0),
          damageCodes_(nullptr), damageCount_(0), damageCap_(0) {
        if (price < 0) throw invalid_argument("Price cannot be negative.");
        price_ = price;
        totalCars_++;
    }

    // Copy constructor
    Car(const Car& other)
        : vin_(other.vin_), make_(other.make_), model_(other.model_), price_(other.price_),
          serviceHistory_(nullptr), serviceCount_(other.serviceCount_), serviceCap_(other.serviceCap_),
          damageCodes_(nullptr), damageCount_(other.damageCount_), damageCap_(other.damageCap_) {
        // Deep copy service records
        if (serviceCap_ > 0) {
            serviceHistory_ = new ServiceRecord[serviceCap_];
            for (size_t i = 0; i < serviceCount_; i++) serviceHistory_[i] = other.serviceHistory_[i];
        }
        // Deep copy damage codes
        if (damageCap_ > 0) {
            damageCodes_ = new int[damageCap_];
            for (size_t i = 0; i < damageCount_; i++) damageCodes_[i] = other.damageCodes_[i];
        }
        totalCars_++;
    }

    // Destructor
    ~Car() {
        delete[] serviceHistory_;
        delete[] damageCodes_;
        totalCars_--;
    }

    // Copy-swap assignment
    Car& operator=(Car other) {
        swap(*this, other);
        return *this;
    }

    // Friend 
    friend void swap(Car& lhs, Car& rhs) noexcept {
        using std::swap;
        swap(lhs.vin_, rhs.vin_);
        swap(lhs.make_, rhs.make_);
        swap(lhs.model_, rhs.model_);
        swap(lhs.price_, rhs.price_);
        swap(lhs.serviceHistory_, rhs.serviceHistory_);
        swap(lhs.serviceCount_, rhs.serviceCount_);
        swap(lhs.serviceCap_, rhs.serviceCap_);
        swap(lhs.damageCodes_, rhs.damageCodes_);
        swap(lhs.damageCount_, rhs.damageCount_);
        swap(lhs.damageCap_, rhs.damageCap_);
    }

    // Static accessor
    static size_t getTotalCars() { return totalCars_; }

    // Setters
    void setVIN(const string& vin) { vin_ = vin; }
    void setMake(const string& make) { make_ = make; }
    void setModel(const string& model) { model_ = model; }
    void setPrice(double price) {
        if (price < 0) throw invalid_argument("Price < 0 not allowed.");
        price_ = price;
    }

    // Getters
    const string& getVIN() const { return vin_; }
    const string& getMake() const { return make_; }
    const string& getModel() const { return model_; }
    double getPrice() const { return price_; }
    size_t getServiceCount() const { return serviceCount_; }
    size_t getDamageCount() const { return damageCount_; }
    const ServiceRecord* getServiceHistory() const { return serviceHistory_; }
    const int* getDamageCodes() const { return damageCodes_; }

    // Business functions
    void addService(const ServiceRecord& rec) {
        if (serviceCount_ == serviceCap_) reserveService(serviceCap_ == 0 ? 2 : serviceCap_ * 2);
        serviceHistory_[serviceCount_++] = rec;
    }

    void addDamageCode(int code) {
        if (damageCount_ == damageCap_) reserveDamage(damageCap_ == 0 ? 2 : damageCap_ * 2);
        damageCodes_[damageCount_++] = code;
    }

    void printInfo() const {
        cout << "VIN: " << vin_ << ", Make: " << make_ << ", Model: " << model_
             << ", Price: $" << price_
             << " | Services: " << serviceCount_
             << ", DamageCodes: " << damageCount_ << endl;

        if (serviceCount_ > 0) {
            cout << " Service Records:\n";
            for (size_t i = 0; i < serviceCount_; i++) {
                cout << "  "; serviceHistory_[i].print();
            }
        }
        if (damageCount_ > 0) {
            cout << " Damage Codes: ";
            for (size_t i = 0; i < damageCount_; i++) cout << damageCodes_[i] << " ";
            cout << endl;
        }
    }
};
size_t Car::totalCars_ = 0;


   
double averagePrice(const Car* arr, size_t n) {
    if (n == 0) return 0.0;
    double sum = 0;
    for (size_t i = 0; i < n; i++) sum += arr[i].getPrice();
    return sum / n;
}

bool compareByPriceAsc(const Car& a, const Car& b) { return a.getPrice() < b.getPrice(); }
bool compareByPriceDesc(const Car& a, const Car& b) { return a.getPrice() > b.getPrice(); }
bool areCarsEqual(const Car& a, const Car& b) { return a.getVIN() == b.getVIN(); }

const Car* maxPriceCar(const Car* arr, size_t n) {
    if (n == 0) return nullptr;
    const Car* maxCar = &arr[0];
    for (size_t i = 1; i < n; i++) if (arr[i].getPrice() > maxCar->getPrice()) maxCar = &arr[i];
    return maxCar;
}

const Car* findCarByVIN(const Car* arr, size_t n, const string& vin) {
    for (size_t i = 0; i < n; i++) if (arr[i].getVIN() == vin) return &arr[i];
    return nullptr;
}

size_t countCarsWithDamage(const Car* arr, size_t n, int code) {
    size_t count = 0;
    for (size_t i = 0; i < n; i++) {
        const int* d = arr[i].getDamageCodes();
        for (size_t j = 0; j < arr[i].getDamageCount(); j++)
            if (d[j] == code) { count++; break; }
    }
    return count;
}

void swapCars(Car& a, Car& b) { swap(a, b); }


int main() {
    cout << "Total Cars initially: " << Car::getTotalCars() << endl;

    Car cDefault;
    cDefault.printInfo();

    Car cHonda("1HGCM", "Honda", "Accord", 19999.99);
    cHonda.addDamageCode(101);
    cHonda.addDamageCode(205);
    cHonda.addDamageCode(307);
    cHonda.addService(ServiceRecord("2022-03-15", 15000, "Oil change"));
    cHonda.addService(ServiceRecord("2023-01-10", 25000, "Brake pads replacement"));

    cout << "\n--- Honda Car ---\n";
    cHonda.printInfo();

    Car cCopy(cHonda);
    cout << "\n--- Copy Car ---\n";
    cCopy.printInfo();

    Car cAssign;
    cAssign = cHonda;
    cout << "\n--- Assigned Car ---\n";
    cAssign.printInfo();

    // Heap array of Cars
    size_t N = 3;
    Car* garage = new Car[N];
    garage[0] = Car("JH4KA", "Acura", "TLX", 27999.49);
    garage[1] = Car("5YJ3E", "Tesla", "Model 3", 39999.00);
    garage[2] = Car("WBA4", "BMW", "3 Series", 34999.99);

    garage[0].addDamageCode(102);
    garage[1].addDamageCode(110);
    garage[2].addDamageCode(150);

    cout << "\n--- Garage Cars ---\n";
    for (size_t i = 0; i < N; i++) garage[i].printInfo();

    cout << "\nAverage price in garage: $" << averagePrice(garage, N) << endl;

    const Car* maxC = maxPriceCar(garage, N);
    if (maxC) cout << "Max price car: " << maxC->getVIN() << " $" << maxC->getPrice() << endl;

    const Car* found = findCarByVIN(garage, N, "5YJ3E");
    if (found) cout << "Found car VIN 5YJ3E: $" << found->getPrice() << endl;

    cout << "Cars with damage 110: " << countCarsWithDamage(garage, N, 110) << endl;

    delete[] garage;

    cout << "\nFinal total cars: " << Car::getTotalCars() << endl;
    return 0;
}

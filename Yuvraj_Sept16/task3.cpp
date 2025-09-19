#include <iostream>
using namespace std;

class CameraConfig {
private:
    int num_modes;
    int* resolution_width;
    int* resolution_height;

public:
    // Constructor
    CameraConfig(int n, int w[], int h[]) {
        num_modes = n;
        resolution_width = new int[num_modes];
        resolution_height = new int[num_modes];
        for (int i = 0; i < num_modes; i++) {
            resolution_width[i] = w[i];
            resolution_height[i] = h[i];
        }
    }

    // Copy constructor
    CameraConfig(const CameraConfig& other) {
        num_modes = other.num_modes;
        resolution_width = new int[num_modes];
        resolution_height = new int[num_modes];
        for (int i = 0; i < num_modes; i++) {
            resolution_width[i] = other.resolution_width[i];
            resolution_height[i] = other.resolution_height[i];
        }
    }

    // Destructor
    ~CameraConfig() {
        delete[] resolution_width;
        delete[] resolution_height;
    }

    void printConfig() const {
        cout << "Camera Configurations:\n";
        for (int i = 0; i < num_modes; i++) {
            cout << "Mode " << i << ": " << resolution_width[i]
                 << "x" << resolution_height[i] << endl;
        }
    }

    bool isHigherResolution(int mode1, int mode2) const {
        int res1 = resolution_width[mode1] * resolution_height[mode1];
        int res2 = resolution_width[mode2] * resolution_height[mode2];
        return this->resolution_width[mode1] * this->resolution_height[mode1] >
               this->resolution_width[mode2] * this->resolution_height[mode2];
    }

    int getNumModes() const { return num_modes; }
};

// Global functions
void printCameraConfig(const CameraConfig& config) {
    config.printConfig();
}

bool globalCompareResolution(const CameraConfig& config, int m1, int m2) {
    return config.isHigherResolution(m1, m2);
}

int main() {
    int widths[3] = {1920, 1280, 3840};
    int heights[3] = {1080, 2160, 2160}; 

    CameraConfig config(3, widths, heights);

    printCameraConfig(config);

    cout << "\nMember comparison (0 vs 2): ";
    cout << (config.isHigherResolution(0, 2) ? "Mode0 > Mode2" : "Mode0 <= Mode2") << endl;

    cout << "Global comparison (0 vs 2): ";
    cout << (globalCompareResolution(config, 0, 2) ? "Mode0 > Mode2" : "Mode0 <= Mode2") << endl;

    return 0;
}

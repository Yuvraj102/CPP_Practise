#include <iostream>
using namespace std;

class LaneBoundary {
private:
    float curvature;
    int lane_id;

public:
    LaneBoundary(float c, int id) : curvature(c), lane_id(id) {}

    float getCurvature() const { return curvature; }
    int getLaneId() const { return lane_id; }

    bool compareCurvature(const LaneBoundary& other) const {
        return this->curvature > other.curvature; 
    }

    void display() const {
        cout << "Lane ID: " << lane_id << ", Curvature: " << curvature << endl;
    }
};


bool isCurvatureGreater(const LaneBoundary& lane1, const LaneBoundary& lane2) {
    return lane1.getCurvature() > lane2.getCurvature();
}

void printLaneComparison(const LaneBoundary& lane1, const LaneBoundary& lane2) {
    if (lane1.getCurvature() > lane2.getCurvature())
        cout << "Lane " << lane1.getLaneId() << " has greater curvature.\n";
    else if (lane2.getCurvature() > lane1.getCurvature())
        cout << "Lane " << lane2.getLaneId() << " has greater curvature.\n";
    else
        cout << "Both lanes have equal curvature.\n";
}

int main() {
    LaneBoundary lane1(0.015f, 1);
    LaneBoundary lane2(0.023f, 2);

    lane1.display();
    lane2.display();

    cout << "\nMember function comparison: ";
    cout << (lane1.compareCurvature(lane2) ? "Lane1 > Lane2" : "Lane1 <= Lane2") << endl;

    cout << "Global function comparison: ";
    printLaneComparison(lane1, lane2);

    return 0;
}

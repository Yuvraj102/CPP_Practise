/*
(Modifying Class GradeBook) Modify class GradeBook (Figs. 3.11–3.12) as follows:
a) Include a second string data member that represents the course instructor’s name.
b) Provideasetfunctiontochangetheinstructor’snameandagetfunctiontoretrieveit.
c) Modify the constructor to specify course name and instructor name parameters.
d) Modify function displayMessage to output the welcome message and course name,
then the string "This course is presented by: " followed by the instructor’s name. Use your modified class in a test program that demonstrates the class’s new capabilities.

*/


#include <iostream>
#include <string>
using namespace std;

class GradeBook {
private:
    string courseName;     // course name
    string instructorName; // instructor name

public:
    // Constructor
    GradeBook(const string& cname, const string& iname) {
        courseName = cname;
        instructorName = iname;
    }

    // Setters
    void setCourseName(const string& cname) { courseName = cname; }
    void setInstructorName(const string& iname) { instructorName = iname; }

    // Getters
    string getCourseName() const { return courseName; }
    string getInstructorName() const { return instructorName; }

    // Display message
    void displayMessage() const {
        cout << "grade book for: " << courseName << "!" << endl;
        cout << "course is presented by: " << instructorName << endl;
    }
};

int main() {
    // Create GradeBook object
    GradeBook gb("Object-Oriented Programming", "Dr. Jean");

    // Display message with course & instructor
    gb.displayMessage();

    cout << "\nUpdating instructor name...\n";
    gb.setInstructorName("Prof. Kevin");

    // Display again with updated instructor
    gb.displayMessage();

    return 0;
}

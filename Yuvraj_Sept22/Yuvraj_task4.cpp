/*
(Employee Class) Create a class called Employee that includes three pieces of information as data members—a first name (type string), a last name (type string) and a monthly salary (type int). [Note: In subsequent chapters, we’ll use numbers that contain decimal points (e.g., 2.75)— called floating-point values—to represent dollar amounts.] Your class should have a constructor that initializes the three data members. Provide a set and a get function for each data member. If the monthly salary is not positive, set it to 0. Write a test program that demonstrates class Employee’s capabilities. Create two Employee objects and display each object’s yearly salary. Then give each Em- ployee a 10 percent raise and display each Employee’s yearly salary again.
*/

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string firstName;
    string lastName;
    int monthlySalary;

public:
    // constructor
    Employee(string f, string l, int salary) {
        firstName = f;
        lastName = l;
        if (salary > 0) {
            monthlySalary = salary;
        } else {
            monthlySalary = 0;
        }
    }

    // setters
    void setFirstName(string f) { firstName = f; }
    void setLastName(string l) { lastName = l; }
    void setMonthlySalary(int salary) {
        monthlySalary = (salary > 0 ? salary : 0);
    }

    // getters
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    int getMonthlySalary() const { return monthlySalary; }

    // calculate yearly salary
    int getYearlySalary() const {
        return monthlySalary * 12;
    }

    // apply raise by percentage
    void giveRaise(double percent) {
        if (percent > 0) {
            monthlySalary = monthlySalary + (monthlySalary * percent / 100);
        }
    }
};

int main() {
    // create employees
    Employee emp1("Alice", "Brown", 3000);
    Employee emp2("Bob", "Smith", 2000);

    cout << emp1.getFirstName() << " " << emp1.getLastName()
         << " yearly salary: " << emp1.getYearlySalary() << endl;
    cout << emp2.getFirstName() << " " << emp2.getLastName()
         << " yearly salary: " << emp2.getYearlySalary() << endl;

    // give 10% raise
    emp1.giveRaise(10);
    emp2.giveRaise(10);

    cout << "\nAfter 10% raise:" << endl;
    cout << emp1.getFirstName() << " " << emp1.getLastName()
         << " yearly salary: " << emp1.getYearlySalary() << endl;
    cout << emp2.getFirstName() << " " << emp2.getLastName()
         << " yearly salary: " << emp2.getYearlySalary() << endl;

    return 0;
}

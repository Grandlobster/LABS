//Aadesh Lawande
//Roll no:37
/* 
Develop a program in C++ to create a database of student�s information system containing the
following information: Name, Roll number, Class, Division, Date of Birth, Blood group,
Contact address, Telephone number, Driving license no. and other. Construct the database with
suitable member functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and dynamic memory
allocation operators-new and delete as well as exception handling
*/
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string className;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNumber;

    // Private static member to keep track of the total number of students
    static int totalStudents;

public:
    // Default constructor
    Student() : rollNumber(0), division('A') {
        totalStudents++;
    }

    // Parameterized constructor
    Student(string n, int roll, string cls, char div, string birth, string blood, string address, string phone, string license)
        : name(n), rollNumber(roll), className(cls), division(div), dob(birth), bloodGroup(blood),
          contactAddress(address), telephoneNumber(phone), drivingLicenseNumber(license) {
        totalStudents++;
    }

    // Copy constructor
    Student(const Student &source) {
        name = source.name;
        rollNumber = source.rollNumber;
        className = source.className;
        division = source.division;
        dob = source.dob;
        bloodGroup = source.bloodGroup;
        contactAddress = source.contactAddress;
        telephoneNumber = source.telephoneNumber;
        drivingLicenseNumber = source.drivingLicenseNumber;
        totalStudents++;
    }

    // Destructor
    ~Student() {
        totalStudents--;
    }

    // Static member function to get the total number of students
    static int getTotalStudents() {
        return totalStudents;
    }

    // Friend class to access private members
    friend class Database;

    // Display function
    void display() const {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\nClass: " << className
             << "\nDivision: " << division << "\nDate of Birth: " << dob << "\nBlood Group: " << bloodGroup
             << "\nContact Address: " << contactAddress << "\nTelephone Number: " << telephoneNumber
             << "\nDriving License Number: " << drivingLicenseNumber << endl;
    }
};

// Initialize the static member
int Student::totalStudents = 0;

// Friend class to access private members of Student
class Database {
public:
    static void printTotalStudents() {
        cout << "Total Students: " << Student::getTotalStudents() << endl;
    }
};

int main() {
    try {
        // Creating objects using different constructors
        Student student1;
        Student student2("Payal Chavan", 101, "Robotics", 'A', "15/11/2004", "Unknow", "Narhe", "???", "??");

        // Displaying student information
        student1.display();
        student2.display();

        // Copying a student
        Student student3 = student2;
        student3.display();

        // Accessing private members using friend class
        Database::printTotalStudents();
    } catch (const exception &e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}


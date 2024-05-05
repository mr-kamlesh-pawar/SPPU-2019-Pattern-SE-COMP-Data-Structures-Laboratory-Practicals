#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Structure to represent an employee
struct Employee {
    int empId;
    string name;
    string designation;
    double salary;
};

// Function to add an employee to the file
void addEmployee() {
    ofstream file("employees.dat", ios::binary | ios::app);
    Employee emp;

    cout << "Enter Employee ID: ";
    cin >> emp.empId;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, emp.name);
    cout << "Enter Designation: ";
    getline(cin, emp.designation);
    cout << "Enter Salary: ";
    cin >> emp.salary;

    file.write(reinterpret_cast<char*>(&emp), sizeof(Employee));
    file.close();
}

// Function to delete an employee from the file
void deleteEmployee(int empId) {
    ifstream inFile("employees.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary);

    Employee emp;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.empId != empId) {
            outFile.write(reinterpret_cast<char*>(&emp), sizeof(Employee));
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove("employees.dat");
    rename("temp.dat", "employees.dat");

    if (!found) {
        cout << "Employee with ID " << empId << " not found." << endl;
    } else {
        cout << "Employee with ID " << empId << " deleted successfully." << endl;
    }
}

// Function to display information of a particular employee
void displayEmployee(int empId) {
    ifstream file("employees.dat", ios::binary);
    Employee emp;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.empId == empId) {
            found = true;
            cout << "Employee ID: " << emp.empId << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Designation: " << emp.designation << endl;
            cout << "Salary: $" << fixed << setprecision(2) << emp.salary << endl;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Employee with ID " << empId << " not found." << endl;
    }
}

int main() {
    int choice;
    int empId;

    do {
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Display Employee Information\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                cout << "Enter Employee ID to delete: ";
                cin >> empId;
                deleteEmployee(empId);
                break;
            case 3:
                cout << "Enter Employee ID to display: ";
                cin >> empId;
                displayEmployee(empId);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}

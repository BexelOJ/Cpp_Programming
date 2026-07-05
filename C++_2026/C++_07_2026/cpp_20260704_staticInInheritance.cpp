#include <iostream>
using namespace std;

class Employee {
private:
//    static int companyId;  
    int empId;             // Non-static member

public:
    static int companyId;  
    static void display() {
        cout << "Company ID: " << companyId << endl;   // ✅ Allowed
    }
};

class HR: public Employee{
static int deptId;
   public:
static void displayHRDetails() {
        cout << "Department ID: " << deptId << endl;
        cout << "Company ID: " << companyId << endl;
    }
};

int Employee::companyId = 1001;
int HR::deptId = 005;

int main() {
    Employee::display();
    HR::displayHRDetails();
}



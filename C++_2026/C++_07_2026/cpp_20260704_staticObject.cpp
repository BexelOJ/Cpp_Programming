#include <iostream>
using namespace std;

class Employee {
private:
    int empId;
    char c;
    char d;
    int z;
    char e;
    char f;
   
    static int companyId;
public:
    Employee(int id) : empId(id) {}

    static void show() {
/*        cout << e.empId << endl;
        e.empId = 103;
        cout << e.empId << endl;// ✅ Allowed through an object*/
        cout << Employee::companyId << endl;   // ✅ Allowed through the class name
        

    }
     void show(Employee &e) {
        cout << e.empId << endl;
        e.empId = 103;
        cout << e.empId << endl;// ✅ Allowed through an object
        cout << Employee::companyId << endl;   // ✅ Allowed through the class name
        cout<<sizeof(this)<<endl;
        cout<<sizeof(e)<<endl;   
        cout<<this<<endl;   
      }
};

int Employee::companyId = 1001;

int main() {
    Employee e(101);
    e.show(e);
    //Employee::show(e);
}






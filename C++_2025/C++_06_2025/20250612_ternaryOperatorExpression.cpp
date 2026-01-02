#include <iostream>
using namespace std;

class Check{
public:
    void equal(int a, int b){
         cout << a<<" and "<<b<<" are " << (a == b ? "Same" : "Different") << " values" << endl;
         // Ternary Operator Expression
    }

    void compares(int a, int b) {
        cout << a << " compares " << b << " : " << (a > b ? "greater" : "lesser") << " values" << endl;
        // Ternary Operator Expression
    }

 };

int main(){
    Check c;
    c.equal(10,10);
    c.equal(5, 10);
    c.equal(10, 15);

    c.compares(10, 5);
    c.compares(10, 15);
    c.compares(5, 10);

}



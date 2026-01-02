// Rule of Three
#include <string>
#include <iostream>

using namespace std;

int add(int a, int b) {
    int res = a + b;
    return res;
}
int main() {
    int a = 0, b = 0;
    cout << "Enter the First Number : " << endl;
    cin >> a;
    cout << "Enter the Second Number : " << endl;
    cin >> b;
    int finRes = add(a, b);
    cout << "Sum of " << a << " and " << b << " is " << finRes << endl;

    return 0;
}





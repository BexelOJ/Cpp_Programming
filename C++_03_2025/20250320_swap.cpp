#include <iostream>

using namespace std;

void swap(int x, int y)
{
    x = x + y;
    y = x - y;
    x = x - y;
    cout << "1st Number: " << x << endl << "2nd Number: " << y << endl;
}

int main()
{
    int a = 0, b = 0;
    cout << "Enter Two Numbers: " << endl;
    cin >> a >> b;
    swap(a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "1st Number: " << a << endl << "2nd Number: " << b << endl;


return 0;
}



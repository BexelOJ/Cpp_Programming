#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cout << "Enter a Number: " << endl;
    cin >> n;

    cout << n << " * 2 = " << endl;
    cout << (n<<1) << endl<<endl;

    cout << n << " * 7 = " << endl;
    cout << (n<<2) + (n<<1) + (n<<0) << endl << endl;

    cout << n << " * 8 = " << endl;
    cout << (n<<3) << endl << endl;

    cout << n << " * 12 = " << endl;
    cout << (n<<3) + (n<<2)<< endl << endl;

    cout << n << " * 33 = " << endl;
    cout << (n<<5) + (n<<0) << endl << endl;

    cout << n << " * 52 = " << endl;
    cout << (n<<5) + (n<<4) + (n<<2)<< endl << endl;

    cout << n << " * 53 = " << endl;
    cout << (n<<5) + (n<<4) + (n<<2) + (n<<0)<< endl << endl;

    return 0;
}


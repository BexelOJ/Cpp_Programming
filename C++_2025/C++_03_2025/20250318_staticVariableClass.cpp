#include <iostream>

using namespace std;

class Base {
private:
    static int a;
public:
    static int b;
    static int count;

    Base()
    {
        count++;
    }

    void showNormalFunction()
    {
        cout << " Inside showNormalFunction: Value of a : " << a << endl;
        cout << " Inside showNormalFunction: Value of b : " << b << endl;
        cout << "Count : " << count << endl;
    }

    static void show()
    {
        cout << " Inside static show: Value of a : " << a << endl;
        cout << " Inside static show: Value of b : " << b << endl;
        cout << "Count : " << count << endl;
    }
};

int Base::a = 10;
int Base::b = 20;
int Base::count = 0;

int main()
{
    //cout << Base::a << endl;
    cout << Base::b << endl;

    Base b1;
    b1.showNormalFunction();
    b1.show();

    Base* b2 = new Base;
    b2->showNormalFunction();
    b2->show();

    Base* b3 = new Base;
    b3->showNormalFunction();
    b3->show();

    Base* b4 = new Base;
    b4->showNormalFunction();
    b4->show();

    Base* b5 = new Base;
    b5->showNormalFunction();
    b5->show();

    Base::show();

    return 0;
}


#include<iostream>

using namespace std;

class Demo {
    int v_1;
    int v_2;
    
public:
    Demo(int value_1 = 0, int value_2 = 0) {
        this->v_1 = value_1;
        this->v_2 = value_2;
    }

    static int  a;

    ~Demo() {
    
    }

    void display() {
        cout << "Displaying number 1 : " << this->v_1 << endl;
        cout << "Displaying number 2 : " << this->v_2 << endl;
    }
};


int Demo::a = 25;

int main() {
    Demo d1; // stack object with no parameter
    cout << d1.a << endl;
    d1.display();
    (d1.a)++;

    Demo d2(10,20);  // stack object with atleast one parameter
    cout << d2.a << endl;
    d2.display();
    (d1.a)++;

    Demo *d3 = new Demo; // heap object with no parameter
    cout << d3->a << endl;
    d3->display();
    (d3->a)++;

    Demo* d4 = new Demo(60,70); // heap object with atleast one parameter
    cout << d4->a << endl;
    d4->display();
    (d4->a)++;

    delete d3,d4;

    return 0;
}




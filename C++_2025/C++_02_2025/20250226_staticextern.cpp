#include "20250226_staticheader.h"
#include <iostream>

using namespace std;

static int varr = 50;

int MyClass::var = 10;

void MyClass::staticFunction() {  // static function definition
    // int var = 20;
    std::cout << "Static Function called" << std::endl;
    cout<<var<<endl;
}

void MyClass::NormalFunction()
{
    cout<<"Normal Function Called"<<endl;
    cout<<varr<<endl;
}




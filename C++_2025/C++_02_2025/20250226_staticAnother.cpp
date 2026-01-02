#include "20250226_staticheader.h"
#include <iostream>

using namespace std;

int main()
{
MyClass::staticFunction();

MyClass *c = new MyClass;;
c->NormalFunction();

MyClass::staticFunction();

return 0;
}

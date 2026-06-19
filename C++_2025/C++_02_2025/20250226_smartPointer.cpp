#include <iostream>
#include <memory>

using namespace std;

int main()
{
std::unique_ptr<int> ptr1 = std::make_unique<int>(20);
std::unique_ptr<double> ptr2 = std::make_unique<double>(10.0012);
cout<<sizeof(ptr1)<<endl;
cout<<sizeof(*ptr1)<<endl;

cout << sizeof(ptr2) << endl;
cout << sizeof(*ptr2) << endl;

cout << *ptr1 << endl;
cout<<*ptr2<<endl;

return 0;
}



/*
OUTPUT:

8
4
8
8
20
10.0012

*/


#include <iostream>
#include <memory>

using namespace std;

int main()
{
std::unique_ptr<int> ptr = std::make_unique<int>(20);
std::unique_ptr<double> ptr2 = std::make_unique<double>(10.0012);
cout<<sizeof(ptr)<<endl;
cout<<sizeof(*ptr)<<endl;
cout<<*ptr2<<endl;
cout<<*ptr<<endl;

return 0;
}




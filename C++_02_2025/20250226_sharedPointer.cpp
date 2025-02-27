#include <iostream>
#include <memory>

using namespace std;

int main()
{
std::shared_ptr<int> ptr = std::make_shared<int>(30);
cout<<sizeof(ptr)<<endl;
cout<<sizeof(*ptr)<<endl;
cout<<*ptr<<endl;
return 0;
}



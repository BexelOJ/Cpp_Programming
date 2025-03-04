#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyClass{
public:
    int a;
    char c;
    MyClass(int x, int y):a(x),c(y){}

static bool compare(const MyClass& a, const MyClass& b)
{
    return a.a < b.a;
}  
};

int main()
{
//MyClass c3,b2,a1;
vector<MyClass> arr = {MyClass(30,'a'),MyClass(20,'b'),MyClass(50,'c'),MyClass(10,'d'),MyClass(40,'e')};
sort(arr.begin(),arr.end(),MyClass::compare);

for(const auto& obj: arr)
{
    cout<<"Int: "<<obj.a<<"Char: "<<obj.c<<endl;
}

return 0;
}


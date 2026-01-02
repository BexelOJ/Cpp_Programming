#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int* calculation(vector<int> v)
{
    int* sum = new int(0);
    for_each(v.begin(), v.end(), [sum](int x){*sum += x;});
    return sum;

    
}

int main()
{
vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};

int* res = calculation(v1);
cout<<"Sum = "<<*res<<endl;

delete res;
return 0;
}





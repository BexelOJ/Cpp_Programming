#include <iostream>
using namespace std;

int main()
{
int n = 3;
while(n>=0)
{
    cout<< n * n <<endl;
    --n;
}

while(n<4)
{
    cout<< n <<endl;
    n++;
}
while(n>0)
{
    cout<< (n/=2) <<endl;
}
cout<<n<<endl;

return 0;
}



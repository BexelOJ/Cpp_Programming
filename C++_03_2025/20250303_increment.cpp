#include <iostream>

using namespace std;

int main()
{
int a = 3;

int res1 = a++; 
cout<<"res1 = "<<res1<<endl;   //3 starting value at a++
cout<<"a1 = "<<a<<endl<<endl;  // 4

a = 3;
int res2 = a++ + ++a;
cout<<"res2 = "<<res2<<endl;
cout<<"a2 = "<<a<<endl<<endl;

a = 3;
int res3 = a++ + ++a + a++;
cout<<"res3 = "<<res3<<endl;
cout<<"a3 = "<<a<<endl<<endl;

a = 3;
int res4 = a++ + ++a + a++ + ++a;
cout<<"res4 = "<<res4<<endl;
cout<<"a4 = "<<a<<endl<<endl;

return 0;
}

/*

res1 = 3
a1 = 4

res2 = 8
a2 = 5

res3 = 13
a3 = 6

res4 = 20
a4 = 7

*/


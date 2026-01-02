#include <iostream>
#include <cstring>

using namespace std;

int main()
{
char str1[10] = "India";
char str2[] = "India_is";
char str3[] = "India_is_my";
char str4[] = "India_is_my_country";
char str5[] = "India_is_my_country_all";
char str6[50] = "India";

int a,b,c,d,e,i,j;
string g,h,f;
a = strlen(str1);
b = sizeof(str1);
c = sizeof(str3);
d = sizeof(str4);
e = sizeof(str5);

cout<<a<<endl;
cout<<b<<endl;
cout<<c<<endl;
cout<<d<<endl;
cout<<e<<endl;

f = strcat(str6,str1);

cout<<f<<endl;
cout<<strlen(str6)<<endl;
cout<<sizeof(str6)<<endl;

return 0;
}






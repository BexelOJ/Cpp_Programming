#include <iostream>
#include <cstring>

using namespace std;

int main()
{
char str[] = "110010101001";
int n=0;
char temp[13];
strcpy(temp,str);
n = strlen(str);
for(int i=1; i<n; i = i+2)
{
    if(str[i] == '1')
        {
            str[i] = '0';
        }
    else if(str[i] == '0')
        {
            str[i] = '1';
        }
   
}
cout<<"Original: "<<temp<<endl;
cout<<"Modified: "<<str<<endl;

printf("%d\n",str[0]);
printf("%x\n",str[0]);
return 0;
}


/*

Original: 110010101001
Modified: 100111111100
49
31

*/

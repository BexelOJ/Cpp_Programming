#include <iostream>
#include <cstring>

using namespace std;

int main()
{
int n = 78;
int s=0;
printf("%d\n",n);
printf("%b\n",n);
printf("%o\n",n);
printf("%x\n",n);
printf("%X\n",n);

char str[10];
int b;
for(int i=0; n>0; i++)
    {
    b = n%2;  // 0   1   1   1   0   0 
    n = n/2;  // 39  19  9   4   2   1
    if(b)
        str[i] = '1';
    else
        str[i] = '0';    
    }
s = strlen(str);
for(int j=s; j>=0; j--)
{
    cout<<str[j];
}
cout<<endl;

return 0;
}

/*

78
1001110
116
4e
4E
1001110

*/

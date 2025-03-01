#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
char str[] = "abbcc88 iuiddd 9945 kii99";
int n=0;
printf("%s\n",str);
cout<<str<<endl;
n = strlen(str);
for(int j=0;j<n;j++)
{
    n=strlen(str);
    for(int i=0; i<n;i++)
        {
            if(str[i] == str[i+1])
                {
                    str[i+1] = str[i+2];
                }
            if(str[i] == ' ')
                {
                    str[i] = str[i+1];
                }
        }
}
cout<<str<<endl;
return 0;
}

/*

abbcc88 iuiddd 9945 kii99
abbcc88 iuiddd 9945 kii99
abc8iuid945ki9

*/

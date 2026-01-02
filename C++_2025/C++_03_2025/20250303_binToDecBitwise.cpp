#include <iostream>

using namespace std;

int display(char m[])
{
    int c=0;
    for(int i=0; i<8; i++)
    {
        if(m[i] == '1')
        {
            c = c + (1<<(7-i));
        }
        else
        {
            continue;
        }
    }
    return c;
}

int main()
{
char n[8]={00000000};
cout<<"Enter a binary number:"<<endl;
cin>>n;
cout<<display(n)<<endl;

return 0;
}



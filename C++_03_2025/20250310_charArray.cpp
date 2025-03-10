#include <iostream>
#include <cstring>
using namespace std;

int main()
{
int size=0;
char arr[] = {"110010101001"};
size = strlen(arr);
for(int i=0; i<size; i++)
{
    cout<<arr[i];
}
cout<<endl;
// 110010101001
// 100111111100
// cout<<"\nsizeof Array: "<<sizeof(arr)<<endl;  //13
// cout<<"strlen Array: "<<strlen(arr)<<endl;   // 12
for(int i=1; i<size; i=i+2)
{
    //cout<<arr[i]<<endl;
    if(arr[i] == '0')
    {
        arr[i] = '1';
    }
    else if(arr[i] == '1')
    {
        arr[i] = '0';
    }
    
}
for(int i=0; i<12; i++)
{
    cout<<arr[i];
}
cout<<endl;
return 0;
}



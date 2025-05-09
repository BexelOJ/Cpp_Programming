#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n=0, dup=0, count=0, y=0, i=0;
    cin>>n;
    dup=n;
    for( int i=0; n>0; i++){
    if(n > 0){
        count++;
        n = n / 10;
        }
    }
    
    int arr[count];
    for(int i=0; dup>0; i++){
    if(dup > 0){
        count++;
        y = dup % 10;
        arr[i] = y;
        dup = dup / 10;
        }
    }
    
    int m = sizeof(arr) / sizeof(arr[0]);

    std::sort(arr, arr + m);
    
    cout<<arr[m-1]*arr[m-2]<<endl;
    
    return 0;
}



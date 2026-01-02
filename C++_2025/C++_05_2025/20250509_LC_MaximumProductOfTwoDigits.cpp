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
        y = dup % 10;
        arr[i] = y;
        dup = dup / 10;
        }
    }
    
    sort(arr, arr + count);
    
    cout<<arr[count-1]*arr[count-2]<<endl;
    
    return 0;
}



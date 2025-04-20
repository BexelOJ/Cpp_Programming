#include <iostream>

using namespace std;

// array passByReference, 
// in c-Style, no passByValue for arrays//
int add(int arr[], int size)
{
    int sum =0;
    for(int i=0; i<size; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

// another way using pointer, for array passByReference//
// int* resultModify(int arr[], int size)
int* resultModify(int *arr, int size) 
{
    for(int i=0; i<size; i++)
    {
        arr[i] = arr[i] + 10;
    }
    return arr;
}

int main()
{
int arr[] = {1,3,5,2,4};
// array size should also be passed// 
int size = (sizeof(arr)/sizeof(arr[0]));

cout<<add(arr,size)<<endl;
int* r = resultModify(arr,size);

for(int i=0; i<size; i++)
{
    cout<<r[i]<<" ";
}
cout<<endl;
return 0;
}


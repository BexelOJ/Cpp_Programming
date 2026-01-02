// My Bubble Sort:
#include <iostream>

using namespace std;

int main()
{
int arr[10]; // = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
cout<<"Enter the Array Elements"<<endl;
for(int i=0; i<10; i++)
{
    cin>>arr[i];
}
int size = (sizeof(arr)/sizeof(arr[0]));
cout<<size<<endl;

cout<<"Entered Array as it is: "<<endl;
for(int i=0; i<10; i++)
{
    cout<<arr[i]<<" ";
}
cout<<endl;

for (int i = 0; i < 10; i++) {
    for (int j = 0; j < (9-i); j++)
    {
        if (arr[j] > arr[j + 1])
        {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}
cout<<"Sorted Array is: "<<endl;
for(int i=0; i<10; i++)
{
    cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}

/*
OUTPUT:

Entered Array as it is:
3 5 7 1 9 2 6 4 15 10
Sorted Array is:
1 2 3 4 5 6 7 9 10 15

*/

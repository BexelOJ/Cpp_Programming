#include <iostream>
#include <cstdio>

using namespace std;

void add1(int (& arr)[10])      // array, call by reference
{
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] <<" ";
    }
    //cout << endl;

    for (int i = 0; i < 9; i++)
    {
        arr[i] = arr[i] + 10;
    }
    cout << endl;
    
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl<<endl;

}

void add2(int* arr)      // array, Call by Address
{
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
   // cout << endl;

    for (int i = 0; i < 9; i++)
    {
        arr[i] = arr[i] + 10;
    }
    cout << endl;

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl<<endl;

}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    add1(arr);
    add2(arr);
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl << endl;

    return 0;
}




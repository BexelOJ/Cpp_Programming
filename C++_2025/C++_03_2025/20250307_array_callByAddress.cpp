#include <iostream>
#include <cstdio>

using namespace std;

void add(int* arr)      // array, Call by Address
{
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;

    for (int i = 0; i < 9; i++)
    {
        arr[i] = arr[i] + 10;
    }
    cout << endl;
    
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    add(arr);
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}




#include <iostream>

using namespace std;

int main()
{
    int n = 0, arr[] = {1,2,3,4,5,6};
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter the Number of Rotate:" << endl;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        int temp = arr[0];
        for (int i = 0; i < 5; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[5] = temp;
    }

     for (int i = 0; i < 6; i++)
        {
            cout << arr[i] << " ";
        }
      cout << endl;
    return 0;
}




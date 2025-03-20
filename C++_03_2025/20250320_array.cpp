#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int* arrCalInt(int *arrDis)
{
    for (int i = 0; i < 5; i++)
    {
        arrDis[i] = arrDis[i] +10;
        cout << arrDis[i] << " ";
    }
    cout << endl;
    return arrDis;
}

char* arrCalChar(char* arrDis)
{
    for (int i = 0; i < 5; i++)
    {
       // arrDis[i] = arrDis[i];
        cout << arrDis[i] << " ";
    }
    cout << endl;
    return arrDis;
}

int main()
{
    char arr1[] = "Hello";
    int arr2[5] = {1,2,3,4,5};
    int a = 3;
    int s = sizeof(arr2);
    int size = strlen(arr1);
    cout << s << " " << size << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Address: " << (char)arr2[i] << endl;
        cout << "Address: " << (int)arr2[i] << endl;
    }

    cout << endl;
    
    int *d2 = arrCalInt(arr2);
    char* d1 = arrCalChar(arr1);

    for (int i = 0; i < 5; i++)
    {
        cout << d2[i]+10<< " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << d1[i+10] << " ";
    }
    cout << endl;

    return 0;
}


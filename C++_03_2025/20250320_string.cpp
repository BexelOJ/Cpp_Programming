#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char* stringReverse(int len, char* arr)
{
    char* temp = new char[len - 1];
    for (int i = 0, j = len - 1; i < len; i++, j--)
    {
        temp[i] = arr[j];
    }
    temp[len] = '\0';  // Null-terminate the reversed string

    return temp; 
}

int main()
{
    char arr[] = "Hello World New India";
    int length = strlen(arr);

    char* revStr = stringReverse(length, arr); 
    int nSpa = 0;
    for (int i = 0; i < length; i++)
    {
        
        if (arr[i] == ' ')
        {
            nSpa++;
        }
    }
    cout << "Numebr of Spaces: " << nSpa << endl;
    // revStr is now pointing to invalid memory
    cout << revStr << endl; // Undefined behavior

    delete[] revStr;
    return 0;
}



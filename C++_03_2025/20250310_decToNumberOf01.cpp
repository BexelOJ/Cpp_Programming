#include <iostream>
#include <cstdint>
#include <cstdio>
using namespace std;

int numberFilter(int num)
{
    int arr[32];// = { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0 };
    //char arr[32];// = { '11110000111100001111000011110000' };
    int i = 0, j = 0;
    for (i = 31, j=0; i >= 0, j<32; i--, j++)
    {
        arr[j] = ((num >> i) & 0x01);
    }

    for (i = 0; i < 32; i++) {
        cout << arr[i];
    }
    cout << endl;
    return *arr;
}

int main()
{
    int m = 0;
    uint32_t n = 0;
    cout << "Enter a Decimal Number: " << endl;
    cin >> m;
    n = m;

int ptr = numberFilter(m);

    // for (int i = 0; i < 32; i++)
    // {
       printf("%x",ptr);
   // }
    return 0;
}



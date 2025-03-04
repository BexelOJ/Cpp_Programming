#include <iostream>
#include <cstdint>

using namespace std;

int convert(int x)
{
    int res = ((x >> 12) & (0x000f) | (x >> 4) & (0x00f0) | (x << 12) & (0xf000) | (x << 4) & (0x0f00) );  
        
    cout << res << endl;
    for (int i = 0; i < 7; i++)
    {
        printf("\n");
        printf("Binary: %b\n", res);
        printf("Hex: %X\n", res);
        printf("Octal: %o\n", res);
        printf("Decimal: %d\n", res);
    }
    return 0;
}

int main()
{
int num = 0;
cout << "Enter 4 Byte Hex Number: " <<endl;
cin >> hex >> num;
convert(num);

return 0;
}




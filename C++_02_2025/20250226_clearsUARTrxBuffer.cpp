#include <iostream>
#include <cstring>
using namespace std;

int main()
{
char rxBuffer[256];

cout<<sizeof(rxBuffer)<<endl;
for(int i=0; i<256; i++)  // set some values
    rxBuffer[i]=i;
for(int i=0; i<256; i++)  // print those values
    cout<<rxBuffer[i]<<endl;

memset(&rxBuffer,1,sizeof(rxBuffer));  // clears UART receive buffer

cout<<sizeof(rxBuffer)<<endl; // print the empty
for(int i=0; i<256; i++)
    cout<<rxBuffer[i]<<endl;
return 0;
}



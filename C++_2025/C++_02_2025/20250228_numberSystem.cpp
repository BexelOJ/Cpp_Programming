#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{

char strn[] = "!"; // 33 in dec
printf("%b\n",strn[0]); // 100001
printf("%o\n",strn[0]); // 41
printf("%d\n",strn[0]); // 33
printf("%X\n",strn[0]); // 21

cout<<strlen(strn)<<endl;
return 0;
}

/*

100001
41
33
21
1

*/


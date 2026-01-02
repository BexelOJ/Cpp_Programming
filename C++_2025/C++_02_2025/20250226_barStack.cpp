#include <iostream>
#include <cstring>

using namespace std;

typedef struct{
    int a;
    double b;
}my_struct_t;

// struct my_struct_t{
//     int a;
//     double b;
// }bar;

int main()
{
my_struct_t bar;
// setting values
bar.a = 10;
bar.b = 20;
cout<<"a = "<<bar.a<<", b = "<<bar.b<<endl;

cout<<sizeof(my_struct_t)<<endl;  // size of struct - 16 (8 + 8)
cout<<sizeof(bar)<<endl;    // size of instance - 16 (8 + 8)

// clearing values
memset(&bar,0,sizeof(my_struct_t));
printf("a = %d, b = %.2f\n",bar.a,bar.b);

return 0;
}






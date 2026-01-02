#include <iostream>
#include <cstring>
#include <algorithm> 

using namespace std;

typedef struct{
    int a;
    double b;
}my_struct_t;

int main()
{
cout<<sizeof(my_struct_t)<<endl;
my_struct_t *ptr = (my_struct_t*)malloc(sizeof(my_struct_t));

cout<<sizeof(ptr)<<endl;  // pointer size - 8
cout<<sizeof(*ptr)<<endl; // size of the instance - 16 (8 + 8)

// setting values
ptr->a = 10;
ptr->b = 20.23;

printf("a = %d, b = %.2f\n",ptr->a, ptr->b);

if(!ptr)
{
    perror("Memory allocation failed");
    return 1;
}

//fill(bar,sizeof(my_struct_t),1);

// clearing values
//memset(ptr,0,sizeof(*ptr));
memset(ptr,0,sizeof(my_struct_t));
printf("a = %d, b = %.2f\n",ptr->a, ptr->b);

free(ptr);

return 0;
}






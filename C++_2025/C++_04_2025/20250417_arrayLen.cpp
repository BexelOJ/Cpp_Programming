#include <iostream>

using namespace std;


//int* solve(int* , int , int);
int* solve(int* A, int n1, int B) {
    cout<<"n1: "<<n1<<endl;
    cout<<"B: "<<B<<endl;
    int* arr = new int[B]; 
    int max = A[0];
    for(int j=0; j<B; j++)
    {
    for(int i=0; i<(n1-1-j); i++)
    {
        if(A[i+1] > A[i])
        {
            max = A[i+1];
        }
    }
    arr[j] = max;
} 
// for(int i=0; i<B; i++)
// {
//     cout<<arr[i]<<" ";
// }
// cout<<endl;
   return arr;
}


int main()
{
int A[] = {1,2,3,4,5,6,7,8,9};
int n1 = (sizeof(A)/sizeof(A[0]));
int B = 3;

int* r = solve(A, n1, B);
for(int i=0; i<B; i++)
{
    cout<<r[i]<<" ";
}
cout<<endl;

return 0;
}



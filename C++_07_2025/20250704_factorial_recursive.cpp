#include <iostream>
using namespace std;

long int factorial(int x){
    long int fin=x, res=0;
    if (x == 0 or x == 1){
        return 1;
    }
    return fin * factorial(fin-1);  
}

int main(){
    int n = 0;
    cout<<"Enter a number to find its factorial: "<<endl;
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}


// 5! = 5 * 4 * 3 * 2 * 1 

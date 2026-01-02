#include <iostream>
#include <cstdio>

using namespace std;

int division(int x, int y){
    if(y == 0){
        throw "Division by Zero Error";
    }
    return x/y;
}

int main(){
    int a = 20, b=0;
    
    try{
    int res = division(a,b);
    cout <<res<<endl;
    }
    catch(const string* msg){
        cout<<msg<<endl;    
    }
    return 0;
}



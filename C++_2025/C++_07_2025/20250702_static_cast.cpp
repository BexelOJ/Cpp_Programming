#include <iostream>
using namespace std;

int main(){
    int x = 10;
    float f = 20.333;
    x = static_cast<int>(f);
    cout<<x<<endl;
    return 0;
}

/*
Output:

20

*/


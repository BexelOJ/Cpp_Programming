#include <iostream>
using namespace std;

int main(){
int x = 5;

auto printX = [x]() {
    cout << x << endl;
};
printX();  // Prints 5

}


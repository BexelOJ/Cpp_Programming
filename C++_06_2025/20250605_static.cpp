#include <iostream>

using namespace std;

void function(int g){
    static int f = 30;
    cout<<"f : "<<f<<endl;
    f++;
    cout<<"g : "<<g<<endl;
}

static int f = 20;

int main(){
static int a = 10;

cout<<"a : "<<a<<endl;
cout<<"g : "<<f<<endl;

function(f);
function(f);
function(f);
function(f);
return 0;
}



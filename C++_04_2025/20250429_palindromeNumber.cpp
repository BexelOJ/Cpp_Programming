#include <iostream>

using namespace std;

bool palin(int x){
  int n=0, l=0, dup = x;
  while(x>0){
    l = x%10;
    n = ((n*10)+l);
    x = x/10;    
  }
  if(dup == n){
    return 1;
  }
    else{
    return 0;
    }
}

int main(){
int x=0;
cin>>x;
cout<<palin(x)<<endl;
return 0;
}


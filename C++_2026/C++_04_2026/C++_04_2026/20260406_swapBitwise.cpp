#include <iostream>

void swap(int a, int b){
a = a^b;
b = b^a;
a = a^b;
std::cout<<"After Swwap "<<std::endl;
std::cout<<"a = "<<a<<"\nb = "<<b<<std::endl;
}

int main(){
int a=0, b=0;
std::cout<<"Enter two Numbers: "<<std::endl;
std::cin>>a>>b;
std::cout<<"Before Swap:"<<std::endl;
std::cout<<"a = "<<a<<"\nb = "<<b<<std::endl;
swap(a,b);
return 0;
}



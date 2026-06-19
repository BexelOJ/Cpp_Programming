#include <iostream>

void swapBitwise(int a, int b){
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
	std::cout<<"After Swap : \n";
	std::cout<<"x = "<<a<<"\ny = "<<b<<std::endl;
}

void swapNormal(int a, int b){
	a = a + b;
	b = a - b;
	a = a - b;
	std::cout<<"After Swap : \n";
	std::cout<<"x = "<<a<<"\ny = "<<b<<std::endl;
}

int main(){
	int x = 0;
	int y = 0;
	std::cout<<"Enter Two Integers : "<<std::endl;
	std::cin>>x>>y;

	std::cout<<"Before Swap : \n";
	std::cout<<"x = "<<x<<"\ny = "<<y<<std::endl;
	swapBitwise(x,y);
	swapNormal(x,y);
	return 0;
}



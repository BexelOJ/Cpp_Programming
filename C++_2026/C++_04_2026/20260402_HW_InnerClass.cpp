#include <iostream>

class Outer{
public:
	int x = 10;
	void showOuter(){
		std::cout<<"x = "<<x<<std::endl;
	}
	class Inner{
	public:
		int y = 20;
		void showInner(){
		std::cout<<"y = "<<y<<std::endl;
	}
	};
};

int main(){
	Outer o1;
	o1.showOuter();


	Outer::Inner I1;
	I1.showInner();

	return 0;
}




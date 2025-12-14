#include <iostream>

using namespace std; 

class add{
    int a;
    double c;
    int b;

public:
    add(int val_1 = 0, int val_2 = 0) :a(val_1), b(val_2) {
     std::cout<<"Parameterized Constructor called"<<std::endl;
    }

    static int addition(int a, int b){
        return a + b;
    }

    int subtraction(int a, int b) {
        return a - b;
    }

    ~add() {
         std::cout << "Destructor called" << std::endl;
    }  

};


int main() {
  
  add a1(3,4); // stored in Stack
  add* ptr = new add(5, 7); // stored in Heap

  int res_1 = a1.addition(30,40);
  int res_2 = ptr->addition(3,4);

  int (*fnPtr_1)(int, int);
  fnPtr_1 = add::addition;
  int fp_res_1 = fnPtr_1(12, 30);
  
  int (add::*fnPtr_2)(int, int);
  fnPtr_2 = &add::subtraction;
  int fp_res_2 = (a1.*fnPtr_2)(40, 5);

  std::cout << res_1 << std::endl;
  std::cout << res_2 << std::endl;
  std::cout << "fp_res_1 = " << fp_res_1 << std::endl;
  std::cout << "fp_res_2 = "<< fp_res_2  << std::endl;

  std::cout << "Size of Object of type add = " << sizeof(add) << std::endl;
  delete ptr;

  return 0;
}




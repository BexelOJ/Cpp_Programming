#include <iostream>

using namespace std;

class Base{

public:
   int a;
   int &ref;
   /*
   Base(int x){
         a = x;
         ref = a;
   }
   */

   Base(int x): a(x), ref(a) {}
};

int main(){
   Base b(10);
   Base* b1 = new Base(20);
   cout << b.a << " " << b.ref << endl;
   cout<< "Address of a: " << &b.a << endl;
   cout<< "Address of ref: " << &b.ref << endl;
   cout<<sizeof(b)<<endl;

   cout << b1->a << " " << b1->ref << endl;
   cout<< "Address of a: " << &b1->a << endl;
   cout<< "Address of ref: " << &b1->ref << endl;
   cout<<sizeof(*b1)<<endl;

   return 0;
}




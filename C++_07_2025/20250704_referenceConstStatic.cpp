#include <iostream>

class abc{
public:
    int a=20;
    int &ref = a;
    static const int sc;
    static int s;
};

int abc::s = 30;
const int abc::sc = 40;


int main(){
    abc* p1 = new abc();
    abc c;
    std::cout<<p1->a<<std::endl;
    std::cout<<p1->ref<<std::endl;
    std::cout<<p1->s<<std::endl;
    // c.s =45;
    std::cout<<p1->sc<<std::endl;
    
    std::cout<<&(p1->ref)<<std::endl;
    std::cout<<&(p1->a)<<std::endl;
    
    p1->a = 75;
    std::cout<<p1->ref<<std::endl;    
    std::cout<<&(p1->ref)<<std::endl;
    
    return 0;
}



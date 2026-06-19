#include <iostream>
#include <vector>

class Base{
    int s = 0;
public:
    std::vector<int> d;

    void append(int b){
        d.push_back(b);
    }

    /*
    void display(){
        for(int i=0; i<d.size(); i++){
        std::cout<<" Value at Index "<<i<<" : "<<d.at(i)<<std::endl;
        } */

    void display(){
        int size = 0;
        for(auto i : d){
        std::cout<<" Value at Index "<<size<<" : "<<i<<std::endl;
        size++;    
    }

    }
};

int main(){
    Base b1;
    Base* b2 = new Base();
    int size = 0, a = 0;
    std::cout<<"Enter the count of the elements you need to insert : "<<std::endl;

    std::cin>>size;

    for(int i=0; i<size; i++){
        std::cout<<"Enter the Integer values to store at Index "<<i<<" : "<<std::endl;
        std::cin>>a;
        b2->append(a);
    }

    b2->display();

    delete b2;

return 0;
}



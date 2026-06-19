#include <iostream>
#include <vector>

class Base{
    int j=0;
public:
    std::vector<int> vec;
    void append(int a){
        vec.push_back(a);
    }

    void display(){
        for(auto i : vec){
            std::cout<<"Value at Index "<<j<<" : "<<i<<std::endl;
            j++;
        }
    }

    bool empty(){
        bool l = false;
        if(vec.empty() == true){
            l = true;
            return l;
        }
        return 0;
    }
};

int main(){
    Base* b1 = new Base();
    int size = 0, n = 0;
    std::cout<<"Enter the size of the Vector: "<<std::endl;
    std::cin>>size;
    std::cout<<"Enter the "<<size<<" elements of the Vector: "<<std::endl;
    for(int i=0; i<size; i++){
        std::cin>>n;
        b1->append(n);
    }

    b1->display();

    if(b1->empty() == true){
        std::cout<<"Vector is Empty"<<std::endl;
    }
    else{
        std::cout<<"Vector is NOT Empty"<<std::endl;
    }

    delete b1;

    return 0;
}



#include <iostream>
#include <string>

class add{
    int a;
    int b;
public:
    add(int a,int b):a(a), b(b) {
    
    }
    const int addition(int a, int b)const { // const member function
        return a + b;
    }
    const int addition()const { // const member function
        return a + b;
}
};

static int non_member_addition(int c, int d) {

    return c+d;
}

int main() {
    add a1(2, 3);
    
    int res = a1.addition(4,5);
    int res_3 = a1.addition();
    
    std::cout<<res<<std::endl;
    std::cout << res_3 << std::endl;

    int res_2 = non_member_addition(10,20);
    std::cout << res_2 << std::endl;

    return 0;
}




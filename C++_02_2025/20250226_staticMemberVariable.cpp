#include <iostream>

using namespace std;

class Base{
    private:
        static const int s_a;
    public:
        const static int s_b = 20;  // static const and const static are both same 
        static const int s_e = 50;
        static constexpr int MAX_VALUE = 100;
        static int s_f;
};

class Derived: public Base{
    static int s_c;
public:
    static int s_d;
};

int Base::s_f = 60;

int main()
{
cout<<Base::s_b<<endl;

Base b1;
cout<<b1.s_b<<endl;
cout<<b1.s_e<<endl;
cout<<b1.MAX_VALUE<<endl;
cout<<Base::MAX_VALUE<<endl;
cout<<Base::s_f<<endl;
cout<<b1.s_f<<endl;

b1.s_f = 601;
Base b2;
cout<<b1.s_f<<endl;
cout<<b2.s_f<<endl;

Base::s_f = 602;
cout<<b1.s_f<<endl;
cout<<b2.s_f<<endl;

return 0;
}


/*

20
20
50
100
100
60
60
601
601
602
602

*/

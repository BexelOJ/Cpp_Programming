#include <iostream>

using namespace std;

class Base{
public:
// Static constant member variable
static const int MAX_VALUE = 100;

// Static function
static void printMaxValue() {
    std::cout << "Max Value: " << MAX_VALUE << std::endl;
}
};

class Derived: public Base{

};

const int Base::MAX_VALUE;

int main()
{
// Accessing static constant directly using the class name
std::cout << "Max Value: " << Base::MAX_VALUE << std::endl;

// Using static function
Base::printMaxValue();

Base b1;
cout<<b1.MAX_VALUE<<endl;
b1.printMaxValue();
return 0;
}



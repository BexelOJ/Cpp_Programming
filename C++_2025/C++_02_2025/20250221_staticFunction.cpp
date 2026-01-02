#include <iostream>

using namespace std;

class Master{
    static int count;
public:
    Master(){}
    static int counter(){
        count++;
        return count;
    }
};

int main()
{

Master m1;

return 0;
}

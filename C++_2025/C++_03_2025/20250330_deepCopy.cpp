#include <iostream>

using namespace std;

class ABC {
private:

public:
    int  size;
    int* ptr;
    
    ABC(int value) : size(value) {
        cout << "Parameterized Constructor Called" << endl;
        ptr = new int[size];
    }

    ABC(const ABC& other)
    {
        cout << "Copy Constructor Called" << endl;
        size = other.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = other.ptr[i];
        }
    }

    ~ABC()
    {
        delete[] ptr;
        cout <<"Destructor Called" << endl;
    }
};

int main()
{
    ABC* obj1 = new ABC(10);
    ABC* obj2 = new ABC(*obj1);

    delete obj1;
    delete obj2;

    return 0;
}

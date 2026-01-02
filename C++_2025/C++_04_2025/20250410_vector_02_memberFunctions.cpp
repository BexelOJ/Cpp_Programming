#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = { 1,2,3,4,5 };

    for (int i = 0; i < 5; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    // 1 2 3 4 5

    cout << "Front: " << vec.front() << endl;
    // Front: 1
    cout << "Front: " << vec.front() + vec[3] << endl;
    // Front: 5
    cout << "Back: " << vec.back() << endl;
    // Back: 5
    cout << vec.at(4) << endl;
    // 5

    try {
        // Accessing invalid index
        cout << "Element at index 5: " << vec.at(10) << endl;
    }
    catch (const out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    // Element at index 5: Caught exception: vector::_M_range_check: __n (which is 10) >= this->size() (which is 5)

    return 0;
}







#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec = { 1,2,3,4,5 };
    cout << vec[1] << endl;
    // 2

    //bool checkEmpty = vec.empty();
    if (vec.empty()) {
        std::cout << "Vector is Empty\n";
    }
    else {
        std::cout << "Vector is NOT Empty\n";
    }
    // Vector is NOT Empty

    int size = vec.size();
    cout << "Vector Size : "<<size << endl;
    // Vector Size : 5

    long int Maxsize = vec.max_size();
    cout << Maxsize << endl;
    // 2305843009213693951
    // Note: This is usually very large and not commonly used in everyday code.

    int capacity = vec.capacity();
    cout << "Vector Capacity : "<<capacity << endl;
    // Vector Capacity : 5

    reverse(vec.begin(), vec.end());
    for (int i = 0; i < 5; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    // 5 4 3 2 1
    
    vec.shrink_to_fit();
    size = vec.size();
    cout << "Vector Size : " << size << endl;
    size = vec.capacity();
    cout << "Vector Capacity : " << size << endl;
    // Vector Size : 5
    // Vector Capacity : 5

    vec.reserve(25);  //  capacity will change
    size = vec.size();
    cout << "Vector Size : " << size << endl;
    size = vec.capacity();
    cout << "Vector Capacity : " << size << endl;
    // Vector Size : 5
    // Vector Capacity : 25
    
    vec.resize(25);  // size will change 
    size = vec.size();
    cout << "Vector Size : " << size << endl;
    size = vec.capacity();
    cout << "Vector Capacity : " << size << endl;
    // Vector Size : 25
    // Vector Capacity : 25

    return 0;


}





#include <iostream>
#include <vector>
//#include <algorithm>
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

    vec.clear();

    if (vec.empty()) {
        std::cout << "Vector is Empty\n";
    }
    else {
        std::cout << "Vector is NOT Empty\n";
    }
    // Vector is Empty
    cout << "Size: "<<vec.size() << endl;
    cout << "Capacity: "<<vec.capacity() << endl;
    // Size: 0
    // Capacity: 5

    // Use of push_back()
    vec.push_back(10);
    int size = vec.size();
    cout << "Vector Size : " << size << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    // Vector Size : 1
    // Capacity: 5

    vec.push_back(20);
    vec.push_back(50);

    size = vec.size();
    cout << "Vector Size : " << size << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    // Vector Size : 3
    // Capacity: 5

    for (int i = 0; i < (vec.size()); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    // Use of insert()
    vec.insert(vec.begin(), 5);
    for (int i = 0; i < (vec.size()); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    
    vec.insert(vec.begin()+2, 15);
    for (int i = 0; i < (vec.size()); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    vector<int> v2 = { 30, 35 };
    vec.insert(vec.begin() + 4, v2.begin(), v2.end());
    for (int i = 0; i < (vec.size()); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    // Use of swap()
    std::vector<int> a = { 1, 2 };
    std::vector<int> b = { 10, 20 };
    cout << "Before Swap : " << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i]<<" ";
    }
    cout << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i]<<" ";
    }
    cout << endl;

    a.swap(b);  // a = {10, 20}, b = {1, 2}

    cout << "After Swap : " << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i]<<" ";
    }
    cout << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i]<<" ";
    }
    cout << endl;

    // Use of erase()
    std::vector<int> v = { 10, 20, 30, 40 };
    v.erase(v.begin() + 1);       // Removes 20 → v = {10, 30, 40}
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    v.erase(v.begin(), v.begin() + 2); // Removes 10 and 30 → v = {40}
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    std::vector<int> v8 = { 10, 20, 30, 40 };
    for (int i = 0; i < v8.size(); i++)
    {
        cout << v8[i] << " ";
    }
    cout << endl;

    v8.erase(v8.begin(), v8.begin() + 2);
    for (int i = 0; i < v8.size(); i++)
    {
        cout << v8[i] << " ";
    }
    cout << endl;
    
    // Use of pop_back()
    std::vector<int> v3 = { 100, 200, 300, 400};
    v3.pop_back();
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " ";
    }
    cout << endl;

    v3.pop_back();
    v3.pop_back();
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " ";
    }
    cout << endl;

    std::vector<int> src = { 1, 2, 3 };
    v.assign(src.begin(), src.end());  // v = {1, 2, 3}
    for (int i = 0; i < src.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    v2.assign(3, 3);
    for (int i = 0; i < src.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;

    return 0;
}





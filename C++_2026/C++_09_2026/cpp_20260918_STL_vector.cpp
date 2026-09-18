```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//---------------------------------------------------
// Helper function
//---------------------------------------------------
void printVector(const vector<int>& v, const string& name)
{
    cout << name << " : ";

    for (const int& value : v)
    {
        cout << value << " ";
    }

    cout << "\n";
}

//---------------------------------------------------
// main
//---------------------------------------------------
int main()
{
    //-----------------------------------------------
    // 1. Constructors
    //-----------------------------------------------

    vector<int> v1;

    vector<int> v2(5);

    vector<int> v3(5, 100);

    vector<int> v4 = { 10, 20, 30, 40, 50 };

    vector<int> v5(v4);

    vector<int> v6(v4.begin(), v4.end());


    printVector(v1, "v1");
    printVector(v2, "v2");
    printVector(v3, "v3");
    printVector(v4, "v4");
    printVector(v5, "v5");
    printVector(v6, "v6");


    //-----------------------------------------------
    // 2. Assignment
    //-----------------------------------------------

    vector<int> v7;

    v7 = { 1, 2, 3, 4, 5 };

    printVector(v7, "v7");


    //-----------------------------------------------
    // 3. assign()
    //-----------------------------------------------

    v7.assign(4, 25);

    printVector(v7, "After assign(4, 25)");


    //-----------------------------------------------
    // 4. Element Access
    //-----------------------------------------------

    vector<int> v = { 10, 20, 30, 40, 50 };

    cout << "\nElement Access\n";

    cout << "operator[] : " << v[2] << "\n";
    cout << "at()       : " << v.at(2) << "\n";
    cout << "front()    : " << v.front() << "\n";
    cout << "back()     : " << v.back() << "\n";
    cout << "data()     : " << v.data() << "\n";


    //-----------------------------------------------
    // 5. Iterators
    //-----------------------------------------------

    cout << "\nIterators\n";

    cout << "begin() : ";

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    cout << "cbegin() : ";

    for (auto it = v.cbegin(); it != v.cend(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    cout << "rbegin() : ";

    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    cout << "crbegin() : ";

    for (auto it = v.crbegin(); it != v.crend(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 6. Capacity
    //-----------------------------------------------

    cout << "\nCapacity\n";

    cout << "empty()        : " << v.empty() << "\n";
    cout << "size()         : " << v.size() << "\n";
    cout << "max_size()     : " << v.max_size() << "\n";
    cout << "capacity()     : " << v.capacity() << "\n";


    //-----------------------------------------------
    // 7. reserve()
    //-----------------------------------------------

    v.reserve(100);

    cout << "After reserve(100)\n";
    cout << "size()         : " << v.size() << "\n";
    cout << "capacity()     : " << v.capacity() << "\n";


    //-----------------------------------------------
    // 8. shrink_to_fit()
    //-----------------------------------------------

    v.shrink_to_fit();

    cout << "After shrink_to_fit()\n";
    cout << "size()         : " << v.size() << "\n";
    cout << "capacity()     : " << v.capacity() << "\n";


    //-----------------------------------------------
    // 9. push_back()
    //-----------------------------------------------

    v.push_back(60);

    printVector(v, "After push_back(60)");


    //-----------------------------------------------
    // 10. emplace_back()
    //-----------------------------------------------

    v.emplace_back(70);

    printVector(v, "After emplace_back(70)");


    //-----------------------------------------------
    // 11. pop_back()
    //-----------------------------------------------

    v.pop_back();

    printVector(v, "After pop_back()");


    //-----------------------------------------------
    // 12. insert()
    //-----------------------------------------------

    v.insert(v.begin() + 2, 25);

    printVector(v, "After insert()");


    //-----------------------------------------------
    // 13. insert() multiple elements
    //-----------------------------------------------

    v.insert(v.begin(), 3, 5);

    printVector(v, "After inserting 3 copies");


    //-----------------------------------------------
    // 14. insert() range
    //-----------------------------------------------

    vector<int> temp = { 100, 200, 300 };

    v.insert(v.end(), temp.begin(), temp.end());

    printVector(v, "After range insert");


    //-----------------------------------------------
    // 15. emplace()
    //-----------------------------------------------

    v.emplace(v.begin() + 1, 999);

    printVector(v, "After emplace()");


    //-----------------------------------------------
    // 16. erase()
    //-----------------------------------------------

    v.erase(v.begin() + 1);

    printVector(v, "After erase()");


    //-----------------------------------------------
    // 17. erase() range
    //-----------------------------------------------

    v.erase(v.begin(), v.begin() + 2);

    printVector(v, "After erase(range)");


    //-----------------------------------------------
    // 18. resize()
    //-----------------------------------------------

    v.resize(5);

    printVector(v, "After resize(5)");


    //-----------------------------------------------
    // 19. resize() with value
    //-----------------------------------------------

    v.resize(10, 500);

    printVector(v, "After resize(10, 500)");


    //-----------------------------------------------
    // 20. clear()
    //-----------------------------------------------

    v.clear();

    printVector(v, "After clear()");

    cout << "size()         : " << v.size() << "\n";
    cout << "capacity()     : " << v.capacity() << "\n";


    //-----------------------------------------------
    // 21. swap()
    //-----------------------------------------------

    vector<int> a = { 1, 2, 3 };

    vector<int> b = { 10, 20, 30, 40 };

    cout << "\nBefore swap()\n";

    printVector(a, "a");
    printVector(b, "b");

    a.swap(b);

    cout << "After swap()\n";

    printVector(a, "a");
    printVector(b, "b");


    //-----------------------------------------------
    // 22. get_allocator()
    //-----------------------------------------------

    auto allocator = a.get_allocator();

    int* memory = allocator.allocate(1);

    allocator.construct(memory, 500);

    cout << "\nget_allocator() : " << *memory << "\n";

    allocator.destroy(memory);

    allocator.deallocate(memory, 1);


    //-----------------------------------------------
    // 23. Comparison
    //-----------------------------------------------

    vector<int> x = { 1, 2, 3 };

    vector<int> y = { 1, 2, 3 };

    vector<int> z = { 1, 2, 4 };

    cout << "\nComparison\n";

    cout << "x == y         : " << (x == y) << "\n";
    cout << "x != z         : " << (x != z) << "\n";
    cout << "x < z          : " << (x < z) << "\n";


    //-----------------------------------------------
    // 24. Non-member swap()
    //-----------------------------------------------

    swap(x, z);

    printVector(x, "x after std::swap()");
    printVector(z, "z after std::swap()");


    //-----------------------------------------------
    // End
    //-----------------------------------------------

    return 0;
}



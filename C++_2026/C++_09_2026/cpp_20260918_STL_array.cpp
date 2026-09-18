#include <array>
#include <iostream>
#include <string>

using namespace std;

//---------------------------------------------------
// Helper function
//---------------------------------------------------
void printArray(const array<int, 5>& arr, const string& name)
{
    cout << name << " : ";

    for (const int& value : arr)
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
    // 1. Constructors / Initialization
    //-----------------------------------------------

    array<int, 5> a1;

    array<int, 5> a2 = { 10, 20, 30, 40, 50 };

    array<int, 5> a3 = { 1, 2, 3 };

    array<int, 5> a4(a2);

    array<int, 5> a5 = a2;


    printArray(a1, "a1");
    printArray(a2, "a2");
    printArray(a3, "a3");
    printArray(a4, "a4");
    printArray(a5, "a5");


    //-----------------------------------------------
    // 2. Assignment
    //-----------------------------------------------

    a1 = a2;

    printArray(a1, "a1 after assignment");


    //-----------------------------------------------
    // 3. Element Access
    //-----------------------------------------------

    cout << "\nElement Access\n";

    cout << "operator[] : " << a2[2] << "\n";
    cout << "at()        : " << a2.at(2) << "\n";
    cout << "front()     : " << a2.front() << "\n";
    cout << "back()      : " << a2.back() << "\n";
    cout << "data()      : " << a2.data() << "\n";


    //-----------------------------------------------
    // 4. Iterators
    //-----------------------------------------------

    cout << "\nIterators\n";

    cout << "begin() : ";

    for (auto it = a2.begin(); it != a2.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    cout << "cbegin() : ";

    for (auto it = a2.cbegin(); it != a2.cend(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    cout << "rbegin() : ";

    for (auto it = a2.rbegin(); it != a2.rend(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    cout << "crbegin() : ";

    for (auto it = a2.crbegin(); it != a2.crend(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 5. Capacity
    //-----------------------------------------------

    cout << "\nCapacity\n";

    cout << "empty()    : " << a2.empty() << "\n";
    cout << "size()     : " << a2.size() << "\n";
    cout << "max_size() : " << a2.max_size() << "\n";


    //-----------------------------------------------
    // 6. fill()
    //-----------------------------------------------

    a3.fill(100);

    printArray(a3, "After fill(100)");


    //-----------------------------------------------
    // 7. swap()
    //-----------------------------------------------

    array<int, 5> a6 = { 1, 2, 3, 4, 5 };

    array<int, 5> a7 = { 10, 20, 30, 40, 50 };

    cout << "\nBefore swap()\n";

    printArray(a6, "a6");
    printArray(a7, "a7");

    a6.swap(a7);

    cout << "After swap()\n";

    printArray(a6, "a6");
    printArray(a7, "a7");


    //-----------------------------------------------
    // 8. Non-member swap()
    //-----------------------------------------------

    swap(a6, a7);

    cout << "\nAfter std::swap()\n";

    printArray(a6, "a6");
    printArray(a7, "a7");


    //-----------------------------------------------
    // 9. Data modification through iterator
    //-----------------------------------------------

    auto it = a2.begin();

    *it = 999;

    printArray(a2, "After iterator modification");


    //-----------------------------------------------
    // 10. Range-based for loop
    //-----------------------------------------------

    cout << "\nRange-based for loop\n";

    for (const int& value : a2)
    {
        cout << value << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 11. Structured binding
    //-----------------------------------------------

    auto [x, y, z, p, q] = a2;

    cout << "\nStructured Binding\n";

    cout << "x : " << x << "\n";
    cout << "y : " << y << "\n";
    cout << "z : " << z << "\n";
    cout << "p : " << p << "\n";
    cout << "q : " << q << "\n";


    //-----------------------------------------------
    // 12. Comparison
    //-----------------------------------------------

    array<int, 3> c1 = { 1, 2, 3 };

    array<int, 3> c2 = { 1, 2, 3 };

    array<int, 3> c3 = { 1, 2, 4 };

    cout << "\nComparison\n";

    cout << "c1 == c2 : " << (c1 == c2) << "\n";
    cout << "c1 != c3 : " << (c1 != c3) << "\n";
    cout << "c1 < c3  : " << (c1 < c3) << "\n";


    //-----------------------------------------------
    // 13. get()
    //-----------------------------------------------

    cout << "\nstd::get()\n";

    cout << "get<0>() : " << get<0>(c1) << "\n";
    cout << "get<1>() : " << get<1>(c1) << "\n";
    cout << "get<2>() : " << get<2>(c1) << "\n";


    //-----------------------------------------------
    // End
    //-----------------------------------------------

    return 0;
}


/*
* std::array API covered

Category	       Functions

Initialization	     {}, copy construction, assignment

Element access	     operator[], at(), front(), back(), data()

Iterators	        begin(), end()
Const iterators	  cbegin(), cend()
Reverse iterators	  rbegin(), rend()
Const reverse	     crbegin(), crend()

Capacity	           empty(), size(), max_size()
Modification	     fill()
Exchange	           swap()
Non-member	        std::swap()
Utilities	        std::get()


One important difference from vector:

std::array has no 
push_back(), pop_back(), insert(), erase(), 
resize(), reserve(), or capacity(), 

because its size is fixed at compile time.

Also, 
std::array<int, 5> means exactly 5 integers. 
The 5 is part of the type.

//---------------------------------------------------
 Output:
//---------------------------------------------------

a1 : -336107088 65535 -1654564260 65535 656
a2 : 10 20 30 40 50
a3 : 1 2 3 0 0
a4 : 10 20 30 40 50
a5 : 10 20 30 40 50
a1 after assignment : 10 20 30 40 50

Element Access
operator[] : 30
at()        : 30
front()     : 10
back()      : 50
data()      : 0xffffebf76968

Iterators
begin() : 10 20 30 40 50
cbegin() : 10 20 30 40 50
rbegin() : 50 40 30 20 10
crbegin() : 50 40 30 20 10

Capacity
empty()    : 0
size()     : 5
max_size() : 5
After fill(100) : 100 100 100 100 100

Before swap()
a6 : 1 2 3 4 5
a7 : 10 20 30 40 50
After swap()
a6 : 10 20 30 40 50
a7 : 1 2 3 4 5

After std::swap()
a6 : 1 2 3 4 5
a7 : 10 20 30 40 50
After iterator modification : 999 20 30 40 50

Range-based for loop
999 20 30 40 50

Structured Binding
x : 999
y : 20
z : 30
p : 40
q : 50

Comparison
c1 == c2 : 1
c1 != c3 : 1
c1 < c3  : 1

std::get()
get<0>() : 1
get<1>() : 2
get<2>() : 3


*/





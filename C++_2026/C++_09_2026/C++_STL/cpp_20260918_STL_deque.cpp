#include <iostream>
#include <deque>
#include <string>

using namespace std;

//---------------------------------------------------
// Helper function
//---------------------------------------------------
void printDeque(const deque<int>& d, const string& name)
{
    cout << name << " : ";

    for (int value : d)
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

    deque<int> d1;

    deque<int> d2(5, 10);

    deque<int> d3 = { 10, 20, 30, 40, 50 };

    deque<int> d4(d3);

    deque<int> d5(d3.begin(), d3.end());


    printDeque(d1, "d1");
    printDeque(d2, "d2");
    printDeque(d3, "d3");
    printDeque(d4, "d4");
    printDeque(d5, "d5");


    //-----------------------------------------------
    // 2. Assignment
    //-----------------------------------------------

    deque<int> d6;

    d6 = d3;

    printDeque(d6, "d6");


    //-----------------------------------------------
    // 3. Element Access
    //-----------------------------------------------

    cout << "\nElement Access\n";

    cout << "operator[] : " << d3[2] << "\n";
    cout << "at()       : " << d3.at(2) << "\n";
    cout << "front()    : " << d3.front() << "\n";
    cout << "back()     : " << d3.back() << "\n";


    //-----------------------------------------------
    // 4. data()
    //-----------------------------------------------
    // deque does NOT provide data()
    //
    // Unlike vector and array, deque storage
    // is not guaranteed to be contiguous.


    //-----------------------------------------------
    // 5. empty()
    //-----------------------------------------------

    cout << "\nCapacity\n";

    cout << "empty()    : " << d3.empty() << "\n";
    cout << "size()     : " << d3.size() << "\n";
    cout << "max_size() : " << d3.max_size() << "\n";


    //-----------------------------------------------
    // 6. push_back()
    //-----------------------------------------------

    d3.push_back(60);

    printDeque(d3, "After push_back(60)");


    //-----------------------------------------------
    // 7. emplace_back()
    //-----------------------------------------------

    d3.emplace_back(70);

    printDeque(d3, "After emplace_back(70)");


    //-----------------------------------------------
    // 8. push_front()
    //-----------------------------------------------

    d3.push_front(0);

    printDeque(d3, "After push_front(0)");


    //-----------------------------------------------
    // 9. emplace_front()
    //-----------------------------------------------

    d3.emplace_front(-10);

    printDeque(d3, "After emplace_front(-10)");


    //-----------------------------------------------
    // 10. pop_back()
    //-----------------------------------------------

    d3.pop_back();

    printDeque(d3, "After pop_back()");


    //-----------------------------------------------
    // 11. pop_front()
    //-----------------------------------------------

    d3.pop_front();

    printDeque(d3, "After pop_front()");


    //-----------------------------------------------
    // 12. insert()
    //-----------------------------------------------

    d3.insert(d3.begin() + 2, 25);

    printDeque(d3, "After insert(25)");


    //-----------------------------------------------
    // 13. insert() multiple values
    //-----------------------------------------------

    d3.insert(d3.begin() + 2, 3, 15);

    printDeque(d3, "After insert(3, 15)");


    //-----------------------------------------------
    // 14. insert() range
    //-----------------------------------------------

    deque<int> source = { 100, 200, 300 };

    d3.insert(d3.end(), source.begin(), source.end());

    printDeque(d3, "After range insert");


    //-----------------------------------------------
    // 15. emplace()
    //-----------------------------------------------

    d3.emplace(d3.begin() + 1, 5);

    printDeque(d3, "After emplace(5)");


    //-----------------------------------------------
    // 16. erase()
    //-----------------------------------------------

    d3.erase(d3.begin() + 1);

    printDeque(d3, "After erase()");


    //-----------------------------------------------
    // 17. erase() range
    //-----------------------------------------------

    d3.erase(d3.begin() + 1, d3.begin() + 3);

    printDeque(d3, "After range erase");


    //-----------------------------------------------
    // 18. resize()
    //-----------------------------------------------

    d3.resize(10);

    printDeque(d3, "After resize(10)");

    cout << "size() : " << d3.size() << "\n";


    //-----------------------------------------------
    // 19. resize() with value
    //-----------------------------------------------

    d3.resize(15, 99);

    printDeque(d3, "After resize(15, 99)");


    //-----------------------------------------------
    // 20. resize() smaller
    //-----------------------------------------------

    d3.resize(5);

    printDeque(d3, "After resize(5)");


    //-----------------------------------------------
    // 21. shrink_to_fit()
    //-----------------------------------------------

    d3.shrink_to_fit();

    printDeque(d3, "After shrink_to_fit()");


    //-----------------------------------------------
    // 22. clear()
    //-----------------------------------------------

    deque<int> clearDeque = { 10, 20, 30, 40 };

    clearDeque.clear();

    cout << "\nAfter clear()\n";

    cout << "empty() : " << clearDeque.empty() << "\n";
    cout << "size()  : " << clearDeque.size() << "\n";


    //-----------------------------------------------
    // 23. Iterators
    //-----------------------------------------------

    deque<int> d7 = { 10, 20, 30, 40, 50 };

    cout << "\nIterators\n";

    cout << "begin()   : " << *d7.begin() << "\n";
    cout << "end()     : " << *(d7.end() - 1) << "\n";

    cout << "cbegin()  : " << *d7.cbegin() << "\n";
    cout << "cend()    : " << *(d7.cend() - 1) << "\n";

    cout << "rbegin()  : " << *d7.rbegin() << "\n";
    cout << "rend()    : " << *(d7.rend() - 1) << "\n";

    cout << "crbegin() : " << *d7.crbegin() << "\n";
    cout << "crend()   : " << *(d7.crend() - 1) << "\n";


    //-----------------------------------------------
    // 24. Iterator traversal
    //-----------------------------------------------

    cout << "\nForward Traversal\n";

    for (auto it = d7.begin(); it != d7.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 25. Reverse traversal
    //-----------------------------------------------

    cout << "\nReverse Traversal\n";

    for (auto it = d7.rbegin(); it != d7.rend(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 26. Const iterators
    //-----------------------------------------------

    cout << "\nConst Iterator Traversal\n";

    for (auto it = d7.cbegin(); it != d7.cend(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 27. Range-based for loop
    //-----------------------------------------------

    cout << "\nRange-based For\n";

    for (int value : d7)
    {
        cout << value << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 28. Modify elements using iterator
    //-----------------------------------------------

    for (auto it = d7.begin(); it != d7.end(); ++it)
    {
        *it *= 2;
    }

    printDeque(d7, "After iterator modification");


    //-----------------------------------------------
    // 29. swap()
    //-----------------------------------------------

    deque<int> d8 = { 1, 2, 3 };
    deque<int> d9 = { 100, 200, 300 };

    cout << "\nBefore swap()\n";

    printDeque(d8, "d8");
    printDeque(d9, "d9");

    d8.swap(d9);

    cout << "After swap()\n";

    printDeque(d8, "d8");
    printDeque(d9, "d9");


    //-----------------------------------------------
    // 30. Non-member std::swap()
    //-----------------------------------------------

    swap(d8, d9);

    cout << "\nAfter std::swap()\n";

    printDeque(d8, "d8");
    printDeque(d9, "d9");


    //-----------------------------------------------
    // 31. Comparison
    //-----------------------------------------------

    deque<int> d10 = { 10, 20, 30 };
    deque<int> d11 = { 10, 20, 30 };
    deque<int> d12 = { 10, 20, 40 };

    cout << "\nComparison\n";

    cout << "d10 == d11 : " << (d10 == d11) << "\n";
    cout << "d10 != d12 : " << (d10 != d12) << "\n";
    cout << "d10 <  d12 : " << (d10 < d12) << "\n";


    //-----------------------------------------------
    // 32. Front and back modification
    //-----------------------------------------------

    d10.front() = 100;
    d10.back() = 300;

    printDeque(d10, "After front/back modification");


    //-----------------------------------------------
    // 33. deque supports both ends
    //-----------------------------------------------

    deque<int> bothEnds;

    bothEnds.push_front(20);
    bothEnds.push_front(10);

    bothEnds.push_back(30);
    bothEnds.push_back(40);

    printDeque(bothEnds, "Both ends");


    //-----------------------------------------------
    // End
    //-----------------------------------------------

    return 0;
}


/*
//---------------------------------------------------
deque functions covered

Category	       Functions

Construction	deque(), size/value, initializer-list, 
copy, range

Access	       operator[], at(), front(), back()
Capacity	       empty(), size(), max_size(), resize(), 
shrink_to_fit()

Front operations	push_front(), emplace_front(), 
pop_front()
Back operations	push_back(), emplace_back(), 
pop_back()

Insertion	      insert(), emplace()
Removal	         erase(), clear()

Iterators	    begin/end, cbegin/cend, rbegin/rend, 
crbegin/crend

Swap	        swap(), std::swap()
Comparison	  ==, !=, <
Traversal	  iterator, reverse iterator, range-for


//---------------------------------------------------
Important difference from vector: 
deque does not have data(), reserve(), or capacity(). 
Its elements are not required to be stored 
contiguously.

Also, unlike queue, 
deque is a full sequence container, 
so you can iterate, insert, erase, 
and access elements by index.

//---------------------------------------------------
 Output:
//---------------------------------------------------

d1 :
d2 : 10 10 10 10 10
d3 : 10 20 30 40 50
d4 : 10 20 30 40 50
d5 : 10 20 30 40 50
d6 : 10 20 30 40 50

Element Access
operator[] : 30
at()       : 30
front()    : 10
back()     : 50

Capacity
empty()    : 0
size()     : 5
max_size() : 2305843009213693951
After push_back(60) : 10 20 30 40 50 60
After emplace_back(70) : 10 20 30 40 50 60 70
After push_front(0) : 0 10 20 30 40 50 60 70
After emplace_front(-10) : -10 0 10 20 30 40 50 60 70
After pop_back() : -10 0 10 20 30 40 50 60
After pop_front() : 0 10 20 30 40 50 60
After insert(25) : 0 10 25 20 30 40 50 60
After insert(3, 15) : 0 10 15 15 15 25 20 30 40 50 60
After range insert : 0 10 15 15 15 25 20 30 40 50 60 100 200 300
After emplace(5) : 0 5 10 15 15 15 25 20 30 40 50 60 100 200 300
After erase() : 0 10 15 15 15 25 20 30 40 50 60 100 200 300
After range erase : 0 15 15 25 20 30 40 50 60 100 200 300
After resize(10) : 0 15 15 25 20 30 40 50 60 100
size() : 10
After resize(15, 99) : 0 15 15 25 20 30 40 50 60 100 99 99 99 99 99
After resize(5) : 0 15 15 25 20
After shrink_to_fit() : 0 15 15 25 20

After clear()
empty() : 1
size()  : 0

Iterators
begin()   : 10
end()     : 50
cbegin()  : 10
cend()    : 50
rbegin()  : 50
rend()    : 10
crbegin() : 50
crend()   : 10

Forward Traversal
10 20 30 40 50

Reverse Traversal
50 40 30 20 10

Const Iterator Traversal
10 20 30 40 50

Range-based For
10 20 30 40 50
After iterator modification : 20 40 60 80 100

Before swap()
d8 : 1 2 3
d9 : 100 200 300
After swap()
d8 : 100 200 300
d9 : 1 2 3

After std::swap()
d8 : 1 2 3
d9 : 100 200 300

Comparison
d10 == d11 : 1
d10 != d12 : 1
d10 <  d12 : 1
After front/back modification : 100 20 300
Both ends : 10 20 30 40


//---------------------------------------------------
*/





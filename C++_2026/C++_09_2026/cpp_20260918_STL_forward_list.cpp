#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

//---------------------------------------------------
// Helper function
//---------------------------------------------------
void printForwardList(const forward_list<int>& fl,
    const string& name)
{
    cout << name << " : ";

    for (int value : fl)
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

    forward_list<int> fl1;

    forward_list<int> fl2(5, 10);

    forward_list<int> fl3 = { 10, 20, 30, 40, 50 };

    forward_list<int> fl4(fl3);

    forward_list<int> fl5(fl3.begin(), fl3.end());


    printForwardList(fl1, "fl1");
    printForwardList(fl2, "fl2");
    printForwardList(fl3, "fl3");
    printForwardList(fl4, "fl4");
    printForwardList(fl5, "fl5");


    //-----------------------------------------------
    // 2. Assignment
    //-----------------------------------------------

    forward_list<int> fl6;

    fl6 = fl3;

    printForwardList(fl6, "fl6");


    //-----------------------------------------------
    // 3. Element Access
    //-----------------------------------------------

    cout << "\nElement Access\n";

    cout << "front() : " << fl3.front() << "\n";


    //-----------------------------------------------
    // 4. Unsupported element access
    //-----------------------------------------------
    // forward_list does NOT provide:
    //
    // operator[]
    // at()
    // back()


    //-----------------------------------------------
    // 5. Capacity
    //-----------------------------------------------

    cout << "\nCapacity\n";

    cout << "empty()    : " << fl3.empty() << "\n";
    cout << "max_size() : " << fl3.max_size() << "\n";


    //-----------------------------------------------
    // 6. size()
    //-----------------------------------------------
    // forward_list intentionally does NOT provide
    // size().
    //
    // std::distance() can be used when required.

    cout << "distance() : "
        << distance(fl3.begin(), fl3.end()) << "\n";


    //-----------------------------------------------
    // 7. push_front()
    //-----------------------------------------------

    fl3.push_front(0);

    printForwardList(fl3, "After push_front(0)");


    //-----------------------------------------------
    // 8. emplace_front()
    //-----------------------------------------------

    fl3.emplace_front(-10);

    printForwardList(fl3, "After emplace_front(-10)");


    //-----------------------------------------------
    // 9. pop_front()
    //-----------------------------------------------

    fl3.pop_front();

    printForwardList(fl3, "After pop_front()");


    //-----------------------------------------------
    // 10. before_begin()
    //-----------------------------------------------

    cout << "\nSpecial Iterator\n";

    auto before = fl3.before_begin();

    cout << "Element after before_begin() : "
        << *next(before) << "\n";


    //-----------------------------------------------
    // 11. begin()
    //-----------------------------------------------

    cout << "begin() : " << *fl3.begin() << "\n";


    //-----------------------------------------------
    // 12. cbegin()
    //-----------------------------------------------

    cout << "cbegin() : " << *fl3.cbegin() << "\n";


    //-----------------------------------------------
    // 13. insert_after()
    //-----------------------------------------------

    fl3.insert_after(fl3.before_begin(), 5);

    printForwardList(fl3, "After insert_after(5)");


    //-----------------------------------------------
    // 14. insert_after() multiple values
    //-----------------------------------------------

    fl3.insert_after(fl3.before_begin(), 3, 1);

    printForwardList(fl3, "After insert_after(3, 1)");


    //-----------------------------------------------
    // 15. insert_after() range
    //-----------------------------------------------

    forward_list<int> source = { 100, 200, 300 };

    auto position = fl3.before_begin();

    fl3.insert_after(position, source.begin(), source.end());

    printForwardList(fl3, "After range insert_after");


    //-----------------------------------------------
    // 16. emplace_after()
    //-----------------------------------------------

    fl3.emplace_after(fl3.before_begin(), 999);

    printForwardList(fl3, "After emplace_after(999)");


    //-----------------------------------------------
    // 17. erase_after()
    //-----------------------------------------------

    fl3.erase_after(fl3.before_begin());

    printForwardList(fl3, "After erase_after()");


    //-----------------------------------------------
    // 18. erase_after() range
    //-----------------------------------------------

    forward_list<int> fl7 = { 10, 20, 30, 40, 50 };

    auto first = fl7.before_begin();
    auto last = next(fl7.begin(), 3);

    fl7.erase_after(first, last);

    printForwardList(fl7, "After range erase_after()");


    //-----------------------------------------------
    // 19. remove()
    //-----------------------------------------------

    forward_list<int> fl8 = { 10, 20, 10, 30, 10, 40 };

    fl8.remove(10);

    printForwardList(fl8, "After remove(10)");


    //-----------------------------------------------
    // 20. remove_if()
    //-----------------------------------------------

    forward_list<int> fl9 = { 1, 2, 3, 4, 5, 6 };

    fl9.remove_if([](int value)
        {
            return value % 2 == 0;
        });

    printForwardList(fl9, "After remove_if(even)");


    //-----------------------------------------------
    // 21. unique()
    //-----------------------------------------------

    forward_list<int> fl10 =
    {
        10, 10, 20, 20, 20, 30, 30, 40
    };

    fl10.unique();

    printForwardList(fl10, "After unique()");


    //-----------------------------------------------
    // 22. sort()
    //-----------------------------------------------

    forward_list<int> fl11 =
    {
        50, 10, 40, 20, 30
    };

    fl11.sort();

    printForwardList(fl11, "After sort()");


    //-----------------------------------------------
    // 23. sort() descending
    //-----------------------------------------------

    fl11.sort(greater<int>());

    printForwardList(fl11, "After descending sort");


    //-----------------------------------------------
    // 24. reverse()
    //-----------------------------------------------

    fl11.reverse();

    printForwardList(fl11, "After reverse()");


    //-----------------------------------------------
    // 25. merge()
    //-----------------------------------------------

    forward_list<int> fl12 =
    {
        10, 30, 50
    };

    forward_list<int> fl13 =
    {
        20, 40, 60
    };

    fl12.merge(fl13);

    printForwardList(fl12, "After merge()");
    printForwardList(fl13, "fl13");


    //-----------------------------------------------
    // 26. merge() descending
    //-----------------------------------------------

    forward_list<int> fl14 =
    {
        60, 40, 20
    };

    forward_list<int> fl15 =
    {
        50, 30, 10
    };

    fl14.merge(fl15, greater<int>());

    printForwardList(fl14, "After descending merge");


    //-----------------------------------------------
    // 27. splice_after() entire list
    //-----------------------------------------------

    forward_list<int> fl16 =
    {
        10, 20, 30
    };

    forward_list<int> fl17 =
    {
        100, 200, 300
    };

    fl16.splice_after(fl16.before_begin(), fl17);

    printForwardList(fl16, "After splice_after()");
    printForwardList(fl17, "fl17");


    //-----------------------------------------------
    // 28. splice_after() single element
    //-----------------------------------------------

    forward_list<int> fl18 =
    {
        1, 2, 3
    };

    forward_list<int> fl19 =
    {
        10, 20, 30
    };

    auto sourcePosition = fl19.begin();

    fl18.splice_after(fl18.before_begin(),
        fl19,
        sourcePosition);

    printForwardList(fl18, "After single splice_after()");
    printForwardList(fl19, "fl19");


    //-----------------------------------------------
    // 29. splice_after() range
    //-----------------------------------------------

    forward_list<int> fl20 =
    {
        1, 2, 3
    };

    forward_list<int> fl21 =
    {
        10, 20, 30, 40, 50
    };

    auto rangeFirst = fl21.before_begin();
    auto rangeLast = next(fl21.begin(), 4);

    fl20.splice_after(fl20.before_begin(),
        fl21,
        rangeFirst,
        rangeLast);

    printForwardList(fl20, "After range splice_after()");
    printForwardList(fl21, "fl21");


    //-----------------------------------------------
    // 30. Iterators
    //-----------------------------------------------

    forward_list<int> fl22 =
    {
        10, 20, 30, 40, 50
    };

    cout << "\nIterators\n";

    cout << "begin()   : " << *fl22.begin() << "\n";
    cout << "cbegin()  : " << *fl22.cbegin() << "\n";


    //-----------------------------------------------
    // 31. Forward traversal
    //-----------------------------------------------

    cout << "\nForward Traversal\n";

    for (auto it = fl22.begin(); it != fl22.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 32. Const iterator traversal
    //-----------------------------------------------

    cout << "\nConst Iterator Traversal\n";

    for (auto it = fl22.cbegin(); it != fl22.cend(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 33. Range-based for loop
    //-----------------------------------------------

    cout << "\nRange-based For\n";

    for (int value : fl22)
    {
        cout << value << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 34. Modify elements using iterator
    //-----------------------------------------------

    for (auto it = fl22.begin(); it != fl22.end(); ++it)
    {
        *it *= 2;
    }

    printForwardList(fl22, "After iterator modification");


    //-----------------------------------------------
    // 35. resize()
    //-----------------------------------------------

    forward_list<int> fl23 =
    {
        10, 20, 30, 40, 50
    };

    fl23.resize(3);

    printForwardList(fl23, "After resize(3)");


    //-----------------------------------------------
    // 36. resize() with value
    //-----------------------------------------------

    fl23.resize(6, 99);

    printForwardList(fl23, "After resize(6, 99)");


    //-----------------------------------------------
    // 37. clear()
    //-----------------------------------------------

    forward_list<int> clearList =
    {
        10, 20, 30, 40
    };

    clearList.clear();

    cout << "\nAfter clear()\n";

    cout << "empty() : " << clearList.empty() << "\n";


    //-----------------------------------------------
    // 38. swap()
    //-----------------------------------------------

    forward_list<int> fl24 =
    {
        1, 2, 3
    };

    forward_list<int> fl25 =
    {
        100, 200, 300
    };

    cout << "\nBefore swap()\n";

    printForwardList(fl24, "fl24");
    printForwardList(fl25, "fl25");

    fl24.swap(fl25);

    cout << "After swap()\n";

    printForwardList(fl24, "fl24");
    printForwardList(fl25, "fl25");


    //-----------------------------------------------
    // 39. Non-member std::swap()
    //-----------------------------------------------

    swap(fl24, fl25);

    cout << "\nAfter std::swap()\n";

    printForwardList(fl24, "fl24");
    printForwardList(fl25, "fl25");


    //-----------------------------------------------
    // 40. Comparison
    //-----------------------------------------------

    forward_list<int> fl26 =
    {
        10, 20, 30
    };

    forward_list<int> fl27 =
    {
        10, 20, 30
    };

    forward_list<int> fl28 =
    {
        10, 20, 40
    };

    cout << "\nComparison\n";

    cout << "fl26 == fl27 : " << (fl26 == fl27) << "\n";
    cout << "fl26 != fl28 : " << (fl26 != fl28) << "\n";
    cout << "fl26 <  fl28 : " << (fl26 < fl28) << "\n";


    //-----------------------------------------------
    // 41. Clearing a forward_list
    //-----------------------------------------------

    forward_list<int> clearAll =
    {
        10, 20, 30
    };

    clearAll.clear();

    cout << "\nAfter clearing forward_list\n";

    cout << "empty() : " << clearAll.empty() << "\n";


    //-----------------------------------------------
    // End
    //-----------------------------------------------

    return 0;
}



/*
std::forward_list

This is the singly linked-list container, 
so there are a few important differences from 
std::list: 
it only moves forward, has no size(), no back(), 
and uses before_begin() / insert_after() / 
erase_after().

NO  operator[]
NO  at()
NO  back()
NO  size()
NO  push_back()
NO  pop_back()
NO  reverse iterators

The most important functions to remember 
for forward_list are 
before_begin(), insert_after(), 
erase_after(), and splice_after().

//---------------------------------------------------
forward_list functions covered

Category	       Functions

Construction	 constructors, copy, range, assignment

Access	       front()
Capacity	       empty(), max_size()

Insertion	    push_front(), emplace_front(), 
insert_after(), emplace_after()

Removal	       pop_front(), erase_after(), 
remove(), remove_if(), clear()

Size	          resize()

Iterators	    before_begin(), begin/end, 
cbefore_begin(), cbegin/cend

List operations	unique(), sort(), reverse(), 
merge(), splice_after()

Swap	          swap(), std::swap()
Comparison	    ==, !=, <


//---------------------------------------------------
 Output:
//---------------------------------------------------

fl1 :
fl2 : 10 10 10 10 10
fl3 : 10 20 30 40 50
fl4 : 10 20 30 40 50
fl5 : 10 20 30 40 50
fl6 : 10 20 30 40 50

Element Access
front() : 10

Capacity
empty()    : 0
max_size() : 576460752303423487
distance() : 5
After push_front(0) : 0 10 20 30 40 50
After emplace_front(-10) : -10 0 10 20 30 40 50
After pop_front() : 0 10 20 30 40 50

Special Iterator
Element after before_begin() : 0
begin() : 0
cbegin() : 0
After insert_after(5) : 5 0 10 20 30 40 50
After insert_after(3, 1) : 1 1 1 5 0 10 20 30 40 50
After range insert_after : 100 200 300 1 1 1 5 0 10 20 30 40 50
After emplace_after(999) : 999 100 200 300 1 1 1 5 0 10 20 30 40 50
After erase_after() : 100 200 300 1 1 1 5 0 10 20 30 40 50
After range erase_after() : 40 50
After remove(10) : 20 30 40
After remove_if(even) : 1 3 5
After unique() : 10 20 30 40
After sort() : 10 20 30 40 50
After descending sort : 50 40 30 20 10
After reverse() : 10 20 30 40 50
After merge() : 10 20 30 40 50 60
fl13 :
After descending merge : 60 50 40 30 20 10
After splice_after() : 100 200 300 10 20 30
fl17 :
After single splice_after() : 20 1 2 3
fl19 : 10 30
After range splice_after() : 10 20 30 40 1 2 3
fl21 : 50

Iterators
begin()   : 10
cbegin()  : 10

Forward Traversal
10 20 30 40 50

Const Iterator Traversal
10 20 30 40 50

Range-based For
10 20 30 40 50
After iterator modification : 20 40 60 80 100
After resize(3) : 10 20 30
After resize(6, 99) : 10 20 30 99 99 99

After clear()
empty() : 1

Before swap()
fl24 : 1 2 3
fl25 : 100 200 300
After swap()
fl24 : 100 200 300
fl25 : 1 2 3

After std::swap()
fl24 : 1 2 3
fl25 : 100 200 300

Comparison
fl26 == fl27 : 1
fl26 != fl28 : 1
fl26 <  fl28 : 1

After clearing forward_list
empty() : 1

*/





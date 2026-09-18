#include <iostream>
#include <set>
#include <string>
#include <cstddef>

using namespace std;

//---------------------------------------------------
// Helper function
//---------------------------------------------------
void printMultiSet(const multiset<int>& ms,
    const string& name)
{
    cout << name << " : ";

    for (int value : ms)
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

    multiset<int> ms1;

    multiset<int> ms2 =
    {
        50, 20, 40, 10, 30, 20, 30
    };

    multiset<int> ms3(ms2);

    multiset<int> ms4(ms2.begin(), ms2.end());


    printMultiSet(ms1, "ms1");
    printMultiSet(ms2, "ms2");
    printMultiSet(ms3, "ms3");
    printMultiSet(ms4, "ms4");


    //-----------------------------------------------
    // 2. Assignment
    //-----------------------------------------------

    multiset<int> ms5;

    ms5 = ms2;

    printMultiSet(ms5, "ms5");


    //-----------------------------------------------
    // 3. Automatic sorting
    //-----------------------------------------------

    cout << "\nAutomatic Sorting\n";

    printMultiSet(ms2, "ms2");


    //-----------------------------------------------
    // 4. Duplicate elements
    //-----------------------------------------------

    multiset<int> ms6;

    ms6.insert(10);
    ms6.insert(20);
    ms6.insert(10);
    ms6.insert(20);
    ms6.insert(10);

    printMultiSet(ms6, "ms6");


    //-----------------------------------------------
    // 5. insert()
    //-----------------------------------------------

    ms6.insert(30);

    printMultiSet(ms6, "After insert(30)");


    //-----------------------------------------------
    // 6. insert() with hint
    //-----------------------------------------------

    auto hint = ms6.end();

    ms6.insert(hint, 40);

    printMultiSet(ms6, "After insert(hint, 40)");


    //-----------------------------------------------
    // 7. insert() range
    //-----------------------------------------------

    multiset<int> source =
    {
        50, 60, 70
    };

    ms6.insert(source.begin(), source.end());

    printMultiSet(ms6, "After range insert");


    //-----------------------------------------------
    // 8. emplace()
    //-----------------------------------------------

    ms6.emplace(80);

    printMultiSet(ms6, "After emplace(80)");


    //-----------------------------------------------
    // 9. emplace_hint()
    //-----------------------------------------------

    ms6.emplace_hint(ms6.end(), 90);

    printMultiSet(ms6, "After emplace_hint(90)");


    //-----------------------------------------------
    // 10. Capacity
    //-----------------------------------------------

    cout << "\nCapacity\n";

    cout << "empty()    : " << ms6.empty() << "\n";
    cout << "size()     : " << ms6.size() << "\n";
    cout << "max_size() : " << ms6.max_size() << "\n";


    //-----------------------------------------------
    // 11. find()
    //-----------------------------------------------

    cout << "\nSearching\n";

    auto it = ms6.find(20);

    if (it != ms6.end())
    {
        cout << "find(20) : found\n";
        cout << "value    : " << *it << "\n";
    }
    else
    {
        cout << "find(20) : not found\n";
    }


    //-----------------------------------------------
    // 12. count()
    //-----------------------------------------------

    cout << "count(10)  : " << ms6.count(10) << "\n";
    cout << "count(20)  : " << ms6.count(20) << "\n";
    cout << "count(999) : " << ms6.count(999) << "\n";


    //-----------------------------------------------
    // 13. contains()
    //-----------------------------------------------

    cout << "contains(20)  : "
        << ms6.contains(20) << "\n";

    cout << "contains(999) : "
        << ms6.contains(999) << "\n";


    //-----------------------------------------------
    // 14. lower_bound()
    //-----------------------------------------------

    auto lower = ms6.lower_bound(25);

    if (lower != ms6.end())
    {
        cout << "lower_bound(25) : "
            << *lower << "\n";
    }


    //-----------------------------------------------
    // 15. upper_bound()
    //-----------------------------------------------

    auto upper = ms6.upper_bound(25);

    if (upper != ms6.end())
    {
        cout << "upper_bound(25) : "
            << *upper << "\n";
    }


    //-----------------------------------------------
    // 16. equal_range()
    //-----------------------------------------------

    auto range = ms6.equal_range(20);

    cout << "equal_range(20) : ";

    for (auto rangeIt = range.first;
        rangeIt != range.second;
        ++rangeIt)
    {
        cout << *rangeIt << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 17. equal_range() using count
    //-----------------------------------------------

    cout << "Number of 20s : "
        << distance(range.first, range.second)
        << "\n";


    //-----------------------------------------------
    // 18. erase() by key
    //-----------------------------------------------
    // Unlike set, erase(key) removes ALL matching
    // elements.

    multiset<int> ms7 =
    {
        10, 20, 20, 20, 30
    };

    cout << "\nBefore erase(key)\n";

    printMultiSet(ms7, "ms7");

    size_t removed = ms7.erase(20);

    cout << "Elements removed : "
        << removed << "\n";

    printMultiSet(ms7, "After erase(20)");


    //-----------------------------------------------
    // 19. erase() by iterator
    //-----------------------------------------------
    // Iterator version removes only one element.

    multiset<int> ms8 =
    {
        10, 20, 20, 20, 30
    };

    auto eraseIt = ms8.find(20);

    if (eraseIt != ms8.end())
    {
        ms8.erase(eraseIt);
    }

    printMultiSet(ms8, "After erase(iterator)");


    //-----------------------------------------------
    // 20. erase() range
    //-----------------------------------------------

    multiset<int> ms9 =
    {
        10, 20, 20, 20, 30, 40
    };

    auto first = ms9.find(20);
    auto last = ms9.find(40);

    if (first != ms9.end() && last != ms9.end())
    {
        ms9.erase(first, last);
    }

    printMultiSet(ms9, "After erase(range)");


    //-----------------------------------------------
    // 21. Iterators
    //-----------------------------------------------

    multiset<int> ms10 =
    {
        10, 20, 20, 30, 40
    };

    cout << "\nIterators\n";

    cout << "begin()   : " << *ms10.begin() << "\n";
    cout << "cbegin()  : " << *ms10.cbegin() << "\n";
    cout << "rbegin()  : " << *ms10.rbegin() << "\n";
    cout << "crbegin() : " << *ms10.crbegin() << "\n";


    //-----------------------------------------------
    // 22. Forward traversal
    //-----------------------------------------------

    cout << "\nForward Traversal\n";

    for (auto iterator = ms10.begin();
        iterator != ms10.end();
        ++iterator)
    {
        cout << *iterator << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 23. Reverse traversal
    //-----------------------------------------------

    cout << "\nReverse Traversal\n";

    for (auto iterator = ms10.rbegin();
        iterator != ms10.rend();
        ++iterator)
    {
        cout << *iterator << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 24. Const iterator traversal
    //-----------------------------------------------

    cout << "\nConst Iterator Traversal\n";

    for (auto iterator = ms10.cbegin();
        iterator != ms10.cend();
        ++iterator)
    {
        cout << *iterator << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 25. Range-based for loop
    //-----------------------------------------------

    cout << "\nRange-based For\n";

    for (int value : ms10)
    {
        cout << value << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 26. Modify element
    //-----------------------------------------------
    // Elements cannot be modified through an iterator.
    //
    // *iterator = 100;       // ERROR
    //
    // Changing a key could break the ordering.


    //-----------------------------------------------
    // 27. swap()
    //-----------------------------------------------

    multiset<int> ms11 =
    {
        1, 2, 3
    };

    multiset<int> ms12 =
    {
        100, 200, 300
    };

    cout << "\nBefore swap()\n";

    printMultiSet(ms11, "ms11");
    printMultiSet(ms12, "ms12");

    ms11.swap(ms12);

    cout << "After swap()\n";

    printMultiSet(ms11, "ms11");
    printMultiSet(ms12, "ms12");


    //-----------------------------------------------
    // 28. Non-member std::swap()
    //-----------------------------------------------

    swap(ms11, ms12);

    cout << "\nAfter std::swap()\n";

    printMultiSet(ms11, "ms11");
    printMultiSet(ms12, "ms12");


    //-----------------------------------------------
    // 29. merge()
    //-----------------------------------------------

    multiset<int> ms13 =
    {
        10, 20, 30
    };

    multiset<int> ms14 =
    {
        20, 30, 40
    };

    ms13.merge(ms14);

    printMultiSet(ms13, "After merge()");
    printMultiSet(ms14, "ms14");


    //-----------------------------------------------
    // 30. merge() keeps duplicates
    //-----------------------------------------------

    cout << "\nMerge with Duplicates\n";

    cout << "Duplicates are allowed in multiset\n";

    printMultiSet(ms13, "ms13");


    //-----------------------------------------------
    // 31. clear()
    //-----------------------------------------------

    multiset<int> clearMultiSet =
    {
        10, 20, 20, 30
    };

    clearMultiSet.clear();

    cout << "\nAfter clear()\n";

    cout << "empty() : "
        << clearMultiSet.empty() << "\n";

    cout << "size()  : "
        << clearMultiSet.size() << "\n";


    //-----------------------------------------------
    // 32. Custom sorting order
    //-----------------------------------------------

    multiset<int, greater<int>> descendingMultiSet =
    {
        10, 50, 20, 40, 30, 20
    };

    cout << "\nDescending multiset\n";

    for (int value : descendingMultiSet)
    {
        cout << value << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 33. Comparison
    //-----------------------------------------------

    multiset<int> ms15 =
    {
        10, 20, 30
    };

    multiset<int> ms16 =
    {
        10, 20, 30
    };

    multiset<int> ms17 =
    {
        10, 20, 40
    };

    cout << "\nComparison\n";

    cout << "ms15 == ms16 : "
        << (ms15 == ms16) << "\n";

    cout << "ms15 != ms17 : "
        << (ms15 != ms17) << "\n";

    cout << "ms15 <  ms17 : "
        << (ms15 < ms17) << "\n";


    //-----------------------------------------------
    // End
    //-----------------------------------------------

    return 0;
}


/*
//-----------------------------------------------
The main difference from set is :

set       → unique keys
multiset  → duplicate keys allowed

//-----------------------------------------------
multiset functions covered:

Category	       Functions

Construction	 constructors, copy, range, assignment
Capacity	       empty(), size(), max_size()
Insertion	    insert(), emplace(), emplace_hint()
Search	       find(), count(), contains()
Range search	 lower_bound(), upper_bound(), equal_range()
Removal	       erase(), clear()
Iterators	    begin/end, cbegin/cend, rbegin/rend, crbegin/crend
Operations	    merge(), swap()
Comparison	    ==, !=, <
Ordering	       custom comparator

//-----------------------------------------------
Output:
//-----------------------------------------------

ms1 :
ms2 : 10 20 20 30 30 40 50
ms3 : 10 20 20 30 30 40 50
ms4 : 10 20 20 30 30 40 50
ms5 : 10 20 20 30 30 40 50

Automatic Sorting
ms2 : 10 20 20 30 30 40 50
ms6 : 10 10 10 20 20
After insert(30) : 10 10 10 20 20 30
After insert(hint, 40) : 10 10 10 20 20 30 40
After range insert : 10 10 10 20 20 30 40 50 60 70
After emplace(80) : 10 10 10 20 20 30 40 50 60 70 80
After emplace_hint(90) : 10 10 10 20 20 30 40 50 60 70 80 90

Capacity
empty()    : 0
size()     : 12
max_size() : 461168601842738790

Searching
find(20) : found
value    : 20
count(10)  : 3
count(20)  : 2
count(999) : 0
contains(20)  : 1
contains(999) : 0
lower_bound(25) : 30
upper_bound(25) : 30
equal_range(20) : 20 20
Number of 20s : 2

Before erase(key)
ms7 : 10 20 20 20 30
Elements removed : 3
After erase(20) : 10 30
After erase(iterator) : 10 20 20 30
After erase(range) : 10 40

Iterators
begin()   : 10
cbegin()  : 10
rbegin()  : 40
crbegin() : 40

Forward Traversal
10 20 20 30 40

Reverse Traversal
40 30 20 20 10

Const Iterator Traversal
10 20 20 30 40

Range-based For
10 20 20 30 40

Before swap()
ms11 : 1 2 3
ms12 : 100 200 300
After swap()
ms11 : 100 200 300
ms12 : 1 2 3

After std::swap()
ms11 : 1 2 3
ms12 : 100 200 300
After merge() : 10 20 20 30 30 40
ms14 :

Merge with Duplicates
Duplicates are allowed in multiset
ms13 : 10 20 20 30 30 40

After clear()
empty() : 1
size()  : 0

Descending multiset
50 40 30 20 20 10

Comparison
ms15 == ms16 : 1
ms15 != ms17 : 1
ms15 <  ms17 : 1


//-----------------------------------------------
*/




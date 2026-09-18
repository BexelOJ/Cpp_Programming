#include <iostream>
#include <set>
#include <string>

using namespace std;

//---------------------------------------------------
// Helper function
//---------------------------------------------------
void printSet(const set<int>& s, const string& name)
{
    cout << name << " : ";

    for (int value : s)
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

    set<int> s1;

    set<int> s2 = { 50, 20, 40, 10, 30 };

    set<int> s3(s2);

    set<int> s4(s2.begin(), s2.end());


    printSet(s1, "s1");
    printSet(s2, "s2");
    printSet(s3, "s3");
    printSet(s4, "s4");


    //-----------------------------------------------
    // 2. Assignment
    //-----------------------------------------------

    set<int> s5;

    s5 = s2;

    printSet(s5, "s5");


    //-----------------------------------------------
    // 3. Automatic sorting
    //-----------------------------------------------

    cout << "\nAutomatic Sorting\n";

    printSet(s2, "s2");


    //-----------------------------------------------
    // 4. Duplicate elements
    //-----------------------------------------------

    set<int> s6;

    auto result1 = s6.insert(10);
    auto result2 = s6.insert(20);
    auto result3 = s6.insert(10);

    printSet(s6, "s6");

    cout << "First insert successful  : "
        << result1.second << "\n";

    cout << "Second insert successful : "
        << result2.second << "\n";

    cout << "Duplicate insert success : "
        << result3.second << "\n";


    //-----------------------------------------------
    // 5. insert()
    //-----------------------------------------------

    s6.insert(30);

    printSet(s6, "After insert(30)");


    //-----------------------------------------------
    // 6. insert() with hint
    //-----------------------------------------------

    auto hint = s6.end();

    s6.insert(hint, 40);

    printSet(s6, "After insert(hint, 40)");


    //-----------------------------------------------
    // 7. insert() range
    //-----------------------------------------------

    set<int> source =
    {
        50, 60, 70
    };

    s6.insert(source.begin(), source.end());

    printSet(s6, "After range insert");


    //-----------------------------------------------
    // 8. emplace()
    //-----------------------------------------------

    s6.emplace(80);

    printSet(s6, "After emplace(80)");


    //-----------------------------------------------
    // 9. emplace_hint()
    //-----------------------------------------------

    s6.emplace_hint(s6.end(), 90);

    printSet(s6, "After emplace_hint(90)");


    //-----------------------------------------------
    // 10. empty()
    //-----------------------------------------------

    cout << "\nCapacity\n";

    cout << "empty()    : " << s6.empty() << "\n";
    cout << "size()     : " << s6.size() << "\n";
    cout << "max_size() : " << s6.max_size() << "\n";


    //-----------------------------------------------
    // 11. find()
    //-----------------------------------------------

    cout << "\nSearching\n";

    auto it = s6.find(40);

    if (it != s6.end())
    {
        cout << "find(40) : found\n";
        cout << "value    : " << *it << "\n";
    }
    else
    {
        cout << "find(40) : not found\n";
    }


    //-----------------------------------------------
    // 12. find() missing element
    //-----------------------------------------------

    auto missing = s6.find(999);

    if (missing == s6.end())
    {
        cout << "find(999) : not found\n";
    }


    //-----------------------------------------------
    // 13. count()
    //-----------------------------------------------

    cout << "count(40)  : " << s6.count(40) << "\n";
    cout << "count(999) : " << s6.count(999) << "\n";


    //-----------------------------------------------
    // 14. contains()
    //-----------------------------------------------

    cout << "contains(40)  : " << s6.contains(40) << "\n";
    cout << "contains(999) : " << s6.contains(999) << "\n";


    //-----------------------------------------------
    // 15. lower_bound()
    //-----------------------------------------------

    auto lower = s6.lower_bound(45);

    if (lower != s6.end())
    {
        cout << "lower_bound(45) : " << *lower << "\n";
    }


    //-----------------------------------------------
    // 16. upper_bound()
    //-----------------------------------------------

    auto upper = s6.upper_bound(45);

    if (upper != s6.end())
    {
        cout << "upper_bound(45) : " << *upper << "\n";
    }


    //-----------------------------------------------
    // 17. equal_range()
    //-----------------------------------------------

    auto range = s6.equal_range(50);

    cout << "equal_range(50) : ";

    for (auto rangeIt = range.first;
        rangeIt != range.second;
        ++rangeIt)
    {
        cout << *rangeIt << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 18. erase() by key
    //-----------------------------------------------

    s6.erase(30);

    printSet(s6, "After erase(30)");


    //-----------------------------------------------
    // 19. erase() by iterator
    //-----------------------------------------------

    auto eraseIt = s6.find(40);

    if (eraseIt != s6.end())
    {
        s6.erase(eraseIt);
    }

    printSet(s6, "After erase(iterator)");


    //-----------------------------------------------
    // 20. erase() range
    //-----------------------------------------------

    auto first = s6.find(50);
    auto last = s6.find(80);

    if (first != s6.end() && last != s6.end())
    {
        s6.erase(first, last);
    }

    printSet(s6, "After erase(range)");


    //-----------------------------------------------
    // 21. Iterators
    //-----------------------------------------------

    set<int> s7 =
    {
        10, 20, 30, 40, 50
    };

    cout << "\nIterators\n";

    cout << "begin()   : " << *s7.begin() << "\n";
    cout << "cbegin()  : " << *s7.cbegin() << "\n";
    cout << "rbegin()  : " << *s7.rbegin() << "\n";
    cout << "crbegin() : " << *s7.crbegin() << "\n";


    //-----------------------------------------------
    // 22. Forward traversal
    //-----------------------------------------------

    cout << "\nForward Traversal\n";

    for (auto iterator = s7.begin();
        iterator != s7.end();
        ++iterator)
    {
        cout << *iterator << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 23. Reverse traversal
    //-----------------------------------------------

    cout << "\nReverse Traversal\n";

    for (auto iterator = s7.rbegin();
        iterator != s7.rend();
        ++iterator)
    {
        cout << *iterator << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 24. Const iterator traversal
    //-----------------------------------------------

    cout << "\nConst Iterator Traversal\n";

    for (auto iterator = s7.cbegin();
        iterator != s7.cend();
        ++iterator)
    {
        cout << *iterator << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 25. Range-based for loop
    //-----------------------------------------------

    cout << "\nRange-based For\n";

    for (int value : s7)
    {
        cout << value << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 26. Modify element
    //-----------------------------------------------
    // Elements of a set cannot be modified directly.
    //
    // *iterator = 100;       // ERROR
    //
    // Changing a key could break the ordering.


    //-----------------------------------------------
    // 27. swap()
    //-----------------------------------------------

    set<int> s8 =
    {
        1, 2, 3
    };

    set<int> s9 =
    {
        100, 200, 300
    };

    cout << "\nBefore swap()\n";

    printSet(s8, "s8");
    printSet(s9, "s9");

    s8.swap(s9);

    cout << "After swap()\n";

    printSet(s8, "s8");
    printSet(s9, "s9");


    //-----------------------------------------------
    // 28. Non-member std::swap()
    //-----------------------------------------------

    swap(s8, s9);

    cout << "\nAfter std::swap()\n";

    printSet(s8, "s8");
    printSet(s9, "s9");


    //-----------------------------------------------
    // 29. merge()
    //-----------------------------------------------

    set<int> s10 =
    {
        10, 20, 30
    };

    set<int> s11 =
    {
        20, 40, 50
    };

    s10.merge(s11);

    printSet(s10, "After merge()");
    printSet(s11, "s11");


    //-----------------------------------------------
    // 30. merge() and duplicate keys
    //-----------------------------------------------

    cout << "\nMerge Duplicate\n";

    cout << "The duplicate key 20 remains in source\n";

    printSet(s11, "s11");


    //-----------------------------------------------
    // 31. clear()
    //-----------------------------------------------

    set<int> clearSet =
    {
        10, 20, 30, 40
    };

    clearSet.clear();

    cout << "\nAfter clear()\n";

    cout << "empty() : " << clearSet.empty() << "\n";
    cout << "size()  : " << clearSet.size() << "\n";


    //-----------------------------------------------
    // 32. Comparison
    //-----------------------------------------------

    set<int> s12 =
    {
        10, 20, 30
    };

    set<int> s13 =
    {
        10, 20, 30
    };

    set<int> s14 =
    {
        10, 20, 40
    };

    cout << "\nComparison\n";

    cout << "s12 == s13 : " << (s12 == s13) << "\n";
    cout << "s12 != s14 : " << (s12 != s14) << "\n";
    cout << "s12 <  s14 : " << (s12 < s14) << "\n";


    //-----------------------------------------------
    // 33. Custom sorting order
    //-----------------------------------------------

    set<int, greater<int>> descendingSet =
    {
        10, 50, 20, 40, 30
    };

    cout << "\nDescending Set\n";

    for (int value : descendingSet)
    {
        cout << value << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // End
    //-----------------------------------------------

    return 0;
}


//---------------------------------------------------
/*

compile with C++20

g++ - std = c++20 cpp_20260918_STL_set.cpp

//---------------------------------------------------
ordered associative container
 
A set stores unique keys in sorted order. 
There is no operator[] or at().

//---------------------------------------------------
set functions covered:

Category    	Functions

Construction	 constructors, copy, range, assignment
Capacity	       empty(), size(), max_size()
Insertion	    insert(), emplace(), emplace_hint()
Search	       find(), count(), contains()

Range search	 lower_bound(), upper_bound(), equal_range()

Removal	       erase(), clear()

Iterators	    begin/end, cbegin/cend, rbegin/rend, crbegin/crend

Operations	        merge(), swap()
Comparison	        ==, !=, <
Custom ordering	  greater<int>

//---------------------------------------------------
set has three properties:

                std::set
                   |
        +----------+----------+
        |          |          |
      UNIQUE     SORTED     KEY ONLY
        |          |          |
    no duplicates ascending  no value


//---------------------------------------------------
 Output:
//---------------------------------------------------

s1 :
s2 : 10 20 30 40 50
s3 : 10 20 30 40 50
s4 : 10 20 30 40 50
s5 : 10 20 30 40 50

Automatic Sorting
s2 : 10 20 30 40 50
s6 : 10 20
First insert successful  : 1
Second insert successful : 1
Duplicate insert success : 0
After insert(30) : 10 20 30
After insert(hint, 40) : 10 20 30 40
After range insert : 10 20 30 40 50 60 70
After emplace(80) : 10 20 30 40 50 60 70 80
After emplace_hint(90) : 10 20 30 40 50 60 70 80 90

Capacity
empty()    : 0
size()     : 9
max_size() : 461168601842738790

Searching
find(40) : found
value    : 40
find(999) : not found
count(40)  : 1
count(999) : 0
contains(40)  : 1
contains(999) : 0
lower_bound(45) : 50
upper_bound(45) : 50
equal_range(50) : 50
After erase(30) : 10 20 40 50 60 70 80 90
After erase(iterator) : 10 20 50 60 70 80 90
After erase(range) : 10 20 80 90

Iterators
begin()   : 10
cbegin()  : 10
rbegin()  : 50
crbegin() : 50

Forward Traversal
10 20 30 40 50

Reverse Traversal
50 40 30 20 10

Const Iterator Traversal
10 20 30 40 50

Range-based For
10 20 30 40 50

Before swap()
s8 : 1 2 3
s9 : 100 200 300
After swap()
s8 : 100 200 300
s9 : 1 2 3

After std::swap()
s8 : 1 2 3
s9 : 100 200 300
After merge() : 10 20 30 40 50
s11 : 20

Merge Duplicate
The duplicate key 20 remains in source
s11 : 20

After clear()
empty() : 1
size()  : 0

Comparison
s12 == s13 : 1
s12 != s14 : 1
s12 <  s14 : 1

Descending Set
50 40 30 20 10

*/






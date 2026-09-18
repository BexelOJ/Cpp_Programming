#include <iostream>
#include <list>
#include <string>

using namespace std;

//---------------------------------------------------
// Helper function
//---------------------------------------------------
void printList(const list<int>& l, const string& name)
{
    cout << name << " : ";

    for (int value : l)
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

    list<int> l1;

    list<int> l2(5, 10);

    list<int> l3 = { 10, 20, 30, 40, 50 };

    list<int> l4(l3);

    list<int> l5(l3.begin(), l3.end());


    printList(l1, "l1");
    printList(l2, "l2");
    printList(l3, "l3");
    printList(l4, "l4");
    printList(l5, "l5");


    //-----------------------------------------------
    // 2. Assignment
    //-----------------------------------------------

    list<int> l6;

    l6 = l3;

    printList(l6, "l6");


    //-----------------------------------------------
    // 3. Element Access
    //-----------------------------------------------

    cout << "\nElement Access\n";

    cout << "front() : " << l3.front() << "\n";
    cout << "back()  : " << l3.back() << "\n";


    //-----------------------------------------------
    // 4. operator[] and at()
    //-----------------------------------------------
    // list does NOT provide:
    //
    // operator[]
    // at()
    //
    // Random access is not supported.


    //-----------------------------------------------
    // 5. Capacity
    //-----------------------------------------------

    cout << "\nCapacity\n";

    cout << "empty()    : " << l3.empty() << "\n";
    cout << "size()     : " << l3.size() << "\n";
    cout << "max_size() : " << l3.max_size() << "\n";


    //-----------------------------------------------
    // 6. push_back()
    //-----------------------------------------------

    l3.push_back(60);

    printList(l3, "After push_back(60)");


    //-----------------------------------------------
    // 7. emplace_back()
    //-----------------------------------------------

    l3.emplace_back(70);

    printList(l3, "After emplace_back(70)");


    //-----------------------------------------------
    // 8. push_front()
    //-----------------------------------------------

    l3.push_front(0);

    printList(l3, "After push_front(0)");


    //-----------------------------------------------
    // 9. emplace_front()
    //-----------------------------------------------

    l3.emplace_front(-10);

    printList(l3, "After emplace_front(-10)");


    //-----------------------------------------------
    // 10. pop_back()
    //-----------------------------------------------

    l3.pop_back();

    printList(l3, "After pop_back()");


    //-----------------------------------------------
    // 11. pop_front()
    //-----------------------------------------------

    l3.pop_front();

    printList(l3, "After pop_front()");


    //-----------------------------------------------
    // 12. insert()
    //-----------------------------------------------

    l3.insert(next(l3.begin(), 2), 25);

    printList(l3, "After insert(25)");


    //-----------------------------------------------
    // 13. insert() multiple values
    //-----------------------------------------------

    l3.insert(next(l3.begin(), 2), 3, 15);

    printList(l3, "After insert(3, 15)");


    //-----------------------------------------------
    // 14. insert() range
    //-----------------------------------------------

    list<int> source = { 100, 200, 300 };

    l3.insert(l3.end(), source.begin(), source.end());

    printList(l3, "After range insert");


    //-----------------------------------------------
    // 15. emplace()
    //-----------------------------------------------

    l3.emplace(next(l3.begin(), 1), 5);

    printList(l3, "After emplace(5)");


    //-----------------------------------------------
    // 16. erase()
    //-----------------------------------------------

    l3.erase(next(l3.begin(), 1));

    printList(l3, "After erase()");


    //-----------------------------------------------
    // 17. erase() range
    //-----------------------------------------------

    l3.erase(next(l3.begin(), 1), next(l3.begin(), 3));

    printList(l3, "After range erase");


    //-----------------------------------------------
    // 18. resize()
    //-----------------------------------------------

    l3.resize(10);

    printList(l3, "After resize(10)");

    cout << "size() : " << l3.size() << "\n";


    //-----------------------------------------------
    // 19. resize() with value
    //-----------------------------------------------

    l3.resize(15, 99);

    printList(l3, "After resize(15, 99)");


    //-----------------------------------------------
    // 20. resize() smaller
    //-----------------------------------------------

    l3.resize(5);

    printList(l3, "After resize(5)");


    //-----------------------------------------------
    // 21. clear()
    //-----------------------------------------------

    list<int> clearList = { 10, 20, 30, 40 };

    clearList.clear();

    cout << "\nAfter clear()\n";

    cout << "empty() : " << clearList.empty() << "\n";
    cout << "size()  : " << clearList.size() << "\n";


    //-----------------------------------------------
    // 22. Iterators
    //-----------------------------------------------

    list<int> l7 = { 10, 20, 30, 40, 50 };

    cout << "\nIterators\n";

    cout << "begin()   : " << *l7.begin() << "\n";
    cout << "cbegin()  : " << *l7.cbegin() << "\n";

    cout << "rbegin()  : " << *l7.rbegin() << "\n";
    cout << "crbegin() : " << *l7.crbegin() << "\n";


    //-----------------------------------------------
    // 23. Forward traversal
    //-----------------------------------------------

    cout << "\nForward Traversal\n";

    for (auto it = l7.begin(); it != l7.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 24. Reverse traversal
    //-----------------------------------------------

    cout << "\nReverse Traversal\n";

    for (auto it = l7.rbegin(); it != l7.rend(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 25. Const iterator
    //-----------------------------------------------

    cout << "\nConst Iterator Traversal\n";

    for (auto it = l7.cbegin(); it != l7.cend(); ++it)
    {
        cout << *it << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 26. Range-based for loop
    //-----------------------------------------------

    cout << "\nRange-based For\n";

    for (int value : l7)
    {
        cout << value << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 27. Modify elements using iterator
    //-----------------------------------------------

    for (auto it = l7.begin(); it != l7.end(); ++it)
    {
        *it *= 2;
    }

    printList(l7, "After iterator modification");


    //-----------------------------------------------
    // 28. remove()
    //-----------------------------------------------

    list<int> l8 = { 10, 20, 10, 30, 10, 40 };

    l8.remove(10);

    printList(l8, "After remove(10)");


    //-----------------------------------------------
    // 29. remove_if()
    //-----------------------------------------------

    list<int> l9 = { 1, 2, 3, 4, 5, 6 };

    l9.remove_if([](int value)
        {
            return value % 2 == 0;
        });

    printList(l9, "After remove_if(even)");


    //-----------------------------------------------
    // 30. unique()
    //-----------------------------------------------

    list<int> l10 = { 10, 10, 20, 20, 20, 30, 30, 40 };

    l10.unique();

    printList(l10, "After unique()");


    //-----------------------------------------------
    // 31. sort()
    //-----------------------------------------------

    list<int> l11 = { 50, 10, 40, 20, 30 };

    l11.sort();

    printList(l11, "After sort()");


    //-----------------------------------------------
    // 32. sort() descending
    //-----------------------------------------------

    l11.sort(greater<int>());

    printList(l11, "After descending sort");


    //-----------------------------------------------
    // 33. reverse()
    //-----------------------------------------------

    l11.reverse();

    printList(l11, "After reverse()");


    //-----------------------------------------------
    // 34. merge()
    //-----------------------------------------------

    list<int> l12 = { 10, 30, 50 };
    list<int> l13 = { 20, 40, 60 };

    l12.merge(l13);

    printList(l12, "After merge()");

    printList(l13, "l13");


    //-----------------------------------------------
    // 35. merge() descending
    //-----------------------------------------------

    list<int> l14 = { 60, 40, 20 };
    list<int> l15 = { 50, 30, 10 };

    l14.merge(l15, greater<int>());

    printList(l14, "After descending merge");


    //-----------------------------------------------
    // 36. splice() entire list
    //-----------------------------------------------

    list<int> l16 = { 10, 20, 30 };
    list<int> l17 = { 100, 200, 300 };

    l16.splice(l16.end(), l17);

    printList(l16, "After splice()");
    printList(l17, "l17");


    //-----------------------------------------------
    // 37. splice() single element
    //-----------------------------------------------

    list<int> l18 = { 1, 2, 3 };
    list<int> l19 = { 10, 20, 30 };

    auto it = next(l19.begin(), 1);

    l18.splice(l18.end(), l19, it);

    printList(l18, "After single splice()");
    printList(l19, "l19");


    //-----------------------------------------------
    // 38. splice() range
    //-----------------------------------------------

    list<int> l20 = { 1, 2, 3 };
    list<int> l21 = { 10, 20, 30, 40, 50 };

    auto first = next(l21.begin(), 1);
    auto last = next(l21.begin(), 4);

    l20.splice(l20.end(), l21, first, last);

    printList(l20, "After range splice()");
    printList(l21, "l21");


    //-----------------------------------------------
    // 39. swap()
    //-----------------------------------------------

    list<int> l22 = { 1, 2, 3 };
    list<int> l23 = { 100, 200, 300 };

    cout << "\nBefore swap()\n";

    printList(l22, "l22");
    printList(l23, "l23");

    l22.swap(l23);

    cout << "After swap()\n";

    printList(l22, "l22");
    printList(l23, "l23");


    //-----------------------------------------------
    // 40. Non-member std::swap()
    //-----------------------------------------------

    swap(l22, l23);

    cout << "\nAfter std::swap()\n";

    printList(l22, "l22");
    printList(l23, "l23");


    //-----------------------------------------------
    // 41. Comparison
    //-----------------------------------------------

    list<int> l24 = { 10, 20, 30 };
    list<int> l25 = { 10, 20, 30 };
    list<int> l26 = { 10, 20, 40 };

    cout << "\nComparison\n";

    cout << "l24 == l25 : " << (l24 == l25) << "\n";
    cout << "l24 != l26 : " << (l24 != l26) << "\n";
    cout << "l24 <  l26 : " << (l24 < l26) << "\n";


    //-----------------------------------------------
    // 42. front() and back() modification
    //-----------------------------------------------

    l24.front() = 100;
    l24.back() = 300;

    printList(l24, "After front/back modification");


    //-----------------------------------------------
    // 43. Clearing a list
    //-----------------------------------------------

    list<int> clearAll = { 10, 20, 30 };

    clearAll.clear();

    cout << "\nAfter clearing list\n";

    cout << "empty() : " << clearAll.empty() << "\n";
    cout << "size()  : " << clearAll.size() << "\n";


    //-----------------------------------------------
    // End
    //-----------------------------------------------

    return 0;
}




/*

std::list. 
This one is important 
because it introduces bidirectional iterators, 
constant-time insertion/erasure at a known position, 
splice(), remove(), unique(), merge(), sort(), 
and reverse().
 
//---------------------------------------------------
list functions covered:

Category	       Functions

Construction	 constructors, copy, range, assignment
Access	       front(), back()
Capacity	       empty(), size(), max_size()
Insertion	    insert(), emplace(), push_front(), 
push_back(), emplace_front(), emplace_back()

Removal	       pop_front(), pop_back(), erase(), clear()
Size	          resize()

Iterators	    begin/end, cbegin/cend, rbegin/rend, crbegin/crend

Special list operations	
remove(), remove_if(), unique()

Ordering	           sort(), reverse()
List operations	  merge(), splice()
Swap	              swap(), std::swap()
Comparison	        ==, !=, <

//---------------------------------------------------
Important: 
list has no operator[], at(), data(), reserve(), 
or capacity().

//---------------------------------------------------
The big reason to learn list separately is its 
list-specific operations: 

splice() and merge(), 

plus its ability to efficiently insert/erase 
elements once you have an iterator to the position.

//---------------------------------------------------
 Output:
//---------------------------------------------------

l1 :
l2 : 10 10 10 10 10
l3 : 10 20 30 40 50
l4 : 10 20 30 40 50
l5 : 10 20 30 40 50
l6 : 10 20 30 40 50

Element Access
front() : 10
back()  : 50

Capacity
empty()    : 0
size()     : 5
max_size() : 384307168202282325
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

After clear()
empty() : 1
size()  : 0

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
After iterator modification : 20 40 60 80 100
After remove(10) : 20 30 40
After remove_if(even) : 1 3 5
After unique() : 10 20 30 40
After sort() : 10 20 30 40 50
After descending sort : 50 40 30 20 10
After reverse() : 10 20 30 40 50
After merge() : 10 20 30 40 50 60
l13 :
After descending merge : 60 50 40 30 20 10
After splice() : 10 20 30 100 200 300
l17 :
After single splice() : 1 2 3 20
l19 : 10 30
After range splice() : 1 2 3 20 30 40
l21 : 10 50

Before swap()
l22 : 1 2 3
l23 : 100 200 300
After swap()
l22 : 100 200 300
l23 : 1 2 3

After std::swap()
l22 : 1 2 3
l23 : 100 200 300

Comparison
l24 == l25 : 1
l24 != l26 : 1
l24 <  l26 : 1
After front/back modification : 100 20 300

After clearing list
empty() : 1
size()  : 0

*/





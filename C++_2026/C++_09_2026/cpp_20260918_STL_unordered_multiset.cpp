#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>

using namespace std;

//---------------------------------------------------
// main
//---------------------------------------------------
int main()
{
    //-----------------------------------------------
    // 1. Constructors
    //-----------------------------------------------

    unordered_multiset<int> ums1;

    unordered_multiset<int> ums2 =
    {
        10, 20, 10, 30, 20, 10
    };

    unordered_multiset<int> ums3(ums2);

    unordered_multiset<int> ums4(move(ums3));

    vector<int> values =
    {
        100, 200, 100, 300
    };

    unordered_multiset<int> ums5(values.begin(), values.end());

    //-----------------------------------------------
    // 2. Assignment
    //-----------------------------------------------

    ums1 = ums2;

    unordered_multiset<int> ums6;
    ums6 = move(ums1);

    //-----------------------------------------------
    // 3. Initial contents
    //-----------------------------------------------

    cout << "Initial contents:\n";

    for (const auto& value : ums2)
    {
        cout << value << " ";
    }

    cout << "\n";

    //-----------------------------------------------
    // 4. empty()
    //-----------------------------------------------

    cout << "\nempty() : "
        << ums2.empty() << "\n";

    //-----------------------------------------------
    // 5. size()
    //-----------------------------------------------

    cout << "size() : "
        << ums2.size() << "\n";

    //-----------------------------------------------
    // 6. max_size()
    //-----------------------------------------------

    cout << "max_size() : "
        << ums2.max_size() << "\n";

    //-----------------------------------------------
    // 7. insert()
    //-----------------------------------------------

    ums2.insert(40);
    ums2.insert(40);

    cout << "\nAfter insert():\n";

    for (const auto& value : ums2)
    {
        cout << value << " ";
    }

    cout << "\n";

    //-----------------------------------------------
    // 8. Duplicate values
    //-----------------------------------------------

    ums2.insert(50);
    ums2.insert(50);
    ums2.insert(50);

    cout << "\ncount(50) : "
        << ums2.count(50) << "\n";

    //-----------------------------------------------
    // 9. emplace()
    //-----------------------------------------------

    ums2.emplace(60);
    ums2.emplace(60);

    //-----------------------------------------------
    // 10. emplace_hint()
    //-----------------------------------------------

    auto hint = ums2.begin();

    ums2.emplace_hint(hint, 70);

    //-----------------------------------------------
    // 11. Insert range
    //-----------------------------------------------

    vector<int> moreValues =
    {
        80, 80, 90, 100
    };

    ums2.insert(moreValues.begin(), moreValues.end());

    //-----------------------------------------------
    // 12. find()
    //-----------------------------------------------

    auto it = ums2.find(20);

    if (it != ums2.end())
    {
        cout << "\nfind(20) : "
            << *it << "\n";
    }

    //-----------------------------------------------
    // 13. count()
    //-----------------------------------------------

    cout << "count(10) : "
        << ums2.count(10) << "\n";

    cout << "count(20) : "
        << ums2.count(20) << "\n";

    cout << "count(999) : "
        << ums2.count(999) << "\n";

    //-----------------------------------------------
    // 14. contains() - C++20
    //-----------------------------------------------

    cout << "\ncontains(10) : "
        << ums2.contains(10) << "\n";

    cout << "contains(999) : "
        << ums2.contains(999) << "\n";

    //-----------------------------------------------
    // 15. equal_range()
    //-----------------------------------------------

    cout << "\nequal_range(10):\n";

    auto range = ums2.equal_range(10);

    for (auto i = range.first;
        i != range.second;
        ++i)
    {
        cout << *i << " ";
    }

    cout << "\n";

    //-----------------------------------------------
    // 16. Iterators - begin(), end()
    //-----------------------------------------------

    cout << "\nbegin() / end():\n";

    for (auto i = ums2.begin();
        i != ums2.end();
        ++i)
    {
        cout << *i << " ";
    }

    cout << "\n";

    //-----------------------------------------------
    // 17. cbegin(), cend()
    //-----------------------------------------------

    cout << "\ncbegin() / cend():\n";

    for (auto i = ums2.cbegin();
        i != ums2.cend();
        ++i)
    {
        cout << *i << " ";
    }

    cout << "\n";

    //-----------------------------------------------
    // 18. Bucket count
    //-----------------------------------------------

    cout << "\nbucket_count() : "
        << ums2.bucket_count() << "\n";

    //-----------------------------------------------
    // 19. bucket_size()
    //-----------------------------------------------

    cout << "bucket_size(0) : "
        << ums2.bucket_size(0) << "\n";

    //-----------------------------------------------
    // 20. bucket()
    //-----------------------------------------------

    cout << "bucket(10) : "
        << ums2.bucket(10) << "\n";

    //-----------------------------------------------
    // 21. Display buckets
    //-----------------------------------------------

    cout << "\nBucket contents:\n";

    for (size_t i = 0;
        i < ums2.bucket_count();
        ++i)
    {
        cout << "Bucket " << i << " : ";

        for (auto iit = ums2.begin(i);
            iit != ums2.end(i);
            ++iit)
        {
            cout << *iit << " ";
        }

        cout << "\n";
    }

    //-----------------------------------------------
    // 22. load_factor()
    //-----------------------------------------------

    cout << "\nload_factor() : "
        << ums2.load_factor() << "\n";

    //-----------------------------------------------
    // 23. max_load_factor()
    //-----------------------------------------------

    cout << "max_load_factor() : "
        << ums2.max_load_factor() << "\n";

    //-----------------------------------------------
    // 24. Change max_load_factor()
    //-----------------------------------------------

    ums2.max_load_factor(0.7);

    cout << "New max_load_factor() : "
        << ums2.max_load_factor() << "\n";

    //-----------------------------------------------
    // 25. rehash()
    //-----------------------------------------------

    ums2.rehash(20);

    cout << "\nAfter rehash(20):\n";

    cout << "bucket_count() : "
        << ums2.bucket_count() << "\n";

    //-----------------------------------------------
    // 26. reserve()
    //-----------------------------------------------

    ums2.reserve(100);

    cout << "After reserve(100):\n";

    cout << "bucket_count() : "
        << ums2.bucket_count() << "\n";

    //-----------------------------------------------
    // 27. hash_function()
    //-----------------------------------------------

    auto hash = ums2.hash_function();

    cout << "\nhash_function()(10) : "
        << hash(10) << "\n";

    //-----------------------------------------------
    // 28. key_eq()
    //-----------------------------------------------

    auto keyEqual = ums2.key_eq();

    cout << "key_eq()(10, 10) : "
        << keyEqual(10, 10) << "\n";

    cout << "key_eq()(10, 20) : "
        << keyEqual(10, 20) << "\n";

    //-----------------------------------------------
    // 29. erase(iterator)
    //-----------------------------------------------

    auto eraseIt = ums2.find(30);

    if (eraseIt != ums2.end())
    {
        ums2.erase(eraseIt);
    }

    //-----------------------------------------------
    // 30. erase(key)
    //-----------------------------------------------

    size_t removed = ums2.erase(50);

    cout << "\nerase(50) removed : "
        << removed << " elements\n";

    //-----------------------------------------------
    // 31. erase(iterator range)
    //-----------------------------------------------

    auto first = ums2.begin();

    auto last = first;

    if (last != ums2.end())
    {
        ++last;
    }

    ums2.erase(first, last);

    //-----------------------------------------------
    // 32. swap()
    //-----------------------------------------------

    unordered_multiset<int> ums7 =
    {
        100, 200, 100
    };

    unordered_multiset<int> ums8 =
    {
        300, 400, 300
    };

    ums7.swap(ums8);

    cout << "\nAfter swap():\n";

    cout << "ums7:\n";

    for (const auto& value : ums7)
    {
        cout << value << " ";
    }

    cout << "\nums8:\n";

    for (const auto& value : ums8)
    {
        cout << value << " ";
    }

    cout << "\n";

    //-----------------------------------------------
    // 33. clear()
    //-----------------------------------------------

    ums8.clear();

    cout << "\nums8 size after clear() : "
        << ums8.size() << "\n";

    //-----------------------------------------------
    // 34. merge()
    //-----------------------------------------------

    unordered_multiset<int> source =
    {
        1, 2, 1, 3
    };

    unordered_multiset<int> destination =
    {
        4, 5
    };

    destination.merge(source);

    cout << "\nAfter merge():\n";

    for (const auto& value : destination)
    {
        cout << value << " ";
    }

    cout << "\n";

    cout << "source size : "
        << source.size() << "\n";

    //-----------------------------------------------
    // 35. extract(iterator)
    //-----------------------------------------------

    auto extractIt = destination.find(1);

    if (extractIt != destination.end())
    {
        auto node = destination.extract(extractIt);

        cout << "\nExtracted node value : "
            << node.value() << "\n";
    }

    //-----------------------------------------------
    // 36. extract(key)
    //-----------------------------------------------

    auto node = destination.extract(2);

    if (!node.empty())
    {
        cout << "extract(key) value : "
            << node.value() << "\n";
    }

    //-----------------------------------------------
    // 37. Modify extracted node
    //-----------------------------------------------

    auto node2 = destination.extract(destination.begin());

    if (!node2.empty())
    {
        node2.value() = 999;

        destination.insert(move(node2));
    }

    //-----------------------------------------------
    // 38. range-based for loop
    //-----------------------------------------------

    cout << "\nRange-based for loop:\n";

    for (const auto& value : destination)
    {
        cout << value << " ";
    }

    cout << "\n";

    //-----------------------------------------------
    // 39. Modify value
    //-----------------------------------------------

    auto modifyIt = destination.find(999);

    if (modifyIt != destination.end())
    {
        /*
            Direct modification is not allowed:

            *modifyIt = 1000;     // ERROR

            Set elements are treated as const because
            changing a value could break the hash table.

            Use extract() to modify the value safely.
        */
    }

    //-----------------------------------------------
    // 40. No operator[] or at()
    //-----------------------------------------------

    /*
        unordered_multiset does NOT provide:

        ums2[10]
        ums2.at(10)

        There is no mapped value.
        The container stores only values.
    */

    //-----------------------------------------------
    // 41. No lower_bound() / upper_bound()
    //-----------------------------------------------

    /*
        unordered_multiset is unordered.

        Therefore:

        lower_bound()    // NOT available
        upper_bound()    // NOT available

        equal_range() IS available because it is based
        on equivalent keys/values.
    */

    //-----------------------------------------------
    // 42. Final size
    //-----------------------------------------------

    cout << "\nFinal size : "
        << destination.size() << "\n";

    //-----------------------------------------------
    // End
    //-----------------------------------------------

    return 0;
}


/*
//---------------------------------------------------
Output:
//---------------------------------------------------

Initial contents:
3 -> Orange
2 -> Grapes
2 -> Banana
1 -> Mango
1 -> Apple

empty() : 0
size()  : 5
max_size() : 384307168202282325

After insert():
4 -> Watermelon
4 -> Pineapple
1 -> Mango
1 -> Apple
2 -> Grapes
2 -> Banana
3 -> Orange

Multiple values for key 1:
1 -> Guava
1 -> Papaya
1 -> Mango
1 -> Apple

find(2) : Grapes
count(1) : 4
count(7) : 2
contains(3) : 1
contains(9) : 0

equal_range(1):
1 -> Guava
1 -> Papaya
1 -> Mango
1 -> Apple

begin() / end():
8 -> Apple
7 -> Lime
7 -> Lemon
6 -> Cherry
3 -> Orange
2 -> Grapes
2 -> Banana
1 -> Guava
1 -> Papaya
1 -> Mango
1 -> Apple
4 -> Watermelon
4 -> Pineapple
5 -> Peach
5 -> Kiwi

cbegin() / cend():
8 -> Apple
7 -> Lime
7 -> Lemon
6 -> Cherry
3 -> Orange
2 -> Grapes
2 -> Banana
1 -> Guava
1 -> Papaya
1 -> Mango
1 -> Apple
4 -> Watermelon
4 -> Pineapple
5 -> Peach
5 -> Kiwi

bucket_count() : 23
bucket_size(0) : 0
bucket(1) : 1

Bucket contents:
Bucket 0 :
Bucket 1 : [1 -> Guava] [1 -> Papaya] [1 -> Mango] [1 -> Apple]
Bucket 2 : [2 -> Grapes] [2 -> Banana]
Bucket 3 : [3 -> Orange]
Bucket 4 : [4 -> Watermelon] [4 -> Pineapple]
Bucket 5 : [5 -> Peach] [5 -> Kiwi]
Bucket 6 : [6 -> Cherry]
Bucket 7 : [7 -> Lime] [7 -> Lemon]
Bucket 8 : [8 -> Apple]
Bucket 9 :
Bucket 10 :
Bucket 11 :
Bucket 12 :
Bucket 13 :
Bucket 14 :
Bucket 15 :
Bucket 16 :
Bucket 17 :
Bucket 18 :
Bucket 19 :
Bucket 20 :
Bucket 21 :
Bucket 22 :

load_factor() : 0.652174
max_load_factor() : 1
New max_load_factor() : 0.7

After rehash(20):
bucket_count() : 23
After reserve(100):
bucket_count() : 149

hash_function()(10) : 10
key_eq()(10, 10) : 1
key_eq()(10, 20) : 0

erase(7) removed : 2 elements

After swap():
umm7:
400 -> Four
300 -> Three
umm8:
200 -> Two
100 -> One

umm8 size after clear() : 0

After merge():
1 -> C
1 -> A
2 -> B
3 -> D
source size : 0

Extracted node:
1 -> C

extract(key):
2 -> B

Range-based for loop:
99 -> Modified
3 -> D

Final size : 2


//---------------------------------------------------
*/


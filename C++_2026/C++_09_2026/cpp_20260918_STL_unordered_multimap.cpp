#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

//-------------------------------------------------
// main
//-------------------------------------------------
int main()
{
    //---------------------------------------------------
    // 1. Constructors
    //---------------------------------------------------

    unordered_multimap<int, string> umm1;

    unordered_multimap<int, string> umm2 =
    {
        {1, "Apple"},
        {2, "Banana"},
        {1, "Mango"},
        {3, "Orange"},
        {2, "Grapes"}
    };

    unordered_multimap<int, string> umm3(umm2);

    unordered_multimap<int, string> umm4(move(umm3));

    vector<pair<int, string>> values =
    {
        {10, "C"},
        {20, "C++"},
        {10, "Java"}
    };

    unordered_multimap<int, string> umm5(values.begin(), values.end());

    //---------------------------------------------------
    // 2. Assignment
    //---------------------------------------------------

    umm1 = umm2;

    unordered_multimap<int, string> umm6;
    umm6 = move(umm1);

    //---------------------------------------------------
    // 3. Initial contents
    //---------------------------------------------------

    cout << "Initial contents:\n";

    for (const auto& [key, value] : umm2)
    {
        cout << key << " -> " << value << "\n";
    }

    //---------------------------------------------------
    // 4. empty()
    //---------------------------------------------------

    cout << "\nempty() : " << umm2.empty() << "\n";

    //---------------------------------------------------
    // 5. size()
    //---------------------------------------------------

    cout << "size()  : " << umm2.size() << "\n";

    //---------------------------------------------------
    // 6. max_size()
    //---------------------------------------------------

    cout << "max_size() : " << umm2.max_size() << "\n";

    //---------------------------------------------------
    // 7. insert()
    //---------------------------------------------------

    umm2.insert({ 4, "Pineapple" });
    umm2.insert(make_pair(4, "Watermelon"));

    cout << "\nAfter insert():\n";

    for (const auto& [key, value] : umm2)
    {
        cout << key << " -> " << value << "\n";
    }

    //---------------------------------------------------
    // 8. Duplicate keys
    //---------------------------------------------------

    umm2.insert({ 1, "Papaya" });
    umm2.insert({ 1, "Guava" });

    cout << "\nMultiple values for key 1:\n";

    for (const auto& [key, value] : umm2)
    {
        if (key == 1)
        {
            cout << key << " -> " << value << "\n";
        }
    }

    //---------------------------------------------------
    // 9. emplace()
    //---------------------------------------------------

    umm2.emplace(5, "Kiwi");
    umm2.emplace(5, "Peach");

    //---------------------------------------------------
    // 10. emplace_hint()
    //---------------------------------------------------

    auto hint = umm2.begin();

    umm2.emplace_hint(hint, 6, "Cherry");

    //---------------------------------------------------
    // 11. insert range
    //---------------------------------------------------

    vector<pair<int, string>> moreValues =
    {
        {7, "Lemon"},
        {7, "Lime"},
        {8, "Apple"}
    };

    umm2.insert(moreValues.begin(), moreValues.end());

    //---------------------------------------------------
    // 12. find()
    //---------------------------------------------------

    auto it = umm2.find(2);

    if (it != umm2.end())
    {
        cout << "\nfind(2) : " << it->second << "\n";
    }

    //---------------------------------------------------
    // 13. count()
    //---------------------------------------------------

    cout << "count(1) : " << umm2.count(1) << "\n";
    cout << "count(7) : " << umm2.count(7) << "\n";

    //---------------------------------------------------
    // 14. contains() - C++20
    //---------------------------------------------------

    cout << "contains(3) : " << umm2.contains(3) << "\n";
    cout << "contains(9) : " << umm2.contains(9) << "\n";

    //---------------------------------------------------
    // 15. equal_range()
    //---------------------------------------------------

    cout << "\nequal_range(1):\n";

    auto range = umm2.equal_range(1);

    for (auto i = range.first; i != range.second; ++i)
    {
        cout << i->first << " -> " << i->second << "\n";
    }

    //---------------------------------------------------
    // 16. Iterators - begin(), end()
    //---------------------------------------------------

    cout << "\nbegin() / end():\n";

    for (auto i = umm2.begin(); i != umm2.end(); ++i)
    {
        cout << i->first << " -> " << i->second << "\n";
    }

    //---------------------------------------------------
    // 17. cbegin(), cend()
    //---------------------------------------------------

    cout << "\ncbegin() / cend():\n";

    for (auto i = umm2.cbegin(); i != umm2.cend(); ++i)
    {
        cout << i->first << " -> " << i->second << "\n";
    }

    //---------------------------------------------------
    // 18. Bucket count
    //---------------------------------------------------

    cout << "\nbucket_count() : "
        << umm2.bucket_count() << "\n";

    //---------------------------------------------------
    // 19. bucket_size()
    //---------------------------------------------------

    cout << "bucket_size(0) : "
        << umm2.bucket_size(0) << "\n";

    //---------------------------------------------------
    // 20. bucket()
    //---------------------------------------------------

    cout << "bucket(1) : "
        << umm2.bucket(1) << "\n";

    //---------------------------------------------------
    // 21. Display buckets
    //---------------------------------------------------

    cout << "\nBucket contents:\n";

    for (size_t i = 0; i < umm2.bucket_count(); ++i)
    {
        cout << "Bucket " << i << " : ";

        for (auto iit = umm2.begin(i);
            iit != umm2.end(i);
            ++iit)
        {
            cout << "[" << iit->first
                << " -> " << iit->second << "] ";
        }

        cout << "\n";
    }

    //---------------------------------------------------
    // 22. load_factor()
    //---------------------------------------------------

    cout << "\nload_factor() : "
        << umm2.load_factor() << "\n";

    //---------------------------------------------------
    // 23. max_load_factor()
    //---------------------------------------------------

    cout << "max_load_factor() : "
        << umm2.max_load_factor() << "\n";

    //---------------------------------------------------
    // 24. Change max_load_factor()
    //---------------------------------------------------

    umm2.max_load_factor(0.7);

    cout << "New max_load_factor() : "
        << umm2.max_load_factor() << "\n";

    //---------------------------------------------------
    // 25. rehash()
    //---------------------------------------------------

    umm2.rehash(20);

    cout << "\nAfter rehash(20):\n";

    cout << "bucket_count() : "
        << umm2.bucket_count() << "\n";

    //---------------------------------------------------
    // 26. reserve()
    //---------------------------------------------------

    umm2.reserve(100);

    cout << "After reserve(100):\n";
    cout << "bucket_count() : "
        << umm2.bucket_count() << "\n";

    //---------------------------------------------------
    // 27. hash_function()
    //---------------------------------------------------

    auto hash = umm2.hash_function();

    cout << "\nhash_function()(10) : "
        << hash(10) << "\n";

    //---------------------------------------------------
    // 28. key_eq()
    //---------------------------------------------------

    auto keyEqual = umm2.key_eq();

    cout << "key_eq()(10, 10) : "
        << keyEqual(10, 10) << "\n";

    cout << "key_eq()(10, 20) : "
        << keyEqual(10, 20) << "\n";

    //---------------------------------------------------
    // 29. erase(iterator)
    //---------------------------------------------------

    auto eraseIt = umm2.find(3);

    if (eraseIt != umm2.end())
    {
        umm2.erase(eraseIt);
    }

    //---------------------------------------------------
    // 30. erase(key)
    //---------------------------------------------------

    size_t removed = umm2.erase(7);

    cout << "\nerase(7) removed : "
        << removed << " elements\n";

    //---------------------------------------------------
    // 31. erase(iterator range)
    //---------------------------------------------------

    auto first = umm2.begin();

    auto last = first;

    if (last != umm2.end())
    {
        ++last;
    }

    umm2.erase(first, last);

    //---------------------------------------------------
    // 32. swap()
    //---------------------------------------------------

    unordered_multimap<int, string> umm7 =
    {
        {100, "One"},
        {200, "Two"}
    };

    unordered_multimap<int, string> umm8 =
    {
        {300, "Three"},
        {400, "Four"}
    };

    umm7.swap(umm8);

    cout << "\nAfter swap():\n";

    cout << "umm7:\n";

    for (const auto& [key, value] : umm7)
    {
        cout << key << " -> " << value << "\n";
    }

    cout << "umm8:\n";

    for (const auto& [key, value] : umm8)
    {
        cout << key << " -> " << value << "\n";
    }

    //---------------------------------------------------
    // 33. clear()
    //---------------------------------------------------

    umm8.clear();

    cout << "\numm8 size after clear() : "
        << umm8.size() << "\n";

    //---------------------------------------------------
    // 34. merge()
    //---------------------------------------------------

    unordered_multimap<int, string> source =
    {
        {1, "A"},
        {2, "B"},
        {1, "C"}
    };

    unordered_multimap<int, string> destination =
    {
        {3, "D"}
    };

    destination.merge(source);

    cout << "\nAfter merge():\n";

    for (const auto& [key, value] : destination)
    {
        cout << key << " -> " << value << "\n";
    }

    cout << "source size : "
        << source.size() << "\n";

    //---------------------------------------------------
    // 35. extract(iterator)
    //---------------------------------------------------

    auto extractIt = destination.find(1);

    if (extractIt != destination.end())
    {
        auto node = destination.extract(extractIt);

        cout << "\nExtracted node:\n";
        cout << node.key() << " -> "
            << node.mapped() << "\n";
    }

    //---------------------------------------------------
    // 36. extract(key)
    //---------------------------------------------------

    auto node = destination.extract(2);

    if (!node.empty())
    {
        cout << "\nextract(key):\n";
        cout << node.key() << " -> "
            << node.mapped() << "\n";
    }

    //---------------------------------------------------
    // 37. Modify extracted node
    //---------------------------------------------------

    auto node2 = destination.extract(destination.begin());

    if (!node2.empty())
    {
        node2.key() = 99;
        node2.mapped() = "Modified";

        destination.insert(move(node2));
    }

    //---------------------------------------------------
    // 38. range-for loop
    //---------------------------------------------------

    cout << "\nRange-based for loop:\n";

    for (const auto& [key, value] : destination)
    {
        cout << key << " -> " << value << "\n";
    }

    //---------------------------------------------------
    // 39. Modify mapped value
    //---------------------------------------------------

    auto modifyIt = destination.find(3);

    if (modifyIt != destination.end())
    {
        modifyIt->second = "Updated";
    }

    //---------------------------------------------------
    // 40. Keys cannot be modified directly
    //---------------------------------------------------

    /*
        The key is const inside:

        pair<const Key, T>

        Therefore:

        modifyIt->first = 10;   // ERROR

        The mapped value can be modified:

        modifyIt->second = "...";   // OK
    */

    //---------------------------------------------------
    // 41. No operator[] or at()
    //---------------------------------------------------

    /*
        unordered_multimap does NOT provide:

        umm2[1]
        umm2.at(1)

        Reason:

        A key can have multiple values.

        Example:

        1 -> Apple
        1 -> Mango
        1 -> Orange

        Which value should operator[] return?

        Therefore unordered_multimap does not provide
        operator[] or at().
    */

    //---------------------------------------------------
    // 42. Final size
    //---------------------------------------------------

    cout << "\nFinal size : "
        << destination.size() << "\n";

    //---------------------------------------------------
    // End
    //---------------------------------------------------

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



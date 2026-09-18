#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

//-------------------------------------------------
// Display unordered_map
//-------------------------------------------------
void display(const unordered_map<int, string>& um)
{
    for (const auto& [key, value] : um)
    {
        cout << key << " -> " << value << "\n";
    }
}

//-------------------------------------------------
// main
//-------------------------------------------------
int main()
{
    //---------------------------------------------
    // 1. Constructors
    //---------------------------------------------

    unordered_map<int, string> um1;

    unordered_map<int, string> um2 =
    {
        {30, "Thirty"},
        {10, "Ten"},
        {50, "Fifty"},
        {20, "Twenty"},
        {40, "Forty"}
    };

    unordered_map<int, string> um3(um2);

    unordered_map<int, string> um4;

    um4 = um2;

    cout << "um2\n";
    display(um2);


    //---------------------------------------------
    // 2. No automatic sorting
    //---------------------------------------------

    cout << "\nUnordered traversal\n";

    for (const auto& [key, value] : um2)
    {
        cout << key << " -> " << value << "\n";
    }


    //---------------------------------------------
    // 3. operator[]
    //---------------------------------------------

    cout << "\noperator[]\n";

    cout << "um2[20] : " << um2[20] << "\n";


    //---------------------------------------------
    // 4. operator[] - insert new key
    //---------------------------------------------

    um2[60] = "Sixty";

    cout << "\nAfter um2[60] = \"Sixty\"\n";

    display(um2);


    //---------------------------------------------
    // 5. operator[] - modify existing key
    //---------------------------------------------

    um2[20] = "Twenty Modified";

    cout << "\nAfter modifying um2[20]\n";

    display(um2);


    //---------------------------------------------
    // 6. at()
    //---------------------------------------------

    cout << "\nat()\n";

    cout << "um2.at(30) : " << um2.at(30) << "\n";


    //---------------------------------------------
    // 7. insert()
    //---------------------------------------------

    auto result = um2.insert({ 70, "Seventy" });

    cout << "\ninsert({70, \"Seventy\"})\n";

    cout << "inserted : " << boolalpha << result.second << "\n";

    cout << "value    : "
        << result.first->first
        << " -> "
        << result.first->second
        << "\n";


    //---------------------------------------------
    // 8. Duplicate insert
    //---------------------------------------------

    auto duplicateResult =
        um2.insert({ 30, "New Thirty" });

    cout << "\nDuplicate insert\n";

    cout << "inserted : "
        << duplicateResult.second
        << "\n";

    cout << "value    : "
        << duplicateResult.first->first
        << " -> "
        << duplicateResult.first->second
        << "\n";


    //---------------------------------------------
    // 9. insert_or_assign()
    //---------------------------------------------

    auto assignResult =
        um2.insert_or_assign(30, "Thirty Updated");

    cout << "\ninsert_or_assign(30, \"Thirty Updated\")\n";

    cout << "inserted : "
        << assignResult.second
        << "\n";

    cout << "value    : "
        << assignResult.first->first
        << " -> "
        << assignResult.first->second
        << "\n";


    //---------------------------------------------
    // 10. try_emplace()
    //---------------------------------------------

    auto emplaceResult =
        um2.try_emplace(80, "Eighty");

    cout << "\ntry_emplace(80, \"Eighty\")\n";

    cout << "inserted : "
        << emplaceResult.second
        << "\n";

    cout << "value    : "
        << emplaceResult.first->first
        << " -> "
        << emplaceResult.first->second
        << "\n";


    //---------------------------------------------
    // 11. emplace()
    //---------------------------------------------

    auto resultEmplace =
        um2.emplace(90, "Ninety");

    cout << "\nemplace(90, \"Ninety\")\n";

    cout << "inserted : "
        << resultEmplace.second
        << "\n";


    //---------------------------------------------
    // 12. find()
    //---------------------------------------------

    cout << "\nfind()\n";

    auto findResult = um2.find(40);

    if (findResult != um2.end())
    {
        cout << "Found : "
            << findResult->first
            << " -> "
            << findResult->second
            << "\n";
    }
    else
    {
        cout << "40 not found\n";
    }


    //---------------------------------------------
    // 13. count()
    //---------------------------------------------

    cout << "\ncount()\n";

    cout << "count(40) : "
        << um2.count(40)
        << "\n";

    cout << "count(99) : "
        << um2.count(99)
        << "\n";


    //---------------------------------------------
    // 14. contains() - C++20
    //---------------------------------------------

    cout << "\ncontains()\n";

    cout << "contains(40) : "
        << um2.contains(40)
        << "\n";

    cout << "contains(99) : "
        << um2.contains(99)
        << "\n";


    //---------------------------------------------
    // 15. empty()
    //---------------------------------------------

    cout << "\nempty()\n";

    cout << "empty() : "
        << um2.empty()
        << "\n";


    //---------------------------------------------
    // 16. size()
    //---------------------------------------------

    cout << "\nsize()\n";

    cout << "size() : "
        << um2.size()
        << "\n";


    //---------------------------------------------
    // 17. max_size()
    //---------------------------------------------

    cout << "\nmax_size()\n";

    cout << "max_size() : "
        << um2.max_size()
        << "\n";


    //---------------------------------------------
    // 18. Iterators
    //---------------------------------------------

    cout << "\nIterator traversal\n";

    for (auto it = um2.begin();
        it != um2.end();
        ++it)
    {
        cout << it->first
            << " -> "
            << it->second
            << "\n";
    }


    //---------------------------------------------
    // 19. Const iterators
    //---------------------------------------------

    cout << "\nConst iterator traversal\n";

    for (auto it = um2.cbegin();
        it != um2.cend();
        ++it)
    {
        cout << it->first
            << " -> "
            << it->second
            << "\n";
    }


    //---------------------------------------------
    // 20. erase() using key
    //---------------------------------------------

    size_t erased = um2.erase(20);

    cout << "\nerase(20)\n";

    cout << "elements erased : "
        << erased
        << "\n";

    cout << "unordered_map\n";

    display(um2);


    //---------------------------------------------
    // 21. erase() using iterator
    //---------------------------------------------

    auto eraseIt = um2.find(30);

    if (eraseIt != um2.end())
    {
        um2.erase(eraseIt);
    }

    cout << "\nAfter erase(iterator)\n";

    display(um2);


    //---------------------------------------------
    // 22. erase() using range
    //---------------------------------------------

    auto first = um2.begin();
    auto last = um2.begin();

    if (last != um2.end())
    {
        ++last;
    }

    um2.erase(first, last);

    cout << "\nAfter erase(range)\n";

    display(um2);


    //---------------------------------------------
    // 23. swap()
    //---------------------------------------------

    unordered_map<int, string> mapA =
    {
        {1, "One"},
        {2, "Two"}
    };

    unordered_map<int, string> mapB =
    {
        {100, "Hundred"},
        {200, "Two Hundred"}
    };

    cout << "\nBefore swap()\n";

    cout << "mapA\n";
    display(mapA);

    cout << "mapB\n";
    display(mapB);

    mapA.swap(mapB);

    cout << "\nAfter swap()\n";

    cout << "mapA\n";
    display(mapA);

    cout << "mapB\n";
    display(mapB);


    //---------------------------------------------
    // 24. std::swap()
    //---------------------------------------------

    swap(mapA, mapB);

    cout << "\nAfter std::swap()\n";

    cout << "mapA\n";
    display(mapA);

    cout << "mapB\n";
    display(mapB);


    //---------------------------------------------
    // 25. Bucket count
    //---------------------------------------------

    cout << "\nbucket_count()\n";

    cout << "bucket_count() : "
        << um2.bucket_count()
        << "\n";


    //---------------------------------------------
    // 26. bucket()
    //---------------------------------------------

    cout << "\nbucket()\n";

    if (um2.find(40) != um2.end())
    {
        cout << "bucket(40) : "
            << um2.bucket(40)
            << "\n";
    }


    //---------------------------------------------
    // 27. bucket_size()
    //---------------------------------------------

    cout << "\nbucket_size()\n";

    size_t bucket = um2.bucket(40);

    cout << "bucket_size("
        << bucket
        << ") : "
        << um2.bucket_size(bucket)
        << "\n";


    //---------------------------------------------
    // 28. Display all buckets
    //---------------------------------------------

    cout << "\nAll buckets\n";

    for (size_t i = 0;
        i < um2.bucket_count();
        ++i)
    {
        cout << "bucket[" << i << "] : ";

        for (auto it = um2.begin(i);
            it != um2.end(i);
            ++it)
        {
            cout << it->first
                << " -> "
                << it->second
                << " ";
        }

        cout << "\n";
    }


    //---------------------------------------------
    // 29. load_factor()
    //---------------------------------------------

    cout << "\nload_factor()\n";

    cout << "load_factor() : "
        << um2.load_factor()
        << "\n";


    //---------------------------------------------
    // 30. max_load_factor()
    //---------------------------------------------

    cout << "\nmax_load_factor()\n";

    cout << "max_load_factor() : "
        << um2.max_load_factor()
        << "\n";


    //---------------------------------------------
    // 31. Change max_load_factor
    //---------------------------------------------

    um2.max_load_factor(0.5);

    cout << "\nAfter max_load_factor(0.5)\n";

    cout << "max_load_factor() : "
        << um2.max_load_factor()
        << "\n";


    //---------------------------------------------
    // 32. rehash()
    //---------------------------------------------

    cout << "\nrehash()\n";

    cout << "Before rehash : "
        << um2.bucket_count()
        << " buckets\n";

    um2.rehash(50);

    cout << "After rehash  : "
        << um2.bucket_count()
        << " buckets\n";


    //---------------------------------------------
    // 33. reserve()
    //---------------------------------------------

    cout << "\nreserve()\n";

    unordered_map<int, string> reserveMap;

    reserveMap.reserve(100);

    cout << "bucket_count() after reserve(100) : "
        << reserveMap.bucket_count()
        << "\n";


    //---------------------------------------------
    // 34. hash_function()
    //---------------------------------------------

    cout << "\nhash_function()\n";

    auto hash = um2.hash_function();

    cout << "hash(40) : "
        << hash(40)
        << "\n";


    //---------------------------------------------
    // 35. key_eq()
    //---------------------------------------------

    cout << "\nkey_eq()\n";

    auto keyEqual = um2.key_eq();

    cout << "key_eq(40, 40) : "
        << keyEqual(40, 40)
        << "\n";

    cout << "key_eq(40, 50) : "
        << keyEqual(40, 50)
        << "\n";


    //---------------------------------------------
    // 36. merge()
    //---------------------------------------------

    unordered_map<int, string> source =
    {
        {3, "Three"},
        {4, "Four"},
        {5, "Five"}
    };

    unordered_map<int, string> destination =
    {
        {1, "One"},
        {2, "Two"},
        {3, "Existing Three"}
    };

    destination.merge(source);

    cout << "\nAfter merge()\n";

    cout << "destination\n";
    display(destination);

    cout << "source\n";
    display(source);


    //---------------------------------------------
    // 37. extract()
    //---------------------------------------------

    unordered_map<int, string> extractMap =
    {
        {10, "Ten"},
        {20, "Twenty"},
        {30, "Thirty"}
    };

    auto node = extractMap.extract(20);

    cout << "\nAfter extract(20)\n";

    cout << "Extracted node : "
        << node.key()
        << " -> "
        << node.mapped()
        << "\n";

    cout << "Remaining map\n";

    display(extractMap);


    //---------------------------------------------
    // 38. Modify extracted node
    //---------------------------------------------

    node.key() = 200;

    extractMap.insert(move(node));

    cout << "\nAfter modifying extracted key to 200\n";

    display(extractMap);


    //---------------------------------------------
    // 39. Modify mapped value
    //---------------------------------------------

    unordered_map<int, string> modifyMap =
    {
        {1, "One"},
        {2, "Two"},
        {3, "Three"}
    };

    auto modifyIt = modifyMap.find(2);

    if (modifyIt != modifyMap.end())
    {
        modifyIt->second = "TWO";
    }

    cout << "\nAfter modifying mapped value\n";

    display(modifyMap);


    //---------------------------------------------
    // 40. Key cannot be modified directly
    //---------------------------------------------

    /*
        unordered_map element:

            pair<const Key, T>

        Therefore:

            it->first

        is const.

        This is NOT allowed:

            it->first = 100;

        But this is allowed:

            it->second = "New Value";
    */


    //---------------------------------------------
    // 41. clear()
    //---------------------------------------------

    unordered_map<int, string> clearMap =
    {
        {1, "One"},
        {2, "Two"},
        {3, "Three"}
    };

    clearMap.clear();

    cout << "\nAfter clear()\n";

    cout << "empty() : "
        << clearMap.empty()
        << "\n";

    cout << "size()  : "
        << clearMap.size()
        << "\n";


    //---------------------------------------------
    // 42. Function summary
    //---------------------------------------------

    cout << "\n";
    cout << "unordered_map functions\n";
    cout << "-----------------------\n";

    cout << "empty()\n";
    cout << "size()\n";
    cout << "max_size()\n";

    cout << "operator[]\n";
    cout << "at()\n";

    cout << "insert()\n";
    cout << "insert_or_assign()\n";
    cout << "try_emplace()\n";
    cout << "emplace()\n";
    cout << "emplace_hint()\n";

    cout << "find()\n";
    cout << "count()\n";
    cout << "contains()\n";

    cout << "erase()\n";
    cout << "clear()\n";

    cout << "begin()\n";
    cout << "end()\n";
    cout << "cbegin()\n";
    cout << "cend()\n";

    cout << "swap()\n";
    cout << "merge()\n";
    cout << "extract()\n";

    cout << "bucket_count()\n";
    cout << "bucket_size()\n";
    cout << "bucket()\n";

    cout << "load_factor()\n";
    cout << "max_load_factor()\n";

    cout << "rehash()\n";
    cout << "reserve()\n";

    cout << "hash_function()\n";
    cout << "key_eq()\n";




    return 0;
}


/*
//-------------------------------------------------
// Important notes
//-------------------------------------------------


    unordered_map:

        - Stores KEY + VALUE pairs.
        - Keys are UNIQUE.
        - Does NOT maintain sorted order.
        - Uses a hash table.


    Example:

        unordered_map<int, string>

        10 -> Ten
        20 -> Twenty
        30 -> Thirty


    Duplicate keys:

        um.insert({10, "Ten"});
        um.insert({10, "New Ten"});

    Second insertion fails.


    operator[]:

        um[10]

    Existing key:
        returns mapped value.

    New key:
        creates the key with a default value.


    at():

        um.at(10)

    Existing key:
        returns mapped value.

    Missing key:
        throws std::out_of_range.


    insert_or_assign():

        Existing key:
            updates the value.

        New key:
            inserts the key + value.


    try_emplace():

        Existing key:
            does not overwrite.

        New key:
            constructs/inserts the mapped value.


    Searching:

        find()
        count()
        contains()


    Hash-table functions:

        bucket_count()
        bucket_size()
        bucket()
        load_factor()
        max_load_factor()
        rehash()
        reserve()
        hash_function()
        key_eq()


    Important:

        Traversal order is NOT guaranteed.

        It can change after:

            insert()
            erase()
            rehash()
            reserve()


    Average complexity:

        Search:
            O(1)

        Insert:
            O(1)

        Erase:
            O(1)


    Worst case:

        Search:
            O(n)

        Insert:
            O(n)

        Erase:
            O(n)


    Key/value:

        it->first
            Key

        it->second
            Mapped value


    Important:

        it->first cannot be modified.

        it->second can be modified.


    No:

        lower_bound()
        upper_bound()
        equal_range()

    Those are ordered-container operations
    provided by map/multimap.


//-------------------------------------------------
Output:
//-------------------------------------------------

um2
40 -> Forty
20 -> Twenty
50 -> Fifty
10 -> Ten
30 -> Thirty

Unordered traversal
40 -> Forty
20 -> Twenty
50 -> Fifty
10 -> Ten
30 -> Thirty

operator[]
um2[20] : Twenty

After um2[60] = "Sixty"
60 -> Sixty
40 -> Forty
20 -> Twenty
50 -> Fifty
10 -> Ten
30 -> Thirty

After modifying um2[20]
60 -> Sixty
40 -> Forty
20 -> Twenty Modified
50 -> Fifty
10 -> Ten
30 -> Thirty

at()
um2.at(30) : Thirty

insert({70, "Seventy"})
inserted : true
value    : 70 -> Seventy

Duplicate insert
inserted : false
value    : 30 -> Thirty

insert_or_assign(30, "Thirty Updated")
inserted : false
value    : 30 -> Thirty Updated

try_emplace(80, "Eighty")
inserted : true
value    : 80 -> Eighty

emplace(90, "Ninety")
inserted : true

find()
Found : 40 -> Forty

count()
count(40) : 1
count(99) : 0

contains()
contains(40) : true
contains(99) : false

empty()
empty() : false

size()
size() : 9

max_size()
max_size() : 384307168202282325

Iterator traversal
90 -> Ninety
80 -> Eighty
70 -> Seventy
60 -> Sixty
40 -> Forty
20 -> Twenty Modified
50 -> Fifty
10 -> Ten
30 -> Thirty Updated

Const iterator traversal
90 -> Ninety
80 -> Eighty
70 -> Seventy
60 -> Sixty
40 -> Forty
20 -> Twenty Modified
50 -> Fifty
10 -> Ten
30 -> Thirty Updated

erase(20)
elements erased : 1
unordered_map
90 -> Ninety
80 -> Eighty
70 -> Seventy
60 -> Sixty
40 -> Forty
50 -> Fifty
10 -> Ten
30 -> Thirty Updated

After erase(iterator)
90 -> Ninety
80 -> Eighty
70 -> Seventy
60 -> Sixty
40 -> Forty
50 -> Fifty
10 -> Ten

After erase(range)
80 -> Eighty
70 -> Seventy
60 -> Sixty
40 -> Forty
50 -> Fifty
10 -> Ten

Before swap()
mapA
2 -> Two
1 -> One
mapB
200 -> Two Hundred
100 -> Hundred

After swap()
mapA
200 -> Two Hundred
100 -> Hundred
mapB
2 -> Two
1 -> One

After std::swap()
mapA
2 -> Two
1 -> One
mapB
200 -> Two Hundred
100 -> Hundred

bucket_count()
bucket_count() : 13

bucket()
bucket(40) : 1

bucket_size()
bucket_size(1) : 1

All buckets
bucket[0] :
bucket[1] : 40 -> Forty
bucket[2] : 80 -> Eighty
bucket[3] :
bucket[4] :
bucket[5] : 70 -> Seventy
bucket[6] :
bucket[7] :
bucket[8] : 60 -> Sixty
bucket[9] :
bucket[10] : 10 -> Ten
bucket[11] : 50 -> Fifty
bucket[12] :

load_factor()
load_factor() : 0.461538

max_load_factor()
max_load_factor() : 1

After max_load_factor(0.5)
max_load_factor() : 0.5

rehash()
Before rehash : 13 buckets
After rehash  : 53 buckets

reserve()
bucket_count() after reserve(100) : 103

hash_function()
hash(40) : 40

key_eq()
key_eq(40, 40) : true
key_eq(40, 50) : false

After merge()
destination
4 -> Four
5 -> Five
3 -> Existing Three
2 -> Two
1 -> One
source
3 -> Three

After extract(20)
Extracted node : 20 -> Twenty
Remaining map
30 -> Thirty
10 -> Ten

After modifying extracted key to 200
200 -> Twenty
30 -> Thirty
10 -> Ten

After modifying mapped value
3 -> Three
2 -> TWO
1 -> One

After clear()
empty() : true
size()  : 0

unordered_map functions
-----------------------
empty()
size()
max_size()
operator[]
at()
insert()
insert_or_assign()
try_emplace()
emplace()
emplace_hint()
find()
count()
contains()
erase()
clear()
begin()
end()
cbegin()
cend()
swap()
merge()
extract()
bucket_count()
bucket_size()
bucket()
load_factor()
max_load_factor()
rehash()
reserve()
hash_function()
key_eq()


//-------------------------------------------------
*/


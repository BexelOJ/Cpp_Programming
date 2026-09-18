#include <cstddef>
#include <iostream>
#include <unordered_set>
#include <functional>

using namespace std;

//---------------------------------------------------
// Display unordered_set
//---------------------------------------------------
void display(const unordered_set<int>& s)
{
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

    unordered_set<int> s1;

    unordered_set<int> s2 = { 40, 10, 30, 50, 20 };

    unordered_set<int> s3(s2);

    unordered_set<int> s4;

    s4 = s2;

    cout << "s2 : ";
    display(s2);


    //-----------------------------------------------
    // 2. insert()
    //-----------------------------------------------

    unordered_set<int> s;

    s.insert(30);
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);

    cout << "\nAfter insert() : ";
    display(s);


    //-----------------------------------------------
    // 3. Duplicate insert
    //-----------------------------------------------

    auto result = s.insert(30);

    cout << "\nDuplicate insert\n";

    cout << "inserted : " << boolalpha << result.second << "\n";

    cout << "value    : " << *result.first << "\n";


    //-----------------------------------------------
    // 4. emplace()
    //-----------------------------------------------

    auto emplaceResult = s.emplace(60);

    cout << "\nemplace(60)\n";

    cout << "inserted : " << emplaceResult.second << "\n";

    cout << "set      : ";
    display(s);


    //-----------------------------------------------
    // 5. emplace_hint()
    //-----------------------------------------------

    s.emplace_hint(s.begin(), 70);

    cout << "\nAfter emplace_hint(70) : ";
    display(s);


    //-----------------------------------------------
    // 6. Element access
    //-----------------------------------------------

    /*
        unordered_set does NOT provide:

            operator[]
            at()

        Elements are accessed using iterators.
    */

    cout << "\nElement access using iterator\n";

    auto it = s.begin();

    if (it != s.end())
    {
        cout << "begin() : " << *it << "\n";
    }


    //-----------------------------------------------
    // 7. find()
    //-----------------------------------------------

    cout << "\nfind()\n";

    auto findResult = s.find(40);

    if (findResult != s.end())
    {
        cout << "40 found\n";
    }
    else
    {
        cout << "40 not found\n";
    }


    //-----------------------------------------------
    // 8. count()
    //-----------------------------------------------

    cout << "\ncount()\n";

    cout << "count(40) : " << s.count(40) << "\n";
    cout << "count(99) : " << s.count(99) << "\n";


    //-----------------------------------------------
    // 9. contains() - C++20
    //-----------------------------------------------

    cout << "\ncontains()\n";

    cout << "contains(40) : " << s.contains(40) << "\n";
    cout << "contains(99) : " << s.contains(99) << "\n";


    //-----------------------------------------------
    // 10. empty()
    //-----------------------------------------------

    cout << "\nempty()\n";

    cout << "empty() : " << s.empty() << "\n";


    //-----------------------------------------------
    // 11. size()
    //-----------------------------------------------

    cout << "\nsize()\n";

    cout << "size() : " << s.size() << "\n";


    //-----------------------------------------------
    // 12. max_size()
    //-----------------------------------------------

    cout << "\nmax_size()\n";

    cout << "max_size() : " << s.max_size() << "\n";


    //-----------------------------------------------
    // 13. Iterators
    //-----------------------------------------------

    cout << "\nIterator traversal\n";

    cout << "begin/end : ";

    for (auto iter = s.begin(); iter != s.end(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 14. const_iterator
    //-----------------------------------------------

    cout << "\nconst_iterator traversal\n";

    cout << "cbegin/cend : ";

    for (auto iter = s.cbegin(); iter != s.cend(); ++iter)
    {
        cout << *iter << " ";
    }

    cout << "\n";


    //-----------------------------------------------
    // 15. erase() using key
    //-----------------------------------------------

    size_t erased = s.erase(20);

    cout << "\nerase(20)\n";

    cout << "elements erased : " << erased << "\n";

    cout << "set             : ";
    display(s);


    //-----------------------------------------------
    // 16. erase() using iterator
    //-----------------------------------------------

    auto eraseIt = s.find(30);

    if (eraseIt != s.end())
    {
        s.erase(eraseIt);
    }

    cout << "\nAfter erase(iterator) : ";
    display(s);


    //-----------------------------------------------
    // 17. erase() using range
    //-----------------------------------------------

    auto first = s.begin();

    if (first != s.end())
    {
        auto last = first;

        ++last;

        s.erase(first, last);
    }

    cout << "\nAfter erase(range) : ";
    display(s);


    //-----------------------------------------------
    // 18. clear()
    //-----------------------------------------------

    unordered_set<int> clearSet = { 10, 20, 30, 40 };

    clearSet.clear();

    cout << "\nAfter clear()\n";

    cout << "empty() : " << clearSet.empty() << "\n";
    cout << "size()  : " << clearSet.size() << "\n";


    //-----------------------------------------------
    // 19. swap()
    //-----------------------------------------------

    unordered_set<int> sA = { 10, 20, 30 };

    unordered_set<int> sB = { 100, 200 };

    cout << "\nBefore swap()\n";

    cout << "sA : ";
    display(sA);

    cout << "sB : ";
    display(sB);

    sA.swap(sB);

    cout << "\nAfter swap()\n";

    cout << "sA : ";
    display(sA);

    cout << "sB : ";
    display(sB);


    //-----------------------------------------------
    // 20. std::swap()
    //-----------------------------------------------

    swap(sA, sB);

    cout << "\nAfter std::swap()\n";

    cout << "sA : ";
    display(sA);

    cout << "sB : ";
    display(sB);


    //-----------------------------------------------
    // 21. bucket_count()
    //-----------------------------------------------

    cout << "\nbucket_count()\n";

    cout << "bucket_count() : " << s.bucket_count() << "\n";


    //-----------------------------------------------
    // 22. bucket()
    //-----------------------------------------------

    cout << "\nbucket()\n";

    if (s.find(40) != s.end())
    {
        cout << "bucket(40) : " << s.bucket(40) << "\n";
    }


    //-----------------------------------------------
    // 23. bucket_size()
    //-----------------------------------------------

    cout << "\nbucket_size()\n";

    size_t bucket = s.bucket(40);

    cout << "bucket_size(" << bucket << ") : "
        << s.bucket_size(bucket) << "\n";


    //-----------------------------------------------
    // 24. Display all buckets
    //-----------------------------------------------

    cout << "\nAll buckets\n";

    for (size_t i = 0; i < s.bucket_count(); ++i)
    {
        cout << "bucket[" << i << "] : ";

        for (auto iter = s.begin(i); iter != s.end(i); ++iter)
        {
            cout << *iter << " ";
        }

        cout << "\n";
    }


    //-----------------------------------------------
    // 25. load_factor()
    //-----------------------------------------------

    cout << "\nload_factor()\n";

    cout << "load_factor() : " << s.load_factor() << "\n";


    //-----------------------------------------------
    // 26. max_load_factor()
    //-----------------------------------------------

    cout << "\nmax_load_factor()\n";

    cout << "max_load_factor() : "
        << s.max_load_factor() << "\n";


    //-----------------------------------------------
    // 27. Change max_load_factor
    //-----------------------------------------------

    s.max_load_factor(0.5);

    cout << "\nAfter max_load_factor(0.5)\n";

    cout << "max_load_factor() : "
        << s.max_load_factor() << "\n";


    //-----------------------------------------------
    // 28. rehash()
    //-----------------------------------------------

    cout << "\nrehash()\n";

    cout << "Before rehash : "
        << s.bucket_count() << " buckets\n";

    s.rehash(50);

    cout << "After rehash  : "
        << s.bucket_count() << " buckets\n";


    //-----------------------------------------------
    // 29. reserve()
    //-----------------------------------------------

    cout << "\nreserve()\n";

    unordered_set<int> reserveSet;

    reserveSet.reserve(100);

    cout << "bucket_count() after reserve(100) : "
        << reserveSet.bucket_count() << "\n";


    //-----------------------------------------------
    // 30. hash_function()
    //-----------------------------------------------

    cout << "\nhash_function()\n";

    auto hash = s.hash_function();

    cout << "hash(40) : " << hash(40) << "\n";


    //-----------------------------------------------
    // 31. key_eq()
    //-----------------------------------------------

    cout << "\nkey_eq()\n";

    auto keyEqual = s.key_eq();

    cout << "key_eq(40, 40) : "
        << keyEqual(40, 40) << "\n";

    cout << "key_eq(40, 50) : "
        << keyEqual(40, 50) << "\n";


    //-----------------------------------------------
    // 32. Merge
    //-----------------------------------------------

    unordered_set<int> source = { 50, 60, 70 };

    unordered_set<int> destination = { 10, 20, 50 };

    destination.merge(source);

    cout << "\nAfter merge()\n";

    cout << "destination : ";
    display(destination);

    cout << "source      : ";
    display(source);


    //-----------------------------------------------
    // 33. Function summary
    //-----------------------------------------------

    cout << "\n";
    cout << "unordered_set functions\n";
    cout << "-----------------------\n";

    cout << "empty()\n";
    cout << "size()\n";
    cout << "max_size()\n";

    cout << "insert()\n";
    cout << "emplace()\n";
    cout << "emplace_hint()\n";

    cout << "find()\n";
    cout << "count()\n";
    cout << "contains()\n";

    cout << "erase()\n";
    cout << "clear()\n";
    cout << "swap()\n";

    cout << "begin()\n";
    cout << "end()\n";
    cout << "cbegin()\n";
    cout << "cend()\n";

    cout << "bucket_count()\n";
    cout << "bucket_size()\n";
    cout << "bucket()\n";

    cout << "load_factor()\n";
    cout << "max_load_factor()\n";

    cout << "rehash()\n";
    cout << "reserve()\n";

    cout << "hash_function()\n";
    cout << "key_eq()\n";

    cout << "merge()\n";




    return 0;
}


/*
//---------------------------------------------------
// Important notes
//---------------------------------------------------

    unordered_set:

        - Stores UNIQUE keys.
        - Does NOT maintain sorted order.
        - Uses hashing.
        - Average O(1) insertion, search and deletion.

    Example:

        insert:
            50 10 30 20 40

        traversal order:
            NOT guaranteed to be
            10 20 30 40 50


    Duplicate keys:

        s.insert(10);
            s.insert(10);
            Only one 10 is stored.


    No:

        operator[]
        at()

    Unlike set:

        No ordering functions:

            lower_bound()
            upper_bound()
            equal_range()

    Hash-table specific functions:

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

        bucket_count()
            Number of buckets.

        bucket(value)
            Bucket containing value.

        bucket_size(index)
            Number of elements in a bucket.

        load_factor()
            Average number of elements per bucket.

        max_load_factor()
            Maximum desired load factor.

        rehash(n)
            Changes the number of buckets.

        reserve(n)
            Reserves enough buckets for at least n elements.

        hash_function()
            Returns the hash function object.

        key_eq()
            Returns the key equality comparison object.



//---------------------------------------------------
Output:
//---------------------------------------------------

s2 : 20 50 30 10 40

After insert() : 40 20 50 10 30

Duplicate insert
inserted : false
value    : 30

emplace(60)
inserted : true
set      : 60 40 20 50 10 30

After emplace_hint(70) : 70 60 40 20 50 10 30

Element access using iterator
begin() : 70

find()
40 found

count()
count(40) : 1
count(99) : 0

contains()
contains(40) : true
contains(99) : false

empty()
empty() : false

size()
size() : 7

max_size()
max_size() : 1152921504606846975

Iterator traversal
begin/end : 70 60 40 20 50 10 30

const_iterator traversal
cbegin/cend : 70 60 40 20 50 10 30

erase(20)
elements erased : 1
set             : 70 60 40 50 10 30

After erase(iterator) : 70 60 40 50 10

After erase(range) : 60 40 50 10

After clear()
empty() : true
size()  : 0

Before swap()
sA : 30 20 10
sB : 200 100

After swap()
sA : 200 100
sB : 30 20 10

After std::swap()
sA : 30 20 10
sB : 200 100

bucket_count()
bucket_count() : 13

bucket()
bucket(40) : 1

bucket_size()
bucket_size(1) : 1

All buckets
bucket[0] :
bucket[1] : 40
bucket[2] :
bucket[3] :
bucket[4] :
bucket[5] :
bucket[6] :
bucket[7] :
bucket[8] : 60
bucket[9] :
bucket[10] : 10
bucket[11] : 50
bucket[12] :

load_factor()
load_factor() : 0.307692

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
destination : 60 70 50 20 10
source      : 50

unordered_set functions
-----------------------
empty()
size()
max_size()
insert()
emplace()
emplace_hint()
find()
count()
contains()
erase()
clear()
swap()
begin()
end()
cbegin()
cend()
bucket_count()
bucket_size()
bucket()
load_factor()
max_load_factor()
rehash()
reserve()
hash_function()
key_eq()
merge()


//---------------------------------------------------
*/


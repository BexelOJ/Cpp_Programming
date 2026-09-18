#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

//-------------------------------------------------
// Display map
//-------------------------------------------------
void display(const map<int, string>& m)
{
    for (const auto& [key, value] : m)
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

    map<int, string> m1;

    map<int, string> m2 =
    {
        {30, "Thirty"},
        {10, "Ten"},
        {50, "Fifty"},
        {20, "Twenty"},
        {40, "Forty"}
    };

    map<int, string> m3(m2);

    map<int, string> m4;

    m4 = m2;

    cout << "m2\n";
    display(m2);


    //---------------------------------------------
    // 2. Automatic sorting
    //---------------------------------------------

    cout << "\nAutomatic sorting\n";

    for (const auto& [key, value] : m2)
    {
        cout << key << " -> " << value << "\n";
    }


    //---------------------------------------------
    // 3. operator[]
    //---------------------------------------------

    cout << "\noperator[]\n";

    cout << "m2[20] : " << m2[20] << "\n";


    //---------------------------------------------
    // 4. operator[] - insert new key
    //---------------------------------------------

    m2[60] = "Sixty";

    cout << "\nAfter m2[60] = \"Sixty\"\n";

    display(m2);


    //---------------------------------------------
    // 5. operator[] - modify existing key
    //---------------------------------------------

    m2[20] = "Twenty Modified";

    cout << "\nAfter modifying m2[20]\n";

    display(m2);


    //---------------------------------------------
    // 6. at()
    //---------------------------------------------

    cout << "\nat()\n";

    cout << "m2.at(30) : " << m2.at(30) << "\n";


    //---------------------------------------------
    // 7. insert()
    //---------------------------------------------

    auto result = m2.insert({ 70, "Seventy" });

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

    auto duplicateResult = m2.insert({ 30, "New Thirty" });

    cout << "\nDuplicate insert\n";

    cout << "inserted : " << duplicateResult.second << "\n";

    cout << "value    : "
        << duplicateResult.first->first
        << " -> "
        << duplicateResult.first->second
        << "\n";


    //---------------------------------------------
    // 9. insert_or_assign()
    //---------------------------------------------

    auto assignResult =
        m2.insert_or_assign(30, "Thirty Updated");

    cout << "\ninsert_or_assign(30, \"Thirty Updated\")\n";

    cout << "inserted : " << assignResult.second << "\n";

    cout << "value    : "
        << assignResult.first->first
        << " -> "
        << assignResult.first->second
        << "\n";


    //---------------------------------------------
    // 10. try_emplace()
    //---------------------------------------------

    auto emplaceResult =
        m2.try_emplace(80, "Eighty");

    cout << "\ntry_emplace(80, \"Eighty\")\n";

    cout << "inserted : " << emplaceResult.second << "\n";

    cout << "value    : "
        << emplaceResult.first->first
        << " -> "
        << emplaceResult.first->second
        << "\n";


    //---------------------------------------------
    // 11. emplace()
    //---------------------------------------------

    auto resultEmplace =
        m2.emplace(90, "Ninety");

    cout << "\nemplace(90, \"Ninety\")\n";

    cout << "inserted : " << resultEmplace.second << "\n";


    //---------------------------------------------
    // 12. find()
    //---------------------------------------------

    cout << "\nfind()\n";

    auto findResult = m2.find(40);

    if (findResult != m2.end())
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

    cout << "count(40) : " << m2.count(40) << "\n";
    cout << "count(99) : " << m2.count(99) << "\n";


    //---------------------------------------------
    // 14. contains() - C++20
    //---------------------------------------------

    cout << "\ncontains()\n";

    cout << "contains(40) : " << m2.contains(40) << "\n";
    cout << "contains(99) : " << m2.contains(99) << "\n";


    //---------------------------------------------
    // 15. empty()
    //---------------------------------------------

    cout << "\nempty()\n";

    cout << "empty() : " << m2.empty() << "\n";


    //---------------------------------------------
    // 16. size()
    //---------------------------------------------

    cout << "\nsize()\n";

    cout << "size() : " << m2.size() << "\n";


    //---------------------------------------------
    // 17. max_size()
    //---------------------------------------------

    cout << "\nmax_size()\n";

    cout << "max_size() : " << m2.max_size() << "\n";


    //---------------------------------------------
    // 18. Iterators
    //---------------------------------------------

    cout << "\nIterator traversal\n";

    for (auto it = m2.begin(); it != m2.end(); ++it)
    {
        cout << it->first << " -> "
            << it->second << "\n";
    }


    //---------------------------------------------
    // 19. Reverse iterators
    //---------------------------------------------

    cout << "\nReverse traversal\n";

    for (auto it = m2.rbegin(); it != m2.rend(); ++it)
    {
        cout << it->first << " -> "
            << it->second << "\n";
    }


    //---------------------------------------------
    // 20. Const iterators
    //---------------------------------------------

    cout << "\nConst iterator traversal\n";

    for (auto it = m2.cbegin(); it != m2.cend(); ++it)
    {
        cout << it->first << " -> "
            << it->second << "\n";
    }


    //---------------------------------------------
    // 21. lower_bound()
    //---------------------------------------------

    cout << "\nlower_bound()\n";

    auto lower = m2.lower_bound(35);

    if (lower != m2.end())
    {
        cout << "lower_bound(35) : "
            << lower->first
            << " -> "
            << lower->second
            << "\n";
    }


    //---------------------------------------------
    // 22. upper_bound()
    //---------------------------------------------

    cout << "\nupper_bound()\n";

    auto upper = m2.upper_bound(40);

    if (upper != m2.end())
    {
        cout << "upper_bound(40) : "
            << upper->first
            << " -> "
            << upper->second
            << "\n";
    }


    //---------------------------------------------
    // 23. equal_range()
    //---------------------------------------------

    cout << "\nequal_range()\n";

    auto range = m2.equal_range(40);

    cout << "lower : ";

    if (range.first != m2.end())
    {
        cout << range.first->first
            << " -> "
            << range.first->second;
    }

    cout << "\n";

    cout << "upper : ";

    if (range.second != m2.end())
    {
        cout << range.second->first
            << " -> "
            << range.second->second;
    }

    cout << "\n";


    //---------------------------------------------
    // 24. erase() using key
    //---------------------------------------------

    size_t erased = m2.erase(20);

    cout << "\nerase(20)\n";

    cout << "elements erased : " << erased << "\n";

    cout << "map\n";
    display(m2);


    //---------------------------------------------
    // 25. erase() using iterator
    //---------------------------------------------

    auto eraseIt = m2.find(30);

    if (eraseIt != m2.end())
    {
        m2.erase(eraseIt);
    }

    cout << "\nAfter erase(iterator)\n";

    display(m2);


    //---------------------------------------------
    // 26. erase() using range
    //---------------------------------------------

    auto first = m2.begin();
    auto last = m2.begin();

    if (last != m2.end())
    {
        ++last;
    }

    m2.erase(first, last);

    cout << "\nAfter erase(range)\n";

    display(m2);


    //---------------------------------------------
    // 27. swap()
    //---------------------------------------------

    map<int, string> mapA =
    {
        {1, "One"},
        {2, "Two"}
    };

    map<int, string> mapB =
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
    // 28. std::swap()
    //---------------------------------------------

    swap(mapA, mapB);

    cout << "\nAfter std::swap()\n";

    cout << "mapA\n";
    display(mapA);

    cout << "mapB\n";
    display(mapB);


    //---------------------------------------------
    // 29. merge()
    //---------------------------------------------

    map<int, string> source =
    {
        {3, "Three"},
        {4, "Four"},
        {5, "Five"}
    };

    map<int, string> destination =
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
    // 30. extract()
    //---------------------------------------------

    map<int, string> extractMap =
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
    // 31. Modify extracted node
    //---------------------------------------------

    node.key() = 200;

    extractMap.insert(move(node));

    cout << "\nAfter modifying extracted key to 200\n";

    display(extractMap);


    //---------------------------------------------
    // 32. Custom comparator
    //---------------------------------------------

    map<int, string, greater<int>> descendingMap =
    {
        {10, "Ten"},
        {30, "Thirty"},
        {20, "Twenty"}
    };

    cout << "\nDescending map\n";

    for (const auto& [key, value] : descendingMap)
    {
        cout << key << " -> "
            << value << "\n";
    }


    //---------------------------------------------
    // 33. Modify mapped value through iterator
    //---------------------------------------------

    map<int, string> modifyMap =
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
    // 34. Key cannot be modified directly
    //---------------------------------------------

    /*
        map element:

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
    // 35. clear()
    //---------------------------------------------

    map<int, string> clearMap =
    {
        {1, "One"},
        {2, "Two"},
        {3, "Three"}
    };

    clearMap.clear();

    cout << "\nAfter clear()\n";

    cout << "empty() : " << clearMap.empty() << "\n";
    cout << "size()  : " << clearMap.size() << "\n";


    //---------------------------------------------
    // 36. Function summary
    //---------------------------------------------

    cout << "\n";
    cout << "map functions\n";
    cout << "-------------\n";

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

    cout << "lower_bound()\n";
    cout << "upper_bound()\n";
    cout << "equal_range()\n";

    cout << "erase()\n";
    cout << "clear()\n";

    cout << "begin()\n";
    cout << "end()\n";
    cout << "cbegin()\n";
    cout << "cend()\n";
    cout << "rbegin()\n";
    cout << "rend()\n";

    cout << "swap()\n";
    cout << "merge()\n";
    cout << "extract()\n";




    return 0;
}


/*
//-------------------------------------------------
// Important notes
//-------------------------------------------------

    map:

        - Stores KEY + VALUE pairs.
        - Keys are UNIQUE.
        - Keys are automatically SORTED.
        - Implemented using an ordered tree structure.

    Example:

        map<int, string>

        10 -> Ten
        20 -> Twenty
        30 -> Thirty


    Duplicate keys are NOT allowed.

        m.insert({10, "Ten"});
        m.insert({10, "New Ten"});

    Second insertion fails.


    operator[]:

        m[10]

    If key exists:
        returns the mapped value.

    If key does NOT exist:
        creates the key with a default value.


     at():

        m.at(10)

    If key does not exist:
        throws std::out_of_range.


    insert_or_assign():

        Existing key:
            updates value.

        New key:
            inserts key + value.


    try_emplace():

        Existing key:
            does not overwrite the value.

        New key:
            constructs/inserts the mapped value.


    Searching:

        find()
        count()
        contains()


    Ordered operations:

        lower_bound()
        upper_bound()
        equal_range()


    Key/value:

        it->first
            Key

        it->second
            Mapped value


    Important:

        it->first cannot be modified.

        it->second can be modified.


    Time complexity:

        Search:
            O(log n)

        Insert:
            O(log n)

        Erase:
            O(log n)


    C++20:

        contains()
        insert_or_assign()
        try_emplace()


    No:

        push_back()
        push_front()
        pop_back()
        pop_front()



//-------------------------------------------------
Output:
//-------------------------------------------------

m2
10 -> Ten
20 -> Twenty
30 -> Thirty
40 -> Forty
50 -> Fifty

Automatic sorting
10 -> Ten
20 -> Twenty
30 -> Thirty
40 -> Forty
50 -> Fifty

operator[]
m2[20] : Twenty

After m2[60] = "Sixty"
10 -> Ten
20 -> Twenty
30 -> Thirty
40 -> Forty
50 -> Fifty
60 -> Sixty

After modifying m2[20]
10 -> Ten
20 -> Twenty Modified
30 -> Thirty
40 -> Forty
50 -> Fifty
60 -> Sixty

at()
m2.at(30) : Thirty

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
max_size() : 256204778801521550

Iterator traversal
10 -> Ten
20 -> Twenty Modified
30 -> Thirty Updated
40 -> Forty
50 -> Fifty
60 -> Sixty
70 -> Seventy
80 -> Eighty
90 -> Ninety

Reverse traversal
90 -> Ninety
80 -> Eighty
70 -> Seventy
60 -> Sixty
50 -> Fifty
40 -> Forty
30 -> Thirty Updated
20 -> Twenty Modified
10 -> Ten

Const iterator traversal
10 -> Ten
20 -> Twenty Modified
30 -> Thirty Updated
40 -> Forty
50 -> Fifty
60 -> Sixty
70 -> Seventy
80 -> Eighty
90 -> Ninety

lower_bound()
lower_bound(35) : 40 -> Forty

upper_bound()
upper_bound(40) : 50 -> Fifty

equal_range()
lower : 40 -> Forty
upper : 50 -> Fifty

erase(20)
elements erased : 1
map
10 -> Ten
30 -> Thirty Updated
40 -> Forty
50 -> Fifty
60 -> Sixty
70 -> Seventy
80 -> Eighty
90 -> Ninety

After erase(iterator)
10 -> Ten
40 -> Forty
50 -> Fifty
60 -> Sixty
70 -> Seventy
80 -> Eighty
90 -> Ninety

After erase(range)
40 -> Forty
50 -> Fifty
60 -> Sixty
70 -> Seventy
80 -> Eighty
90 -> Ninety

Before swap()
mapA
1 -> One
2 -> Two
mapB
100 -> Hundred
200 -> Two Hundred

After swap()
mapA
100 -> Hundred
200 -> Two Hundred
mapB
1 -> One
2 -> Two

After std::swap()
mapA
1 -> One
2 -> Two
mapB
100 -> Hundred
200 -> Two Hundred

After merge()
destination
1 -> One
2 -> Two
3 -> Existing Three
4 -> Four
5 -> Five
source
3 -> Three

After extract(20)
Extracted node : 20 -> Twenty
Remaining map
10 -> Ten
30 -> Thirty

After modifying extracted key to 200
10 -> Ten
30 -> Thirty
200 -> Twenty

Descending map
30 -> Thirty
20 -> Twenty
10 -> Ten

After modifying mapped value
1 -> One
2 -> TWO
3 -> Three

After clear()
empty() : true
size()  : 0

map functions
-------------
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
lower_bound()
upper_bound()
equal_range()
erase()
clear()
begin()
end()
cbegin()
cend()
rbegin()
rend()
swap()
merge()
extract()


//-------------------------------------------------
*/




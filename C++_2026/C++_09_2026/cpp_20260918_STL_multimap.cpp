#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

//---------------------------------------------------
// Display multimap
//---------------------------------------------------
void display(const multimap<int, string>& mm)
{
    for (const auto& [key, value] : mm)
    {
        cout << key << " -> " << value << "\n";
    }
}

//---------------------------------------------------
// main
//---------------------------------------------------
int main()
{
    //-----------------------------------------------
    // 1. Constructors
    //-----------------------------------------------

    multimap<int, string> mm1;

    multimap<int, string> mm2 =
    {
        {30, "Thirty"},
        {10, "Ten"},
        {30, "Thirty Again"},
        {50, "Fifty"},
        {20, "Twenty"},
        {30, "Third Thirty"}
    };

    multimap<int, string> mm3(mm2);

    multimap<int, string> mm4;

    mm4 = mm2;

    cout << "mm2\n";
    display(mm2);


    //-----------------------------------------------
    // 2. Automatic sorting
    //-----------------------------------------------

    cout << "\nAutomatic sorting\n";

    for (const auto& [key, value] : mm2)
    {
        cout << key << " -> " << value << "\n";
    }


    //-----------------------------------------------
    // 3. Duplicate keys
    //-----------------------------------------------

    cout << "\nDuplicate keys\n";

    mm2.insert({ 30, "Fourth Thirty" });

    mm2.insert({ 30, "Fifth Thirty" });

    display(mm2);


    //-----------------------------------------------
    // 4. insert()
    //-----------------------------------------------

    auto result = mm2.insert({ 60, "Sixty" });

    cout << "\ninsert({60, \"Sixty\"})\n";

    cout << "value : "
        << result->first
        << " -> "
        << result->second
        << "\n";


    //-----------------------------------------------
    // 5. emplace()
    //-----------------------------------------------

    auto emplaceResult =
        mm2.emplace(70, "Seventy");

    cout << "\nemplace(70, \"Seventy\")\n";

    cout << "value : "
        << emplaceResult->first
        << " -> "
        << emplaceResult->second
        << "\n";


    //-----------------------------------------------
    // 6. emplace_hint()
    //-----------------------------------------------

    mm2.emplace_hint(mm2.begin(), 80, "Eighty");

    cout << "\nAfter emplace_hint()\n";

    display(mm2);


    //-----------------------------------------------
    // 7. operator[] and at()
    //-----------------------------------------------

    /*
        multimap does NOT provide:

            operator[]
            at()

        Because multiple values can exist for one key.

        Example:

            30 -> Thirty
            30 -> Thirty Again
            30 -> Third Thirty

        Therefore:

            mm[30]

        would be ambiguous.
    */


    //-----------------------------------------------
    // 8. find()
    //-----------------------------------------------

    cout << "\nfind(30)\n";

    auto findResult = mm2.find(30);

    if (findResult != mm2.end())
    {
        cout << "First matching element : "
            << findResult->first
            << " -> "
            << findResult->second
            << "\n";
    }


    //-----------------------------------------------
    // 9. count()
    //-----------------------------------------------

    cout << "\ncount()\n";

    cout << "count(30) : "
        << mm2.count(30)
        << "\n";

    cout << "count(99) : "
        << mm2.count(99)
        << "\n";


    //-----------------------------------------------
    // 10. contains() - C++20
    //-----------------------------------------------

    cout << "\ncontains()\n";

    cout << "contains(30) : "
        << mm2.contains(30)
        << "\n";

    cout << "contains(99) : "
        << mm2.contains(99)
        << "\n";


    //-----------------------------------------------
    // 11. empty()
    //-----------------------------------------------

    cout << "\nempty()\n";

    cout << "empty() : "
        << boolalpha
        << mm2.empty()
        << "\n";


    //-----------------------------------------------
    // 12. size()
    //-----------------------------------------------

    cout << "\nsize()\n";

    cout << "size() : "
        << mm2.size()
        << "\n";


    //-----------------------------------------------
    // 13. max_size()
    //-----------------------------------------------

    cout << "\nmax_size()\n";

    cout << "max_size() : "
        << mm2.max_size()
        << "\n";


    //-----------------------------------------------
    // 14. Iterators
    //-----------------------------------------------

    cout << "\nIterator traversal\n";

    for (auto it = mm2.begin();
        it != mm2.end();
        ++it)
    {
        cout << it->first
            << " -> "
            << it->second
            << "\n";
    }


    //-----------------------------------------------
    // 15. Reverse iterators
    //-----------------------------------------------

    cout << "\nReverse traversal\n";

    for (auto it = mm2.rbegin();
        it != mm2.rend();
        ++it)
    {
        cout << it->first
            << " -> "
            << it->second
            << "\n";
    }


    //-----------------------------------------------
    // 16. Const iterators
    //-----------------------------------------------

    cout << "\nConst iterator traversal\n";

    for (auto it = mm2.cbegin();
        it != mm2.cend();
        ++it)
    {
        cout << it->first
            << " -> "
            << it->second
            << "\n";
    }


    //-----------------------------------------------
    // 17. lower_bound()
    //-----------------------------------------------

    cout << "\nlower_bound(30)\n";

    auto lower = mm2.lower_bound(30);

    if (lower != mm2.end())
    {
        cout << "lower_bound : "
            << lower->first
            << " -> "
            << lower->second
            << "\n";
    }


    //-----------------------------------------------
    // 18. upper_bound()
    //-----------------------------------------------

    cout << "\nupper_bound(30)\n";

    auto upper = mm2.upper_bound(30);

    if (upper != mm2.end())
    {
        cout << "upper_bound : "
            << upper->first
            << " -> "
            << upper->second
            << "\n";
    }


    //-----------------------------------------------
    // 19. equal_range()
    //-----------------------------------------------

    cout << "\nequal_range(30)\n";

    auto range = mm2.equal_range(30);

    cout << "Elements with key 30:\n";

    for (auto it = range.first;
        it != range.second;
        ++it)
    {
        cout << it->first
            << " -> "
            << it->second
            << "\n";
    }


    //-----------------------------------------------
    // 20. erase() using key
    //-----------------------------------------------

    multimap<int, string> eraseMap =
    {
        {10, "Ten"},
        {20, "Twenty"},
        {20, "Twenty Again"},
        {30, "Thirty"},
        {20, "Twenty Third"}
    };

    size_t erased = eraseMap.erase(20);

    cout << "\nerase(20)\n";

    cout << "elements erased : "
        << erased
        << "\n";

    cout << "Remaining map\n";

    display(eraseMap);


    //-----------------------------------------------
    // 21. erase() using iterator
    //-----------------------------------------------

    auto eraseIt = mm2.find(30);

    if (eraseIt != mm2.end())
    {
        mm2.erase(eraseIt);
    }

    cout << "\nAfter erase(iterator)\n";

    display(mm2);


    //-----------------------------------------------
    // 22. erase() using range
    //-----------------------------------------------

    auto first = mm2.begin();
    auto last = mm2.begin();

    if (last != mm2.end())
    {
        ++last;
    }

    mm2.erase(first, last);

    cout << "\nAfter erase(range)\n";

    display(mm2);


    //-----------------------------------------------
    // 23. swap()
    //-----------------------------------------------

    multimap<int, string> mapA =
    {
        {1, "One"},
        {2, "Two"},
        {2, "Two Again"}
    };

    multimap<int, string> mapB =
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


    //-----------------------------------------------
    // 24. std::swap()
    //-----------------------------------------------

    swap(mapA, mapB);

    cout << "\nAfter std::swap()\n";

    cout << "mapA\n";
    display(mapA);

    cout << "mapB\n";
    display(mapB);


    //-----------------------------------------------
    // 25. merge()
    //-----------------------------------------------

    multimap<int, string> source =
    {
        {3, "Three"},
        {3, "Three Again"},
        {4, "Four"}
    };

    multimap<int, string> destination =
    {
        {1, "One"},
        {3, "Existing Three"}
    };

    destination.merge(source);

    cout << "\nAfter merge()\n";

    cout << "destination\n";
    display(destination);

    cout << "source\n";
    display(source);


    //-----------------------------------------------
    // 26. extract()
    //-----------------------------------------------

    multimap<int, string> extractMap =
    {
        {10, "Ten"},
        {20, "Twenty"},
        {20, "Twenty Again"},
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


    //-----------------------------------------------
    // 27. Modify extracted node
    //-----------------------------------------------

    node.key() = 200;

    extractMap.insert(move(node));

    cout << "\nAfter modifying extracted key to 200\n";

    display(extractMap);


    //-----------------------------------------------
    // 28. Modify mapped value
    //-----------------------------------------------

    multimap<int, string> modifyMap =
    {
        {1, "One"},
        {2, "Two"},
        {2, "Two Again"},
        {3, "Three"}
    };

    auto modifyIt = modifyMap.find(2);

    if (modifyIt != modifyMap.end())
    {
        modifyIt->second = "TWO";
    }

    cout << "\nAfter modifying mapped value\n";

    display(modifyMap);


    //-----------------------------------------------
    // 29. Custom comparator
    //-----------------------------------------------

    multimap<int, string, greater<int>> descendingMap =
    {
        {10, "Ten"},
        {30, "Thirty"},
        {20, "Twenty"},
        {20, "Twenty Again"}
    };

    cout << "\nDescending multimap\n";

    for (const auto& [key, value] : descendingMap)
    {
        cout << key
            << " -> "
            << value
            << "\n";
    }


    //-----------------------------------------------
    // 30. clear()
    //-----------------------------------------------

    multimap<int, string> clearMap =
    {
        {1, "One"},
        {2, "Two"},
        {2, "Two Again"},
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


    //-----------------------------------------------
    // 31. Function summary
    //-----------------------------------------------

    cout << "\n";
    cout << "multimap functions\n";
    cout << "------------------\n";

    cout << "empty()\n";
    cout << "size()\n";
    cout << "max_size()\n";

    cout << "insert()\n";
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
//---------------------------------------------------
    // Important notes
    //-----------------------------------------------


        multimap:

            - Stores KEY + VALUE pairs.
            - Duplicate keys ARE allowed.
            - Keys are automatically SORTED.
            - Implemented using an ordered tree structure.


        Example:

            10 -> Ten
            20 -> Twenty
            20 -> Twenty Again
            30 -> Thirty


        No:

            operator[]
            at()

        Because one key can have multiple values.


        Searching:

            find(key)
                Returns one matching element.

            count(key)
                Returns number of elements with the key.

            contains(key)
                Returns true if at least one matching key exists.


        Finding ALL values for a key:

            auto range = mm.equal_range(key);

            for (auto it = range.first;
                 it != range.second;
                 ++it)
            {
                ...
            }


        erase(key):

            Removes ALL elements with that key.

            Example:

                20 -> Twenty
                20 -> Twenty Again
                20 -> Twenty Third

                mm.erase(20);

            removes all three.


        erase(iterator):

            Removes only the element pointed to
            by that iterator.


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


        No:

            operator[]
            at()
            push_back()
            push_front()
            pop_back()
            pop_front()

//---------------------------------------------------
Output:
//---------------------------------------------------

mm2
10 -> Ten
20 -> Twenty
30 -> Thirty
30 -> Thirty Again
30 -> Third Thirty
50 -> Fifty

Automatic sorting
10 -> Ten
20 -> Twenty
30 -> Thirty
30 -> Thirty Again
30 -> Third Thirty
50 -> Fifty

Duplicate keys
10 -> Ten
20 -> Twenty
30 -> Thirty
30 -> Thirty Again
30 -> Third Thirty
30 -> Fourth Thirty
30 -> Fifth Thirty
50 -> Fifty

insert({60, "Sixty"})
value : 60 -> Sixty

emplace(70, "Seventy")
value : 70 -> Seventy

After emplace_hint()
10 -> Ten
20 -> Twenty
30 -> Thirty
30 -> Thirty Again
30 -> Third Thirty
30 -> Fourth Thirty
30 -> Fifth Thirty
50 -> Fifty
60 -> Sixty
70 -> Seventy
80 -> Eighty

find(30)
First matching element : 30 -> Thirty

count()
count(30) : 5
count(99) : 0

contains()
contains(30) : 1
contains(99) : 0

empty()
empty() : false

size()
size() : 11

max_size()
max_size() : 256204778801521550

Iterator traversal
10 -> Ten
20 -> Twenty
30 -> Thirty
30 -> Thirty Again
30 -> Third Thirty
30 -> Fourth Thirty
30 -> Fifth Thirty
50 -> Fifty
60 -> Sixty
70 -> Seventy
80 -> Eighty

Reverse traversal
80 -> Eighty
70 -> Seventy
60 -> Sixty
50 -> Fifty
30 -> Fifth Thirty
30 -> Fourth Thirty
30 -> Third Thirty
30 -> Thirty Again
30 -> Thirty
20 -> Twenty
10 -> Ten

Const iterator traversal
10 -> Ten
20 -> Twenty
30 -> Thirty
30 -> Thirty Again
30 -> Third Thirty
30 -> Fourth Thirty
30 -> Fifth Thirty
50 -> Fifty
60 -> Sixty
70 -> Seventy
80 -> Eighty

lower_bound(30)
lower_bound : 30 -> Thirty

upper_bound(30)
upper_bound : 50 -> Fifty

equal_range(30)
Elements with key 30:
30 -> Thirty
30 -> Thirty Again
30 -> Third Thirty
30 -> Fourth Thirty
30 -> Fifth Thirty

erase(20)
elements erased : 3
Remaining map
10 -> Ten
30 -> Thirty

After erase(iterator)
10 -> Ten
20 -> Twenty
30 -> Thirty Again
30 -> Third Thirty
30 -> Fourth Thirty
30 -> Fifth Thirty
50 -> Fifty
60 -> Sixty
70 -> Seventy
80 -> Eighty

After erase(range)
20 -> Twenty
30 -> Thirty Again
30 -> Third Thirty
30 -> Fourth Thirty
30 -> Fifth Thirty
50 -> Fifty
60 -> Sixty
70 -> Seventy
80 -> Eighty

Before swap()
mapA
1 -> One
2 -> Two
2 -> Two Again
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
2 -> Two Again

After std::swap()
mapA
1 -> One
2 -> Two
2 -> Two Again
mapB
100 -> Hundred
200 -> Two Hundred

After merge()
destination
1 -> One
3 -> Existing Three
3 -> Three
3 -> Three Again
4 -> Four
source

After extract(20)
Extracted node : 20 -> Twenty
Remaining map
10 -> Ten
20 -> Twenty Again
30 -> Thirty

After modifying extracted key to 200
10 -> Ten
20 -> Twenty Again
30 -> Thirty
200 -> Twenty

After modifying mapped value
1 -> One
2 -> TWO
2 -> Two Again
3 -> Three

Descending multimap
30 -> Thirty
20 -> Twenty
20 -> Twenty Again
10 -> Ten

After clear()
empty() : true
size()  : 0

multimap functions
------------------
empty()
size()
max_size()
insert()
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


//---------------------------------------------------
*/



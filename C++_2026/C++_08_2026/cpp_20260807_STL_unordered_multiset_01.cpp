#include <iostream>
#include <unordered_set>
//Allows duplicates and uses hashing

void printUnorderedMultiset(
    const std::unordered_multiset<int>& ums)
{
    for (int value : ums)
        std::cout << value << ' ';

    std::cout << '\n';
}

int main()
{
    std::unordered_multiset<int> ums = {
        10, 20, 20, 30, 30, 30
    };

    std::cout << "Initial unordered_multiset: ";
    printUnorderedMultiset(ums);

    // ----------------------------------------------
    // insert()
    ums.insert(40);
    // ----------------------------------------------
    // emplace()
    ums.emplace(50);

    std::cout << "After insert/emplace: ";
    printUnorderedMultiset(ums);

    // ----------------------------------------------
    // find()
    auto it = ums.find(30);

    if (it != ums.end())
        std::cout << "find(30): "
        << *it << '\n';

    // ----------------------------------------------
    // count()
    std::cout << "count(30): "
        << ums.count(30) << '\n';

    // ----------------------------------------------
    // contains()
    std::cout << "contains(20): "
        << ums.contains(20) << '\n';

    // ----------------------------------------------
    // equal_range()
    auto range = ums.equal_range(30);

    std::cout << "equal_range(30): ";

    for (auto i = range.first; i != range.second; ++i)
        std::cout << *i << ' ';

    std::cout << '\n';

    // ----------------------------------------------
    // erase(iterator)
    it = ums.find(20);

    if (it != ums.end())
        ums.erase(it);

    std::cout << "After erase(iterator): ";
    printUnorderedMultiset(ums);

    // ----------------------------------------------
    // erase(key)
    ums.erase(30);

    std::cout << "After erase(30): ";
    printUnorderedMultiset(ums);

    // ----------------------------------------------
    // size()
    std::cout << "ums.size(): "
        << ums.size() << '\n';

    // ----------------------------------------------
    // empty()
    std::cout << "ums.empty(): "
        << ums.empty() << '\n';

    // ----------------------------------------------
    // max_size()
    std::cout << "ums.max_size(): "
        << ums.max_size() << '\n';

    // ----------------------------------------------
    // bucket_count()
    std::cout << "bucket_count(): "
        << ums.bucket_count() << '\n';

    // ----------------------------------------------
    // load_factor()
    std::cout << "load_factor(): "
        << ums.load_factor() << '\n';

    // ----------------------------------------------
    // clear()
    ums.clear();

    std::cout << "After clear(): "
        << ums.empty() << '\n';


    return 0;
}



/*
//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


*/



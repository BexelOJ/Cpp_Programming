#include <iostream>
#include <unordered_set>
//No sorting. Unique elements. Uses hashing

void printUnorderedSet(const std::unordered_set<int>& us)
{
    for (int value : us)
        std::cout << value << ' ';

    std::cout << '\n';
}

int main()
{
    std::unordered_set<int> us = {
        50, 20, 40, 10, 30, 20
    };

    std::cout << "Initial unordered_set: ";
    printUnorderedSet(us);

    // ----------------------------------------------
    // insert()
    us.insert(60);

    std::cout << "After insert(60): ";
    printUnorderedSet(us);

    // ----------------------------------------------
    // emplace()
    us.emplace(70);

    std::cout << "After emplace(70): ";
    printUnorderedSet(us);

    // ----------------------------------------------
    // find()
    auto it = us.find(40);

    if (it != us.end())
        std::cout << "find(40): " << *it << '\n';

    // ----------------------------------------------
    // count()
    std::cout << "count(40): "
        << us.count(40) << '\n';

    // ----------------------------------------------
    // contains()
    std::cout << "contains(50): "
        << us.contains(50) << '\n';

    // ----------------------------------------------
    // erase(iterator)
    it = us.find(30);

    if (it != us.end())
        us.erase(it);

    std::cout << "After erase(iterator): ";
    printUnorderedSet(us);

    // ----------------------------------------------
    // erase(key)
    us.erase(20);

    std::cout << "After erase(20): ";
    printUnorderedSet(us);

    // ----------------------------------------------
    // size()
    std::cout << "us.size(): "
        << us.size() << '\n';

    // ----------------------------------------------
    // empty()
    std::cout << "us.empty(): "
        << us.empty() << '\n';

    // ----------------------------------------------
    // max_size()
    std::cout << "us.max_size(): "
        << us.max_size() << '\n';

    // ----------------------------------------------
    // bucket_count()
    std::cout << "bucket_count(): "
        << us.bucket_count() << '\n';

    // ----------------------------------------------
    // load_factor()
    std::cout << "load_factor(): "
        << us.load_factor() << '\n';

    // ----------------------------------------------
    // clear()
    us.clear();

    std::cout << "After clear(): "
        << us.empty() << '\n';


    return 0;
}



/*
//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------



*/



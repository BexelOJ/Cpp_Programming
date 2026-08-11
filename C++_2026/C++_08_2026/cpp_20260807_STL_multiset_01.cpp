#include <iostream>
#include <set>
//Unlike set, duplicate values are allowed

void printMultiset(const std::multiset<int>& ms)
{
    for (int value : ms)
        std::cout << value << ' ';

    std::cout << '\n';
}

int main()
{
    std::multiset<int> ms = {
        30, 10, 20, 20, 30, 30, 40
    };

    std::cout << "Initial multiset: ";
    printMultiset(ms);

    // ----------------------------------------------
    // insert()
    ms.insert(50);

    std::cout << "After insert(50): ";
    printMultiset(ms);

    // ----------------------------------------------
    // emplace()
    ms.emplace(60);

    std::cout << "After emplace(60): ";
    printMultiset(ms);

    // ----------------------------------------------
    // find()
    auto it = ms.find(30);

    if (it != ms.end())
        std::cout << "find(30): " << *it << '\n';

    // ----------------------------------------------
    // count()
    std::cout << "count(30): "
              << ms.count(30) << '\n';

    // ----------------------------------------------
    // contains()
    std::cout << "contains(20): "
              << ms.contains(20) << '\n';

    // ----------------------------------------------
    // lower_bound()
    it = ms.lower_bound(25);

    if (it != ms.end())
        std::cout << "lower_bound(25): "
                  << *it << '\n';

    // ----------------------------------------------
    // upper_bound()
    it = ms.upper_bound(30);

    if (it != ms.end())
        std::cout << "upper_bound(30): "
                  << *it << '\n';

    // ----------------------------------------------
    // equal_range()
    auto range = ms.equal_range(30);

    std::cout << "equal_range(30): ";

    for (auto i = range.first; i != range.second; ++i)
        std::cout << *i << ' ';

    std::cout << '\n';

    // ----------------------------------------------
    // erase one element using iterator
    it = ms.find(20);

    if (it != ms.end())
        ms.erase(it);

    std::cout << "After erase(iterator): ";
    printMultiset(ms);

    // ----------------------------------------------
    // erase all elements with key 30
    ms.erase(30);

    std::cout << "After erase(30): ";
    printMultiset(ms);

    // ----------------------------------------------
    // size()
    std::cout << "ms.size(): "
              << ms.size() << '\n';

    // ----------------------------------------------
    // empty()
    std::cout << "ms.empty(): "
              << ms.empty() << '\n';


    // max_size()
    std::cout << "ms.max_size(): "
              << ms.max_size() << '\n';

    // ----------------------------------------------
    // clear()
    ms.clear();

    std::cout << "After clear(): "
              << ms.empty() << '\n';


    return 0;
}



/*
//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


*/



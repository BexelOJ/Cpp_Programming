#include <iostream>
#include <map>
//A multimap allows duplicate keys

void printMultiMap(
    const std::multimap<int, std::string>& mm)
{
    for (const auto& [key, value] : mm)
        std::cout << key << " -> " << value << '\n';
}

int main()
{
    std::multimap<int, std::string> mm = {
        {1, "One"},
        {2, "Two"},
        {2, "TWO"},
        {3, "Three"}
    };

    printMultiMap(mm);

    // ----------------------------------------------
    // insert()
    mm.insert({ 2, "Second Two" });

    // ----------------------------------------------
    // emplace()
    mm.emplace(4, "Four");

    std::cout << "\nAfter insert/emplace:\n";
    printMultiMap(mm);

    // ----------------------------------------------
    // find()
    auto it = mm.find(2);

    if (it != mm.end())
        std::cout << "\nfind(2): "
        << it->second << '\n';

    // ----------------------------------------------
    // count()
    std::cout << "count(2): "
        << mm.count(2) << '\n';

    // ----------------------------------------------
    // contains()
    std::cout << "contains(2): "
        << mm.contains(2) << '\n';

    // ----------------------------------------------
    // lower_bound()
    it = mm.lower_bound(2);

    if (it != mm.end())
        std::cout << "lower_bound(2): "
        << it->first << '\n';

    // ----------------------------------------------
    // upper_bound()
    it = mm.upper_bound(2);

    if (it != mm.end())
        std::cout << "upper_bound(2): "
        << it->first << '\n';

    // ----------------------------------------------
    // equal_range()
    auto range = mm.equal_range(2);

    std::cout << "equal_range(2):\n";

    for (auto i = range.first; i != range.second; ++i)
        std::cout << i->first << " -> "
        << i->second << '\n';

    // ----------------------------------------------
    // erase(iterator)
    it = mm.find(2);

    if (it != mm.end())
        mm.erase(it);

    std::cout << "\nAfter erase(iterator):\n";
    printMultiMap(mm);

    // ----------------------------------------------
    // erase(key)
    mm.erase(2);

    std::cout << "After erase(2):\n";
    printMultiMap(mm);

    // ----------------------------------------------
    // size()
    std::cout << "mm.size(): "
        << mm.size() << '\n';

    // ----------------------------------------------
    // empty()
    std::cout << "mm.empty(): "
        << mm.empty() << '\n';

    // ----------------------------------------------
    // max_size()
    std::cout << "mm.max_size(): "
        << mm.max_size() << '\n';

    // ----------------------------------------------
    // clear()
    mm.clear();

    std::cout << "After clear(): "
        << mm.empty() << '\n';


    return 0;
}



/*
//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


*/



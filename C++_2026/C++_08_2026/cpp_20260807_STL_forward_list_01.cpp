#include <iostream>
#include <forward_list>

void printForwardList(const std::forward_list<int>& fl)
{
    for (int value : fl)
        std::cout << value << ' ';

    std::cout << '\n';
}

int main()
{
    // --------------------------------------------------
    // 1. Declaration and initialization
    // --------------------------------------------------

    std::forward_list<int> fl = { 10, 20, 30, 40, 50 };

    std::cout << "Initial forward_list: ";
    printForwardList(fl);


    // --------------------------------------------------
    // 2. Element access
    // --------------------------------------------------

    std::cout << "fl.front() : " << fl.front() << '\n';


    // --------------------------------------------------
    // 3. Modify front
    // --------------------------------------------------

    fl.front() = 100;

    std::cout << "After fl.front() = 100: ";
    printForwardList(fl);


    // --------------------------------------------------
    // 4. begin() / end()
    // --------------------------------------------------

    std::cout << "begin() -> end(): ";

    for (auto it = fl.begin(); it != fl.end(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // --------------------------------------------------
    // 5. cbegin() / cend()
    // --------------------------------------------------

    std::cout << "cbegin() -> cend(): ";

    for (auto it = fl.cbegin(); it != fl.cend(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // --------------------------------------------------
    // 6. Capacity
    // --------------------------------------------------

    std::cout << "fl.empty()    : " << fl.empty() << '\n';
    std::cout << "fl.max_size() : " << fl.max_size() << '\n';


    // --------------------------------------------------
    // 7. push_front()
    // --------------------------------------------------

    fl.push_front(5);

    std::cout << "After push_front(5): ";
    printForwardList(fl);


    // --------------------------------------------------
    // 8. emplace_front()
    // --------------------------------------------------

    fl.emplace_front(1);

    std::cout << "After emplace_front(1): ";
    printForwardList(fl);


    // --------------------------------------------------
    // 9. insert_after()
    // --------------------------------------------------

    auto it = fl.before_begin();

    std::advance(it, 2);

    fl.insert_after(it, 999);

    std::cout << "After insert_after(999): ";
    printForwardList(fl);


    // --------------------------------------------------
    // 10. emplace_after()
    // --------------------------------------------------

    fl.emplace_after(it, 888);

    std::cout << "After emplace_after(888): ";
    printForwardList(fl);


    // --------------------------------------------------
    // 11. erase_after()
    // --------------------------------------------------

    fl.erase_after(it);

    std::cout << "After erase_after(): ";
    printForwardList(fl);


    // --------------------------------------------------
    // 12. pop_front()
    // --------------------------------------------------

    fl.pop_front();

    std::cout << "After pop_front(): ";
    printForwardList(fl);


    // --------------------------------------------------
    // 13. resize()
    // --------------------------------------------------

    fl.resize(8);

    std::cout << "After resize(8): ";
    printForwardList(fl);


    // --------------------------------------------------
    // 14. assign()
    // --------------------------------------------------

    fl.assign(5, 100);

    std::cout << "After assign(5, 100): ";
    printForwardList(fl);


    // --------------------------------------------------
    // 15. remove()
    // --------------------------------------------------

    fl.assign({ 10, 20, 30, 20, 40 });

    fl.remove(20);

    std::cout << "After remove(20): ";
    printForwardList(fl);


    // --------------------------------------------------
    // 16. remove_if()
    // --------------------------------------------------

    fl.remove_if([](int value)
        {
            return value > 25;
        });

    std::cout << "After remove_if(value > 25): ";
    printForwardList(fl);


    // --------------------------------------------------
    // 17. reverse()
    // --------------------------------------------------

    fl.reverse();

    std::cout << "After reverse(): ";
    printForwardList(fl);


    // --------------------------------------------------
    // 18. sort()
    // --------------------------------------------------

    fl.assign({ 50, 10, 40, 20, 30 });

    fl.sort();

    std::cout << "After sort(): ";
    printForwardList(fl);


    // --------------------------------------------------
    // 19. unique()
    // --------------------------------------------------

    fl.assign({ 10, 10, 20, 20, 30 });

    fl.unique();

    std::cout << "After unique(): ";
    printForwardList(fl);


    // --------------------------------------------------
    // 20. swap()
    // --------------------------------------------------

    std::forward_list<int> fl2 = { 100, 200, 300 };

    fl.swap(fl2);

    std::cout << "After swap():\n";

    std::cout << "fl  : ";
    printForwardList(fl);

    std::cout << "fl2 : ";
    printForwardList(fl2);


    // --------------------------------------------------
    // 21. clear()
    // --------------------------------------------------

    fl.clear();

    std::cout << "After clear():\n";
    std::cout << "fl.empty() : " << fl.empty() << '\n';


    return 0;
}


/*
// --------------------------------------------------
std::list
    ↓
bidirectional iterator
    ↓
begin() ↔ end()
rbegin() ↔ rend()

std::forward_list
    ↓
forward iterator only
    ↓
begin() → end()

// --------------------------------------------------
Therefore forward_list does not have:

fl.back();       // ❌
fl.push_back();  // ❌
fl.pop_back();   // ❌
fl.rbegin();     // ❌
fl.rend();       // ❌
fl.size();       // ❌

// --------------------------------------------------


*/



#include <iostream>
#include <deque>

void printDeque(const std::deque<int>& d)
{
    for (int value : d)
        std::cout << value << ' ';

    std::cout << '\n';
}

int main()
{
    // ----------------------------------------------
    // 1. Declaration and initialization
    // ----------------------------------------------

    std::deque<int> d = { 10, 20, 30, 40, 50 };

    std::cout << "Initial deque: ";
    printDeque(d);


    // ----------------------------------------------
    // 2. Element access
    // ----------------------------------------------

    std::cout << "d[0]      : " << d[0] << '\n';
    std::cout << "d.at(1)   : " << d.at(1) << '\n';
    std::cout << "d.front() : " << d.front() << '\n';
    std::cout << "d.back()  : " << d.back() << "\n\n";


    // ----------------------------------------------
    // 3. Modify using operator[]
    // ----------------------------------------------

    d[2] = 100;

    std::cout << "After d[2] = 100: ";
    printDeque(d);


    // ----------------------------------------------
    // 4. begin() / end()
    // ----------------------------------------------

    std::cout << "\nbegin() -> end(): ";

    for (auto it = d.begin(); it != d.end(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // ----------------------------------------------
    // 5. rbegin() / rend()
    // ----------------------------------------------

    std::cout << "rbegin() -> rend(): ";

    for (auto it = d.rbegin(); it != d.rend(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // ----------------------------------------------
    // 6. cbegin() / cend()
    // ----------------------------------------------

    std::cout << "cbegin() -> cend(): ";

    for (auto it = d.cbegin(); it != d.cend(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // ----------------------------------------------
    // 7. crbegin() / crend()
    // ----------------------------------------------

    std::cout << "crbegin() -> crend(): ";

    for (auto it = d.crbegin(); it != d.crend(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // ----------------------------------------------
    // 8. Capacity functions
    // ----------------------------------------------

    std::cout << "\nd.empty()    : " << d.empty() << '\n';
    std::cout << "d.size()     : " << d.size() << '\n';
    std::cout << "d.max_size() : " << d.max_size() << "\n\n";


    // ----------------------------------------------
    // 9. push_back()
    // ----------------------------------------------

    d.push_back(60);

    std::cout << "After push_back(60): ";
    printDeque(d);


    // ----------------------------------------------
    // 10. push_front()
    // ----------------------------------------------

    d.push_front(5);

    std::cout << "After push_front(5): ";
    printDeque(d);


    // ----------------------------------------------
    // 11. emplace_back()
    // ----------------------------------------------

    d.emplace_back(70);

    std::cout << "After emplace_back(70): ";
    printDeque(d);


    // ----------------------------------------------
    // 12. emplace_front()
    // ----------------------------------------------

    d.emplace_front(1);

    std::cout << "After emplace_front(1): ";
    printDeque(d);


    // ----------------------------------------------
    // 13. insert()
    // ----------------------------------------------

    d.insert(d.begin() + 2, 999);

    std::cout << "After insert(999 at index 2): ";
    printDeque(d);


    // ----------------------------------------------
    // 14. emplace()
    // ----------------------------------------------

    d.emplace(d.begin() + 3, 888);

    std::cout << "After emplace(888 at index 3): ";
    printDeque(d);


    // ----------------------------------------------
    // 15. erase()
    // ----------------------------------------------

    d.erase(d.begin() + 2);

    std::cout << "After erase(index 2): ";
    printDeque(d);


    // ----------------------------------------------
    // 16. pop_back()
    // ----------------------------------------------

    d.pop_back();

    std::cout << "After pop_back(): ";
    printDeque(d);


    // ----------------------------------------------
    // 17. pop_front()
    // ----------------------------------------------

    d.pop_front();

    std::cout << "After pop_front(): ";
    printDeque(d);


    // ----------------------------------------------
    // 18. resize()
    // ----------------------------------------------

    d.resize(10);

    std::cout << "After resize(10): ";
    printDeque(d);


    // ----------------------------------------------
    // 19. resize() with a value
    // ----------------------------------------------

    d.resize(12, 500);

    std::cout << "After resize(12, 500): ";
    printDeque(d);


    // ----------------------------------------------
    // 20. assign()
    // ----------------------------------------------

    d.assign(5, 1000);

    std::cout << "After assign(5, 1000): ";
    printDeque(d);


    // ----------------------------------------------
    // 21. assign() using a range
    // ----------------------------------------------

    int arr[] = { 1, 2, 3, 4 };

    d.assign(std::begin(arr), std::end(arr));

    std::cout << "After assign(range): ";
    printDeque(d);


    // ----------------------------------------------
    // 22. swap()
    // ----------------------------------------------

    std::deque<int> d2 = { 100, 200, 300 };

    std::cout << "\nBefore swap:\n";

    std::cout << "d  : ";
    printDeque(d);

    std::cout << "d2 : ";
    printDeque(d2);

    d.swap(d2);

    std::cout << "\nAfter swap:\n";

    std::cout << "d  : ";
    printDeque(d);

    std::cout << "d2 : ";
    printDeque(d2);


    // ----------------------------------------------
    // 23. clear()
    // ----------------------------------------------

    d.clear();

    std::cout << "\nAfter clear():\n";

    std::cout << "d.size()  : " << d.size() << '\n';
    std::cout << "d.empty() : " << d.empty() << "\n\n";


    return 0;
}



/*
//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


*/



#include <iostream>
#include <vector>

void printVector(const std::vector<int>& v)
{
    for (int value : v)
        std::cout << value << ' ';

    std::cout << '\n';
}

int main() {
    // ----------------------------------------------
    // 1. Declaration and initialization
    // ----------------------------------------------

    std::vector<int> v = { 10, 20, 30, 40, 50 };

    std::cout << "Initial vector: ";
    printVector(v);

    // Output: Initial vector: 10 20 30 40 50
    
    // ----------------------------------------------
    // 2. Element access
    // ----------------------------------------------

    std::cout << "v[0]      : " << v[0] << '\n';
    std::cout << "v.at(1)   : " << v.at(1) << '\n';
    std::cout << "v.front() : " << v.front() << '\n';
    std::cout << "v.back()  : " << v.back() << "\n\n";


    // data()
    int* ptr = v.data();

    std::cout << "v.data()[0] : " << v.data()[0] << '\n';
    std::cout << "v.data()[0] : " << ptr[0] << "\n\n";

    // ----------------------------------------------
    // 3. Modify using operator[]
    // ----------------------------------------------

    v[2] = 100;

    std::cout << "After v[2] = 100: ";
    printVector(v);


    // ----------------------------------------------
    // 4. Iterators
    // ----------------------------------------------

    std::cout << "\nbegin() -> end(): ";

    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // Reverse iterators
    std::cout << "rbegin() -> rend(): ";

    for (auto it = v.rbegin(); it != v.rend(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // Const iterators
    std::cout << "cbegin() -> cend(): ";

    for (auto it = v.cbegin(); it != v.cend(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // Const reverse iterators
    std::cout << "crbegin() -> crend(): ";

    for (auto it = v.crbegin(); it != v.crend(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // ----------------------------------------------
    // 5. Capacity functions
    // ----------------------------------------------

    std::cout << "\nv.empty()    : " << v.empty() << "\n";
    std::cout << "v.size()     : " << v.size() << "\n";
    std::cout << "v.max_size() : " << v.max_size() << "\n";
    std::cout << "v.capacity() : " << v.capacity() << "\n\n";


    // ----------------------------------------------
    // 6. reserve()
    // ----------------------------------------------

    v.reserve(20);

    std::cout << "\nAfter reserve(20):\n";
    std::cout << "v.size()     : " << v.size() << '\n';
    std::cout << "v.capacity() : " << v.capacity() << "\n\n";


    // ----------------------------------------------
    // 7. push_back()
    // ----------------------------------------------

    v.push_back(60);

    std::cout << "\nAfter push_back(60): ";
    printVector(v);


    // ----------------------------------------------
    // 8. emplace_back()
    // ----------------------------------------------

    v.emplace_back(70);

    std::cout << "\nAfter emplace_back(70): ";
    printVector(v);


    // ----------------------------------------------
    // 9. insert()
    // ----------------------------------------------

    v.insert(v.begin() + 2, 999);

    std::cout << "\nAfter insert(999 at index 2): ";
    printVector(v);


    // ----------------------------------------------
    // 10. emplace()
    // ----------------------------------------------

    v.emplace(v.begin() + 3, 888);

    std::cout << "\nAfter emplace(888 at index 3): ";
    printVector(v);


    // ----------------------------------------------
    // 11. erase()
    // ----------------------------------------------

    v.erase(v.begin() + 2);

    std::cout << "\nAfter erase(index 2): ";
    printVector(v);


    // ----------------------------------------------
    // 12. pop_back()
    // ----------------------------------------------

    v.pop_back();

    std::cout << "\nAfter pop_back(): ";
    printVector(v);


    // ----------------------------------------------
    // 13. resize()
    // ----------------------------------------------

    v.resize(10);

    std::cout << "\nAfter resize(10): ";
    printVector(v);

    std::cout << "size     : " << v.size() << '\n';
    std::cout << "capacity : " << v.capacity() << '\n';


    // ----------------------------------------------
    // 14. resize() with a value
    // ----------------------------------------------

    v.resize(12, 500);

    std::cout << "\nAfter resize(12, 500): ";
    printVector(v);


    // ----------------------------------------------
    // 15. shrink_to_fit()
    // ----------------------------------------------

    v.shrink_to_fit();

    std::cout << "\nAfter shrink_to_fit():\n";
    std::cout << "size     : " << v.size() << '\n';
    std::cout << "capacity : " << v.capacity() << "\n\n";


    // ----------------------------------------------
    // 16. assign()
    // ----------------------------------------------

    v.assign(5, 1000);

    std::cout << "\nAfter assign(5, 1000): ";
    printVector(v);


    // ----------------------------------------------
    // 17. assign() using a range
    // ----------------------------------------------

    int arr[] = { 1, 2, 3, 4 };

    v.assign(std::begin(arr), std::end(arr));

    std::cout << "\nAfter assign(range): ";
    printVector(v);


    // ----------------------------------------------
    // 18. swap()
    // ----------------------------------------------

    std::vector<int> v2 = { 100, 200, 300 };

    std::cout << "\nBefore swap:\n";

    std::cout << "v  : ";
    printVector(v);

    std::cout << "v2 : ";
    printVector(v2);

    v.swap(v2);

    std::cout << "After swap:\n";

    std::cout << "v  : ";
    printVector(v);

    std::cout << "v2 : ";
    printVector(v2);


    // ----------------------------------------------
    // 19. clear()
    // ----------------------------------------------

    v.clear();

    std::cout << "\nAfter clear():\n";
    std::cout << "v.size()     : " << v.size() << '\n';
    std::cout << "v.capacity() : " << v.capacity() << '\n';
    std::cout << "v.empty()    : " << v.empty() << "\n\n";
    return 0;
}

/*
// member functions common to array class:
Member_function	  Description
    // ----------------------------------------------

//------------------------------------------------
1.) at()	        Accesses an element with bounds checking
2.) operator[]	  Accesses an element without bounds checking

3.) front()	     Returns the first element
4.) back()	     Returns the last element

5.) data()	     Returns a pointer to the first element

//-----------------------------------
6.) begin()	     Returns an iterator to the first element
7.) end()	     Returns an iterator past the last element

8.) rbegin()	  Returns a reverse iterator to the last element
9.) rend()	     Returns a reverse iterator past the first element

10.) cbegin()	  Returns a const iterator to the first element
11.) cend()	     Returns a const iterator past the last element

12.) crbegin()	  Returns a const reverse iterator to the last element
13.) crend()	  Returns a const reverse iterator past the first element

//-----------------------------------
14.) empty()	  Checks whether the container is empty

15.) size()	     Returns the number of elements
16.) max_size()  Returns the maximum number of elements supported

17.) swap()	     Exchanges the contents of two containers

//-----------------------------------
// member functions not common to array class:

18.) assign()

19.) capacity()	Returns the number of elements the vector can hold without reallocation

20.) reserve()	   Requests allocation of storage for at least a specified number of elements

21.) shrink_to_fit()	Requests reduction of unused allocated memory

//-----------------------------------
22.) push_back()	Adds an element to the end
23.) pop_back()	Removes the last element

//-----------------------------------
24.) insert()	   Inserts elements at a specified position
25.) erase()	   Removes elements from a specified position or range
26.) clear()	   Removes all elements
27.) resize()	   Changes the number of elements

//-----------------------------------
28.) emplace_back()	Constructs and adds an element at the end
29.) emplace()	   Constructs and inserts an element at a specified position

*/



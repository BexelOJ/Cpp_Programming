#include <iostream>
#include <array>

void printArray(const std::array<int, 5>& arr)
{
    for (int value : arr)
        std::cout << value << ' ';

    std::cout << '\n';
}

int main() {
    // ----------------------------------------------
    // 1. Declaration and initialization
    // ----------------------------------------------

    std::array<int, 5> arr = { 10, 20, 30, 40, 50 };

    std::cout << "Initial array: ";
    printArray(arr);


    // ----------------------------------------------
    // 2. Element access
    // ----------------------------------------------

    std::cout << "\narr[0]      : " << arr[0] << '\n';
    std::cout << "arr.at(1)   : " << arr.at(1) << '\n';
    std::cout << "arr.front() : " << arr.front() << '\n';
    std::cout << "arr.back()  : " << arr.back() << "\n\n";


    // ----------------------------------------------
    // 3. data()
    // ----------------------------------------------

    int* ptr = arr.data();

    std::cout << "arr.data()[0] : " << arr.data()[0] << '\n';
    std::cout << "arr.data()[0] : " << ptr[0] << "\n\n";

    // ----------------------------------------------
    // 4. Modify using operator[]
    // ----------------------------------------------

    arr[2] = 100;

    std::cout << "After arr[2] = 100: ";
    printArray(arr);


    // ----------------------------------------------
    // 5. begin() / end()
    // ----------------------------------------------

    std::cout << "begin() -> end(): ";

    for (auto it = arr.begin(); it != arr.end(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // ----------------------------------------------
    // 6. rbegin() / rend()
    // ----------------------------------------------

    std::cout << "rbegin() -> rend(): ";

    for (auto it = arr.rbegin(); it != arr.rend(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // ----------------------------------------------
    // 7. cbegin() / cend()
    // ----------------------------------------------

    std::cout << "cbegin() -> cend(): ";

    for (auto it = arr.cbegin(); it != arr.cend(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // ----------------------------------------------
    // 8. crbegin() / crend()
    // ----------------------------------------------

    std::cout << "crbegin() -> crend(): ";

    for (auto it = arr.crbegin(); it != arr.crend(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';


    // ----------------------------------------------
    // 9. Capacity / size functions
    // ----------------------------------------------

    std::cout << "arr.empty()    : " << arr.empty() << '\n';
    std::cout << "arr.size()     : " << arr.size() << '\n';
    std::cout << "arr.max_size() : " << arr.max_size() << '\n';


    // ----------------------------------------------
    // 10. fill()
    // ----------------------------------------------

    arr.fill(500);

    std::cout << "After arr.fill(500): ";
    printArray(arr);


    // ----------------------------------------------
    // 11. swap()
    // ----------------------------------------------

    std::array<int, 5> arr_2 = { 1, 2, 3, 4, 5 };

    std::cout << "\nBefore swap:\n";

    std::cout << "arr   : ";
    printArray(arr);

    std::cout << "arr_2 : ";
    printArray(arr_2);

    arr.swap(arr_2);

    std::cout << "After swap:\n";

    std::cout << "arr   : ";
    printArray(arr);

    std::cout << "arr_2 : ";
    printArray(arr_2);


    // ----------------------------------------------
    // 12. std::get()
    // ----------------------------------------------

    std::cout << "\nstd::get<0>(arr) : "
        << std::get<0>(arr) << '\n';

    std::cout << "std::get<4>(arr) : "
        << std::get<4>(arr) << '\n';


    // ----------------------------------------------
    // 13. std::tuple_size
    // -----------------------------------------------

    std::cout << "tuple_size : "
        << std::tuple_size<decltype(arr)>::value
        << '\n';


    // ----------------------------------------------
    // 14. std::tuple_element
    // ----------------------------------------------

    std::cout << "tuple_element<0> type exists for std::array\n";


    // ----------------------------------------------
    // 15. No clear()
    // ----------------------------------------------

    // arr.clear();       // ❌ std::array has no clear()

    // No push_back()
    // arr.push_back(10); // ❌

    // No pop_back()
    // arr.pop_back();    // ❌

    // No resize()
    // arr.resize(10);    // ❌

    return 0;
}



/*
//---------------------------------------------------

1.) operator[]	 Access element
2.) at()	       Access element with bounds checking

3.) front()	    First element
4.) back()	    Last element

5.) data()	    Pointer to underlying array

//---------------------------------------------------

6.) begin()	    Iterator to first element
7.) end()	    Iterator past last element

8.) rbegin()	 Reverse iterator to last element
9.) rend()	    Reverse iterator past first

10.) cbegin()	 Const iterator beginning
11.) cend()	    Const iterator ending

12.) crbegin()	 Const reverse beginning, crbegin() means const reverse begin.
13.) crend()	 Const reverse ending

//---------------------------------------------------

14.) empty()	 Check whether array is empty

15.) size()	    Number of elements
16.) max_size() Maximum number of elements

17.) fill()	    Fill all elements with a value
18.) swap()	    Swap two arrays

//---------------------------------------------------

r = reverse
c = const, read-only

rbegin  = reverse + begin
cbegin  = const + begin
crbegin = const + reverse + begin

rend()   → reverse end
cend()   → const end
crend()  → const reverse end

//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------


//---------------------------------------------------



*/



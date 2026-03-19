#include <iostream>
#include <deque>
#include <cstddef> 

int main() {
    std::deque<int> my_deque;
    
    std::deque<int>* dqPtr = new std::deque<int>();

    my_deque.push_back(2);
    my_deque.push_front(1);
    my_deque.push_front(3);
    my_deque.push_front(4);
    my_deque.push_back(5);

    //std::cout << my_deque[0] << std::endl;

    // Range-based for loop
    for (auto i : my_deque) {
        std::cout << i << " ";
    }
    std::cout<<std::endl;

    // Indexed loop (explicit positions):
    for (size_t i = 0; i < my_deque.size(); ++i) {
        std::cout << my_deque[i] << " ";
    }
    std::cout << std::endl;

    // Iterator loop (STL classic):
    for (auto it = my_deque.begin(); it != my_deque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << my_deque.front() << std::endl;
    std::cout << my_deque.back() << std::endl;

    std::cout << my_deque.size() << std::endl;
    
    std::cout << my_deque.empty() << std::endl;
    my_deque.clear(); // << std::endl;
    std::cout << my_deque.empty() << std::endl;
    return 0;
}


/*
Core Element Operations:

1.) push_back()	Adds element to back 
​
2.) push_front()	Adds element to front 
​
3.) pop_back()	Removes element from back 
​
4.) pop_front()	Removes element from front 
​
5.) front()	Accesses first element 
​
6.) back()	Accesses last element 
​

Container Management:

1.) size()	Returns number of elements
​
2.) empty()	Checks if deque is empty
​
3.) clear()	Removes all elements
​
4.) at(index)	Accesses element with bounds checking
​
5.) operator[](index)	Accesses element (no bounds checking)
​
*/


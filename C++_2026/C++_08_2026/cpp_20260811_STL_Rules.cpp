#include <iostream>

int main() {
    std::cout << "Some good notes of STL containers and its features " << std::endl;
    return 0;
}


/*
// --------------------------------------------------
The main three styles of for loops to remember:

1. Index-based
   for (size_t i = 0; i < arr.size(); ++i)

2. Iterator-based
   for (auto it = arr.begin(); it != arr.end(); ++it)

3. Range-based
   for (auto value : arr)

// --------------------------------------------------
is possible:

for (auto value : arr)        // copy
for (auto& value : arr)       // reference, can modify
for (const auto& value : arr) // reference, cannot modify

// --------------------------------------------------
Member_function	Returns

begin()	         iterator
end()	            iterator

rbegin()	         reverse iterator
rend()	         reverse iterator

cbegin()	         const iterator
cend()	         const iterator

crbegin()	      const reverse iterator
crend()	         const reverse iterator

begin(), end(), etc. are member functions that return iterator objects. They themselves are not iterators.

// --------------------------------------------------
for std::vector

Function	       What it uses

at()	          index
operator[]	    index

erase()	       iterator
insert()	       iterator

// --------------------------------------------------
Why iterator for insert() / erase()?

Because these operations are designed to work with positions in a container, and STL uses iterators as the general way to represent positions.

And this distinction becomes even more important when you move from 
vector to containers that don't have indexes, such as std::list.

// --------------------------------------------------

Iterators are the general STL way of representing positions

// --------------------------------------------------

std::vector
    ↓
contiguous memory
    ↓
fast random access
    ↓
efficient back insertion
    ↓
front insertion is expensive


std::deque
    ↓
non-contiguous memory
    ↓
fast random access
    ↓
efficient front insertion
    ↓
efficient back insertion

// --------------------------------------------------

std::deque
    ↓
actual container
    ↓
exposes its elements
    ↓
random access available


std::queue
    ↓
container adaptor
    ↓
restricts the interface
    ↓
FIFO operations only

// --------------------------------------------------
std::list
Notice the important difference:

l[2];        // ❌ operator not available in list 
l.at(2);     // ❌ at not available in list

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

Therefore forward_list does not have:

fl.back();       // ❌
fl.push_back();  // ❌
fl.pop_back();   // ❌
fl.rbegin();     // ❌
fl.rend();       // ❌
fl.size();       // ❌

// --------------------------------------------------
[] / at()
    array
    vector
    deque
    string

push_front()
    deque
    list
    forward_list

push_back()
    vector
    deque
    list
    string

random access
    array
    vector
    deque
    string

sorted automatically
    set
    multiset
    map
    multimap

hash based
    unordered_set
    unordered_multiset
    unordered_map
    unordered_multimap

LIFO
    stack

FIFO
    queue

highest-priority-first
    priority_queue

// --------------------------------------------------


// --------------------------------------------------


// --------------------------------------------------


// --------------------------------------------------


// --------------------------------------------------



*/
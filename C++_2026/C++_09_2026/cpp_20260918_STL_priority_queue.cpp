#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <functional>

using namespace std;

//---------------------------------------------------
// Display priority_queue
//---------------------------------------------------
void display(priority_queue<int> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << "\n";
}

//---------------------------------------------------
// main
//---------------------------------------------------
int main()
{
    //---------------------------------------------------
    // 1. Constructors
    //---------------------------------------------------

    priority_queue<int> pq1;

    vector<int> values = { 40, 10, 30, 50, 20 };

    priority_queue<int> pq2(values.begin(), values.end());

    priority_queue<int> pq3(pq2);

    priority_queue<int> pq4;

    pq4 = pq2;


    //---------------------------------------------------
    // 2. push()
    //---------------------------------------------------

    priority_queue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    cout << "After push() : ";
    display(pq);


    //---------------------------------------------------
    // 3. top()
    //---------------------------------------------------

    cout << "\n";

    cout << "top()        : " << pq.top() << "\n";


    //---------------------------------------------------
    // 4. size()
    //---------------------------------------------------

    cout << "size()       : " << pq.size() << "\n";


    //---------------------------------------------------
    // 5. empty()
    //---------------------------------------------------

    cout << "empty()      : " << boolalpha << pq.empty() << "\n";


    //---------------------------------------------------
    // 6. emplace()
    //---------------------------------------------------

    pq.emplace(60);

    cout << "\nAfter emplace(60) : ";
    display(pq);


    //---------------------------------------------------
    // 7. pop()
    //---------------------------------------------------

    pq.pop();

    cout << "\nAfter pop() : ";
    display(pq);


    //---------------------------------------------------
    // 8. Maximum priority_queue
    //---------------------------------------------------

    priority_queue<int> maxPQ;

    maxPQ.push(25);
    maxPQ.push(10);
    maxPQ.push(50);
    maxPQ.push(5);
    maxPQ.push(40);

    cout << "\nMax priority_queue : ";

    while (!maxPQ.empty())
    {
        cout << maxPQ.top() << " ";
        maxPQ.pop();
    }

    cout << "\n";


    //---------------------------------------------------
    // 9. Minimum priority_queue
    //---------------------------------------------------

    priority_queue<int, vector<int>, greater<int>> minPQ;

    minPQ.push(25);
    minPQ.push(10);
    minPQ.push(50);
    minPQ.push(5);
    minPQ.push(40);

    cout << "\nMin priority_queue : ";

    while (!minPQ.empty())
    {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }

    cout << "\n";


    //---------------------------------------------------
    // 10. swap()
    //---------------------------------------------------

    priority_queue<int> pqA;
    priority_queue<int> pqB;

    pqA.push(10);
    pqA.push(30);
    pqA.push(20);

    pqB.push(100);
    pqB.push(300);

    cout << "\nBefore swap()\n";

    cout << "pqA : ";
    display(pqA);

    cout << "pqB : ";
    display(pqB);

    pqA.swap(pqB);

    cout << "\nAfter swap()\n";

    cout << "pqA : ";
    display(pqA);

    cout << "pqB : ";
    display(pqB);


    //---------------------------------------------------
    // 11. std::swap()
    //---------------------------------------------------

    swap(pqA, pqB);

    cout << "\nAfter std::swap()\n";

    cout << "pqA : ";
    display(pqA);

    cout << "pqB : ";
    display(pqB);


    //---------------------------------------------------
    // 12. Using deque as underlying container
    //---------------------------------------------------

    priority_queue<int, deque<int>> dequePQ;

    dequePQ.push(100);
    dequePQ.push(50);
    dequePQ.push(200);

    cout << "\nPriority queue using deque : ";

    while (!dequePQ.empty())
    {
        cout << dequePQ.top() << " ";
        dequePQ.pop();
    }

    cout << "\n";


    //---------------------------------------------------
    // 13. Clear priority_queue
    //---------------------------------------------------

    priority_queue<int> clearPQ;

    clearPQ.push(10);
    clearPQ.push(20);
    clearPQ.push(30);

    while (!clearPQ.empty())
    {
        clearPQ.pop();
    }

    cout << "\nAfter clearing : ";
    cout << "empty() = " << clearPQ.empty() << "\n";


    //---------------------------------------------------
    // 14. Priority behavior
    //---------------------------------------------------

    cout << "\nPriority queue behavior\n";

    priority_queue<int> priority;

    priority.push(10);
    priority.push(50);
    priority.push(20);
    priority.push(40);
    priority.push(30);

    cout << "Insertion order : 10 50 20 40 30\n";
    cout << "Removal order   : ";

    while (!priority.empty())
    {
        cout << priority.top() << " ";
        priority.pop();
    }

    cout << "\n";


    //---------------------------------------------------
    // 15. Function summary
    //---------------------------------------------------

    cout << "\n";
    cout << "priority_queue functions\n";
    cout << "------------------------\n";
    cout << "empty()\n";
    cout << "size()\n";
    cout << "top()\n";
    cout << "push()\n";
    cout << "emplace()\n";
    cout << "pop()\n";
    cout << "swap()\n";


    return 0;
}



/*

compile with

g++ -std=c++20 cpp_20260918_STL_priorityQueue.cpp

//-------------------------------------------------------
// Important notes
//-------------------------------------------------------

    
priority_queue is a container adaptor.

Default behavior:
    Largest element has highest priority.

Example:
    push:  10 50 20 40 30
    pop:   50 40 30 20 10

Minimum priority queue:
    priority_queue<int, vector<int>, greater<int>>

Example:
    push:  10 50 20 40 30
    pop:   10 20 30 40 50

Important functions:

    empty()
    size()
    top()
    push()
    emplace()
    pop()
    swap()

No iterators:
    begin()
    end()
    rbegin()
    rend()

No direct element access:
    operator[]
    at()

No:
   insert()
   erase()
   clear()

To clear:
   while (!pq.empty())
   pq.pop();


Underlying container:
   vector<T> is the default.

Another possible container:
   deque<T>

The underlying container must support:
   front()
   push_back()
   pop_back()


Important:
   top() gives access to the highest-priority element,
   but does NOT remove it.
   
   pop() removes the highest-priority element,
   but does NOT return it.

 Therefore:

    cout << pq.top();
    pq.pop();
    
//-------------------------------------------------------
Output:
//-------------------------------------------------------

After push() : 50 40 30 20 10

top()        : 50
size()       : 5
empty()      : false

After emplace(60) : 60 50 40 30 20 10

After pop() : 50 40 30 20 10

Max priority_queue : 50 40 25 10 5

Min priority_queue : 5 10 25 40 50

Before swap()
pqA : 30 20 10
pqB : 300 100

After swap()
pqA : 300 100
pqB : 30 20 10

After std::swap()
pqA : 30 20 10
pqB : 300 100

Priority queue using deque : 200 100 50

After clearing : empty() = true

Priority queue behavior
Insertion order : 10 50 20 40 30
Removal order   : 50 40 30 20 10

priority_queue functions
------------------------
empty()
size()
top()
push()
emplace()
pop()
swap()



*/

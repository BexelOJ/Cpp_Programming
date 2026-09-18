#include <iostream>
#include <queue>
#include <string>

using namespace std;

//---------------------------------------------------
// Helper function
//---------------------------------------------------
void printQueue(queue<int> q, const string& name)
{
    cout << name << " : ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << "\n";
}

//---------------------------------------------------
// main
//---------------------------------------------------
int main()
{
    //-----------------------------------------------
    // 1. Constructors
    //-----------------------------------------------

    queue<int> q1;

    queue<int> q2;

    q2.push(10);
    q2.push(20);
    q2.push(30);

    queue<int> q3(q2);


    printQueue(q1, "q1");
    printQueue(q2, "q2");
    printQueue(q3, "q3");


    //-----------------------------------------------
    // 2. Assignment
    //-----------------------------------------------

    queue<int> q4;

    q4 = q2;

    printQueue(q4, "q4");


    //-----------------------------------------------
    // 3. empty()
    //-----------------------------------------------

    cout << "\nCapacity\n";

    cout << "empty() : " << q4.empty() << "\n";


    //-----------------------------------------------
    // 4. size()
    //-----------------------------------------------

    cout << "size()  : " << q4.size() << "\n";


    //-----------------------------------------------
    // 5. front()
    //-----------------------------------------------

    cout << "\nElement Access\n";

    cout << "front() : " << q4.front() << "\n";


    //-----------------------------------------------
    // 6. back()
    //-----------------------------------------------

    cout << "back()  : " << q4.back() << "\n";


    //-----------------------------------------------
    // 7. push()
    //-----------------------------------------------

    q4.push(40);

    printQueue(q4, "After push(40)");


    //-----------------------------------------------
    // 8. emplace()
    //-----------------------------------------------

    q4.emplace(50);

    printQueue(q4, "After emplace(50)");


    //-----------------------------------------------
    // 9. pop()
    //-----------------------------------------------

    q4.pop();

    printQueue(q4, "After pop()");


    //-----------------------------------------------
    // 10. front() and back() modification
    //-----------------------------------------------

    q4.front() = 100;

    q4.back() = 500;

    printQueue(q4, "After modifying front/back");


    //-----------------------------------------------
    // 11. swap()
    //-----------------------------------------------

    queue<int> q5;

    q5.push(1);
    q5.push(2);
    q5.push(3);

    cout << "\nBefore swap()\n";

    printQueue(q4, "q4");
    printQueue(q5, "q5");

    q4.swap(q5);

    cout << "After swap()\n";

    printQueue(q4, "q4");
    printQueue(q5, "q5");


    //-----------------------------------------------
    // 12. Non-member swap()
    //-----------------------------------------------

    swap(q4, q5);

    cout << "\nAfter std::swap()\n";

    printQueue(q4, "q4");
    printQueue(q5, "q5");


    //-----------------------------------------------
    // 13. Comparison
    //-----------------------------------------------

    queue<int> q6;

    queue<int> q7;

    queue<int> q8;

    q6.push(10);
    q6.push(20);
    q6.push(30);

    q7.push(10);
    q7.push(20);
    q7.push(30);

    q8.push(10);
    q8.push(20);
    q8.push(40);

    cout << "\nComparison\n";

    cout << "q6 == q7 : " << (q6 == q7) << "\n";
    cout << "q6 != q8 : " << (q6 != q8) << "\n";
    cout << "q6 < q8  : " << (q6 < q8) << "\n";


    //-----------------------------------------------
    // 14. FIFO demonstration
    //-----------------------------------------------

    queue<int> fifo;

    fifo.push(10);
    fifo.push(20);
    fifo.push(30);
    fifo.push(40);

    cout << "\nFIFO Order\n";

    while (!fifo.empty())
    {
        cout << fifo.front() << " ";

        fifo.pop();
    }

    cout << "\n";


    //-----------------------------------------------
    // 15. Clearing a queue
    //-----------------------------------------------

    queue<int> clearQueue;

    clearQueue.push(10);
    clearQueue.push(20);
    clearQueue.push(30);

    while (!clearQueue.empty())
    {
        clearQueue.pop();
    }

    cout << "\nAfter clearing queue\n";

    cout << "empty() : " << clearQueue.empty() << "\n";
    cout << "size()  : " << clearQueue.size() << "\n";


    //-----------------------------------------------
    // End
    //-----------------------------------------------

    return 0;
}



/*
//---------------------------------------------------
For queue, we'll cover the functions that belong 
specifically to the container adaptor. 

Unlike vector/array, queue does not provide 
iterators, begin(), end(), at(), or [].

//---------------------------------------------------
std::queue API covered:

Category	           Functions

Construction	     queue()
Copy	              queue(const queue&)
Assignment	        operator=
Capacity	           empty(), size()
Element access	     front(), back()
Insertion	        push()
Construction in place	emplace()
Removal	           pop()
Exchange	           swap()
Non-member	        std::swap()
Comparison	        ==, !=, <

One important point: 
queue is a container adaptor, 
not a normal sequence container. 
Its default underlying container is std::deque, 
which is why functions such as begin(), end(), 
insert(), and erase() are intentionally unavailable.


//---------------------------------------------------
 Output:
//---------------------------------------------------

q1 :
q2 : 10 20 30
q3 : 10 20 30
q4 : 10 20 30

Capacity
empty() : 0
size()  : 3

Element Access
front() : 10
back()  : 30
After push(40) : 10 20 30 40
After emplace(50) : 10 20 30 40 50
After pop() : 20 30 40 50
After modifying front/back : 100 30 40 500

Before swap()
q4 : 100 30 40 500
q5 : 1 2 3
After swap()
q4 : 1 2 3
q5 : 100 30 40 500

After std::swap()
q4 : 100 30 40 500
q5 : 1 2 3

Comparison
q6 == q7 : 1
q6 != q8 : 1
q6 < q8  : 1

FIFO Order
10 20 30 40

After clearing queue
empty() : 1
size()  : 0


//---------------------------------------------------
*/





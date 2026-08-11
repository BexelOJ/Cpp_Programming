#include <iostream>
#include <queue>

void printPriorityQueue(std::priority_queue<int> pq)
{
    while (!pq.empty())
    {
        std::cout << pq.top() << ' ';
        pq.pop();
    }

    std::cout << '\n';
}

int main()
{
    // ----------------------------------------------
    // 1. Declaration
    // ----------------------------------------------

    std::priority_queue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    std::cout << "Initial priority_queue: ";
    printPriorityQueue(pq);


    // ----------------------------------------------
    // 2. top()
    // ----------------------------------------------

    std::cout << "pq.top() : " << pq.top() << '\n';


    // ----------------------------------------------
    // 3. push()
    // ----------------------------------------------

    pq.push(100);

    std::cout << "After push(100): ";
    printPriorityQueue(pq);


    // ----------------------------------------------
    // 4. emplace()
    // ----------------------------------------------

    pq.emplace(200);

    std::cout << "After emplace(200): ";
    printPriorityQueue(pq);


    // ----------------------------------------------
    // 5. pop()
    // ----------------------------------------------

    pq.pop();

    std::cout << "After pop(): ";
    printPriorityQueue(pq);


    // ----------------------------------------------
    // 6. size()
    // ----------------------------------------------

    std::cout << "pq.size() : " << pq.size() << '\n';


    // ----------------------------------------------
    // 7. empty()
    // ----------------------------------------------

    std::cout << "pq.empty() : " << pq.empty() << '\n';


    // ----------------------------------------------
    // 8. max_size()
    // ----------------------------------------------

    std::cout << "pq.max_size() : " << pq.max_size() << '\n';


    // ----------------------------------------------
    // 9. swap()
    // ----------------------------------------------

    std::priority_queue<int> pq2;

    pq2.push(1000);
    pq2.push(2000);

    pq.swap(pq2);

    std::cout << "After swap():\n";

    std::cout << "pq  : ";
    printPriorityQueue(pq);

    std::cout << "pq2 : ";
    printPriorityQueue(pq2);


    return 0;
}



/*
//---------------------------------------------------
Default behavior: largest element has highest priority.

//---------------------------------------------------
You can also create a min-heap:

std::priority_queue<
    int,
    std::vector<int>,
    std::greater<int>
> pq;

//---------------------------------------------------


//---------------------------------------------------



*/



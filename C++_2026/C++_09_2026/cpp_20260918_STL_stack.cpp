#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <string>

using namespace std;

//---------------------------------------------------
// main
//---------------------------------------------------
int main()
{
    //---------------------------------------------------
    // 1. Constructors
    //---------------------------------------------------

    stack<int> s1;

    stack<int> s2;

    s2.push(10);
    s2.push(20);
    s2.push(30);

    stack<int> s3(s2);

    stack<int> s4(move(s3));

    //---------------------------------------------------
    // 2. Constructor with underlying container
    //---------------------------------------------------

    deque<int> values =
    {
        100, 200, 300
    };

    stack<int> s5(values);

    //---------------------------------------------------
    // 3. Initial contents
    //---------------------------------------------------

    cout << "Initial stack:\n";

    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }

    cout << "\n";

    //---------------------------------------------------
    // Rebuild stack
    //---------------------------------------------------

    s2.push(10);
    s2.push(20);
    s2.push(30);

    //---------------------------------------------------
    // 4. empty()
    //---------------------------------------------------

    cout << "\nempty() : "
        << s2.empty() << "\n";

    //---------------------------------------------------
    // 5. size()
    //---------------------------------------------------

    cout << "size() : "
        << s2.size() << "\n";

    //---------------------------------------------------
    // 6. top()
    //---------------------------------------------------

    cout << "top() : "
        << s2.top() << "\n";

    //---------------------------------------------------
    // 7. top() - modify top element
    //---------------------------------------------------

    s2.top() = 99;

    cout << "top() after modification : "
        << s2.top() << "\n";

    //---------------------------------------------------
    // 8. push()
    //---------------------------------------------------

    s2.push(40);

    cout << "\nAfter push(40):\n";

    cout << "top() : "
        << s2.top() << "\n";

    cout << "size() : "
        << s2.size() << "\n";

    //---------------------------------------------------
    // 9. emplace()
    //---------------------------------------------------

    s2.emplace(50);

    cout << "\nAfter emplace(50):\n";

    cout << "top() : "
        << s2.top() << "\n";

    //---------------------------------------------------
    // 10. pop()
    //---------------------------------------------------

    s2.pop();

    cout << "\nAfter pop():\n";

    cout << "top() : "
        << s2.top() << "\n";

    //---------------------------------------------------
    // 11. pop() does not return the element
    //---------------------------------------------------

    /*
        This is WRONG:

        int value = s2.pop();

        pop() returns void.

        Correct approach:

        int value = s2.top();
        s2.pop();
    */

    int value = s2.top();
    s2.pop();

    cout << "\nRemoved value : "
        << value << "\n";

    //---------------------------------------------------
    // 12. Multiple push()
    //---------------------------------------------------

    s2.push(100);
    s2.push(200);
    s2.push(300);

    //---------------------------------------------------
    // 13. LIFO behavior
    //---------------------------------------------------

    cout << "\nLIFO order:\n";

    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }

    cout << "\n";

    //---------------------------------------------------
    // 14. Build another stack
    //---------------------------------------------------

    stack<int> s6;

    s6.push(10);
    s6.push(20);
    s6.push(30);

    stack<int> s7;

    s7.push(100);
    s7.push(200);

    //---------------------------------------------------
    // 15. swap()
    //---------------------------------------------------

    s6.swap(s7);

    cout << "\nAfter swap():\n";

    cout << "s6 top() : "
        << s6.top() << "\n";

    cout << "s7 top() : "
        << s7.top() << "\n";

    //---------------------------------------------------
    // 16. std::swap()
    //---------------------------------------------------

    swap(s6, s7);

    cout << "\nAfter std::swap():\n";

    cout << "s6 top() : "
        << s6.top() << "\n";

    cout << "s7 top() : "
        << s7.top() << "\n";

    //---------------------------------------------------
    // 17. Comparison operators
    //---------------------------------------------------

    stack<int> s8;

    stack<int> s9;

    s8.push(10);
    s8.push(20);

    s9.push(10);
    s9.push(20);

    cout << "\nComparison:\n";

    cout << "s8 == s9 : "
        << (s8 == s9) << "\n";

    cout << "s8 != s9 : "
        << (s8 != s9) << "\n";

    cout << "s8 < s9  : "
        << (s8 < s9) << "\n";

    cout << "s8 <= s9 : "
        << (s8 <= s9) << "\n";

    cout << "s8 > s9  : "
        << (s8 > s9) << "\n";

    cout << "s8 >= s9 : "
        << (s8 >= s9) << "\n";

    //---------------------------------------------------
    // 18. Modify stack through top()
    //---------------------------------------------------

    s8.top() = 999;

    cout << "\nModified top:\n";

    cout << "top() : "
        << s8.top() << "\n";

    //---------------------------------------------------
    // 19. Stack with string
    //---------------------------------------------------

    stack<string> names;

    names.push("Lr");
    names.push("Alice");
    names.push("Bob");

    cout << "\nString stack:\n";

    while (!names.empty())
    {
        cout << names.top() << "\n";
        names.pop();
    }

    //---------------------------------------------------
    // 20. Stack with vector as underlying container
    //---------------------------------------------------

    stack<int, vector<int>> vectorStack;

    vectorStack.push(10);
    vectorStack.push(20);
    vectorStack.push(30);

    cout << "\nStack using vector:\n";

    while (!vectorStack.empty())
    {
        cout << vectorStack.top() << " ";
        vectorStack.pop();
    }

    cout << "\n";

    //---------------------------------------------------
    // 21. Stack with deque as underlying container
    //---------------------------------------------------

    stack<int, deque<int>> dequeStack;

    dequeStack.push(100);
    dequeStack.push(200);
    dequeStack.push(300);

    cout << "\nStack using deque:\n";

    while (!dequeStack.empty())
    {
        cout << dequeStack.top() << " ";
        dequeStack.pop();
    }

    cout << "\n";

    //---------------------------------------------------
    // 22. Underlying container
    //---------------------------------------------------

    /*
        Default underlying container:

        stack<T>
        =
        stack<T, deque<T>>

        Therefore:

        stack<int> s;

        is effectively:

        stack<int, deque<int>> s;
    */

    //---------------------------------------------------
    // 23. No iterators
    //---------------------------------------------------

    /*
        stack does NOT provide:

        begin()
        end()
        cbegin()
        cend()

        Therefore this is NOT possible:

        for (auto it = s.begin(); it != s.end(); ++it)
        {
        }
    */

    //---------------------------------------------------
    // 24. No random access
    //---------------------------------------------------

    /*
        stack does NOT provide:

        operator[]
        at()

        Example:

        s[2];       // ERROR
        s.at(2);    // ERROR

        Only the top element is directly accessible.
    */

    //---------------------------------------------------
    // 25. No insert() / erase()
    //---------------------------------------------------

    /*
        stack does NOT provide:

        insert()
        erase()
        clear()

        Elements can only be added using:

        push()
        emplace()

        and removed using:

        pop()
    */

    //---------------------------------------------------
    // 26. Clear a stack
    //---------------------------------------------------

    stack<int> clearStack;

    clearStack.push(10);
    clearStack.push(20);
    clearStack.push(30);

    while (!clearStack.empty())
    {
        clearStack.pop();
    }

    cout << "\nStack cleared.\n";

    cout << "empty() : "
        << clearStack.empty() << "\n";

    //---------------------------------------------------
    // 27. Empty stack safety
    //---------------------------------------------------

    /*
        Do NOT call:

        top()
        pop()

        on an empty stack.

        Always check:

        if (!s.empty())
        {
            s.top();
            s.pop();
        }
    */

    //---------------------------------------------------
    // 28. Final
    //---------------------------------------------------

    cout << "\nStack demonstration completed.\n";

    //---------------------------------------------------
    // End
    //---------------------------------------------------

    return 0;
}


/*
//---------------------------------------------------
Output:
//---------------------------------------------------

Initial stack:
30 20 10

empty() : 0
size() : 3
top() : 30
top() after modification : 99

After push(40):
top() : 40
size() : 4

After emplace(50):
top() : 50

After pop():
top() : 40

Removed value : 40

LIFO order:
300 200 100 99 20 10

After swap():
s6 top() : 200
s7 top() : 30

After std::swap():
s6 top() : 30
s7 top() : 200

Comparison:
s8 == s9 : 1
s8 != s9 : 0
s8 < s9  : 0
s8 <= s9 : 1
s8 > s9  : 0
s8 >= s9 : 1

Modified top:
top() : 999

String stack:
Bob
Alice
Lr

Stack using vector:
30 20 10

Stack using deque:
300 200 100

Stack cleared.
empty() : 1

Stack demonstration completed.


//---------------------------------------------------
*/




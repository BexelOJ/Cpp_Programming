#include <iostream>
using namespace std;

// Node structure for Linked List
struct Node {
    int data;  // Data to store
    Node* next;  // Pointer to the next node

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Stack class using Linked List
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Push function to add an element to the stack
    void push(int value) {
        Node* newNode = new Node(value);  // Create a new node
        newNode->next = top;  // Link the new node to the previous top
        top = newNode;  // Update the top to the new node
    }

    // Pop function to remove the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;  // Move top to the next node
        delete temp;  // Delete the old top node
    }

    // Peek function to get the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;  // Return a sentinel value if the stack is empty
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor to clean up the stack
    ~Stack() {
        while (!isEmpty()) {
            pop();  // Pop all elements
        }
    }
};

// Main function to test the stack implementation
int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;  // Should print 30

    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;  // Should print 20

    stack.pop();
    stack.pop();
    stack.pop();  // Trying to pop from empty stack

    return 0;
}







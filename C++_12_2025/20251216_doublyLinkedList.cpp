#include <iostream>
using namespace std;

class Node {
public:
    int data = 0;
    Node* next;
    Node* prev;  // ← NEW: Previous pointer
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}  // Initialize prev too
};

class DoubleLinkedList {
    Node* head;
public:
    DoubleLinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        newNode->prev = nullptr;  // New node becomes head, no previous

        if (head) {
            head->prev = newNode;  // Old head's prev points to new head
        }
        head = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~DoubleLinkedList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    DoubleLinkedList List;

    List.insert(10);
    List.insert(20);
    List.insert(30);
    List.insert(40);

    List.display();  // Output: 40 30 20 10 

    return 0;
}



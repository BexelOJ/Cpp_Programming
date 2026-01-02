#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) :data(value), next(nullptr) {}
};

class DoubleLinkedList {
    Node* head;
public:
    DoubleLinkedList() :head(nullptr) {}  // construtor

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtIndex(int n, int val) {
        Node* newNode = new Node(val);
        // Insert at the beginning (index 0)
        if (n == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Find the (n-1)-th node (node just before the insertion point)
        Node* temp = head;
        for (int i = 0; i < n-1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        // If index is out of bounds (past the end), you can either append or ignore
        if (temp == nullptr) {
            // index too large; simple choice: insert at tail
            // or: delete newNode and return; depending on what you want
            delete newNode;
            std::cout << "Index out of limit of the List" << std::endl;
            return;
        }

        // Splice newNode into the list
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

};

int main() {
    DoubleLinkedList list;

    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);

    list.insertAtTail(40);
    list.insertAtTail(50);

    list.insertAtHead(9);
    list.insertAtHead(07);
    
    list.insertAtTail(55);

    list.display();

    int index = 0, value = 0;
    std::cout << "Insert at which index ? and what Value ?" << std::endl;
    std::cin >> index >> value;

    list.insertAtIndex(index, value);
    list.display();

    return 0;
}



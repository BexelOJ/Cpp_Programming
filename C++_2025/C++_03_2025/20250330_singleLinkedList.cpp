#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Define the LinkedList class
class LinkedList {
public:
    Node* head;

    // Constructor to initialize the list
    LinkedList() {
        head = nullptr;
    }

    // Function to add a node at the end of the list
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
       
        // If the list is empty, make the new node the head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Otherwise, traverse to the last node and insert the new node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to display the list
    void display() {
        if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to delete a node by value
    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }

        // If the node to be deleted is the head
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        // If the node was not found
        if (temp->next == nullptr) {
            cout << "Node with value " << val << " not found!" << endl;
            return;
        }

        // Delete the node
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Function to search for a node by value
    bool search(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Destructor to clean up the allocated memory
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};



int main() {
    LinkedList list;

    // Insert elements
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    // Display the list
    cout << "Linked List: ";
    list.display();

    // Delete a node
    cout << "\nDeleting node with value 20..." << endl;
    list.deleteNode(20);

    // Display the updated list
    cout << "Updated Linked List: ";
    list.display();

    // Search for a node
    int searchVal = 30;
    if (list.search(searchVal)) {
        cout << "\nNode with value " << searchVal << " found!" << endl;
    } else {
        cout << "\nNode with value " << searchVal << " not found!" << endl;
    }

    return 0;
}



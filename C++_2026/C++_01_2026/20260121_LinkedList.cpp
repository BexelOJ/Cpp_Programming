#include <iostream>

class Node {

public:
    int data;
    Node* next;
    Node(int val) :data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void appendAtBack(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* tmp = head;
            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    }
    void appendAtFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* tmp = head;
        while (tmp) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

    
    ~LinkedList() {
        Node* tmp = head;
        while (tmp) {
            Node* next = tmp->next;
            delete tmp;
            tmp = next;
        }
        head = nullptr;
    }
    
};


int main() {
    LinkedList list;
    
    list.appendAtFront(10);
    list.appendAtBack(20);
    list.appendAtFront(30);
    list.appendAtBack(40);
    list.appendAtFront(50);

    list.display();

    return 0;
}



#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int value) :data(value), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* tmp = head;
        while (tmp) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout<<std::endl;
    }
};

int main() {
    LinkedList list;
    
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    list.display();

    return 0;
}


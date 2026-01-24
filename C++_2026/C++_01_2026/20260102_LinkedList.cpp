#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int Value):data(Value), next(nullptr){}
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
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




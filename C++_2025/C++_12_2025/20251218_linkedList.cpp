#include <iostream>

using namespace std;

class Node {
public:
    int data = 0;
    Node* next;
    Node(int value) :data(value), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList():head(nullptr){}

    void insert(int val) {
        Node* newNode = new Node(val);
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
    LinkedList List;
    // std::cout << sizeof(List) << std::endl;
    
    List.insert(15);
    List.insert(25);
    List.insert(35);
    List.insert(45);

    List.display();
    
    return 0;
}


#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int v) :data(v), next(nullptr) {}
};

class linkedList {
    Node* head;
public:
    linkedList(){
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
        std::cout << std::endl;
    }

    ~linkedList() {
        Node* tmp = head;
        while (tmp) {
            Node* nxt = tmp;
            tmp = tmp->next;
            delete nxt;
        }
    }
};

int main() {
    linkedList list;
    
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    list.display();

    return 0;
}


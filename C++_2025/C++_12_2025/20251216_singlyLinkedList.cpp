#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int a) : data(a), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList(): head(nullptr) {
    
    }

    void insertAtHead(int v) {
        Node* newNode = new Node(v);
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
        head = nullptr;
    }
};


int main() {
    int n = 0;
    LinkedList list;

    std::cout << "Enter the size of the LinkedList: " << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int a = 0;
        std::cout << "Enter the " << i+1 << " value of Node : " << std::endl;
        std::cin >> a;
        list.insertAtHead(a);
    }
    
    list.display();
    
    return 0;
}



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Append a node at the end
    void append(int value) {
        Node* newNode = new Node(value);
        cout<<"size of Void* : "<<sizeof(void*)<<endl;
        cout<<sizeof(newNode)<<endl;
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Print the linked list
    void print() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data;
            if (temp->next) std::cout << " -> ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;
    
    list.append(10);
    list.append(20);
    list.append(30);

    std::cout << "Linked List: ";
    list.print();

    return 0;
}


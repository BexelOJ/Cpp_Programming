#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) :data(val), next(nullptr) {};
};

class LinkedList {
    Node* head;
public:
    int count = 0;
    LinkedList() {
        head = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void normalDisplay() {
        Node* tmp = head;
        while (tmp) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
            count++;
        }
        std::cout << std::endl;
    }
    
    void reverseDisplay() {
      
        for (int i = 0; i < count; i++) {
            Node* tmp_2 = head;          // ✅ reset every time
            int j = count - i - 1;       // ✅ correct index from end

            while (j > 0) {
                tmp_2 = tmp_2->next;
                j--;
            }

            std::cout << tmp_2->data << " ";
        }

        std::cout << std::endl;
    }

};

int main() {
    LinkedList list;
    
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    list.append(60);

    list.normalDisplay();

    list.reverseDisplay();

    return 0;
}


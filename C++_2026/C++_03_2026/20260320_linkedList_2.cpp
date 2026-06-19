#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr){}
};

class linkedList {
    Node* head;
public:
    int count = 0;
    linkedList() {
        head = nullptr;
    }

    void append(int val) {
        Node* newNode = new Node(val);
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
        for(int i =0; i<count; i++){
           
            Node* tmp = head;

            int j = count - i - 1;
            while (j > 0) {
                tmp = tmp->next;
                j--;
            }
            std::cout << tmp->data << " ";
        }
        std::cout << std::endl;
    }

};

int main() {
    linkedList list;

    list.append(15);
    list.append(25);
    list.append(35);
    list.append(45);
    list.append(55);
    list.append(65);

    list.normalDisplay();

    list.reverseDisplay();

    return 0;
}



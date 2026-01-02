#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int value):val(value), next(nullptr){}
};

class LinkedList{
    Node* head = nullptr;
public:
    LinkedList(){
        head = nullptr;
    }

    void append(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next){
            temp = temp->next;

        }
        temp->next = newNode;
    }

    void display() const {
        Node* temp = head;
        while(temp){
            cout<<temp->val;
            if(temp->next) cout<<" -> ";
            temp = temp->next;
        }
        cout<<endl;
    }

    ~LinkedList(){
        Node* current = head;
        while(current){
            Node* next = current->next;
            delete current;
            current = next;
        }
    }  
};

int main(){
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);

    list.display();

    return 0;
}


#include <iostream>
#include<forward_list>
#include <memory>
#include <list>

struct Node{
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
Node* head;
public:
    LinkedList() : head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void displayCommands(){
        // std::cout<<list1.begin()<<std::endl;
        // std::cout<<list1.end()<<std::endl;
        // std::cout<<list1.rbegin()<<std::endl;
        // std::cout<<list1.rend()<<std::endl;
        // std::cout<<list1.cbegin()<<std::endl;
        // std::cout<<list1.cend()<<std::endl;

    }
   ~LinkedList(){
    std::cout<<"Destructor called to free memory."<<std::endl;
    Node* current = head;
    while(current){
        Node* newNode = current->next;
        delete current;
        current = newNode;
    }
}
    // Additional methods for adding two linked lists can be implemented here
};

int main(){
    LinkedList list1, list2, result, add;
    int n=0, value=0;
    std::cout<<"Enter the Size of First Linked List: "<<std::endl;
    std::cin>>n;
    std::cout<<"Enter the First Linked List: "<<std::endl;
    for(int i=0; i<n; i++){
        std::cout<<"Enter "<<i+1<<" element : ";
        std::cin>>value;
        list1.append(value);       
    }

    std::cout<<"\nEnter the Size of Second Linked List: "<<std::endl;
    std::cin>>n;
    std::cout<<"Enter the Second Linked List: "<<std::endl;
    for(int i=0; i<n; i++){
        std::cout<<"Enter "<<i+1<<" element : ";
        std::cin>>value;
        list2.append(value);       
    }    
    list1.display();
    list2.display();
    int s1 = list1.size();
    int s2 = list2.size();
    
    //list1.displayCommands();
// std::cout<<list1.empty()<<std::endl;       // true if empty
// std::cout<<list1.size()<<std::endl;        // number of elements
// std::cout<<list1.max_size()<<std::endl;    // maximum possible elements

    return 0;
}


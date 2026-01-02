#include <iostream>
#include <vector>
#include <algorithm>

struct Node{
    int data;
    Node* next;

    Node(int value): data(value), next(nullptr){}
};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }
    int n=0;
    void append(int value){
        Node* newNode = new Node(value);
        n++;
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp -> next = newNode;
    }

    void display(){
        Node* temp = head;
        while(temp){
            std::cout<<temp->data<<" ";
            if(temp->next){std::cout<<"-> ";}
            temp = temp->next;
        }
    std::cout<<std::endl;
    }
    
    void sort(){
        Node* temp = head;
        int tp;
        for(int i=0; i<n-1; i++){
            temp = head;
            for(int j=0; j<n-i-1; j++){
                if(temp->data > temp->next->data){
                    tp = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = tp;
                }  
                temp = temp->next; 
            }
        }
    }

    int displayAt(int n){
        Node* temp = head;
        while(n-1){
            temp = temp->next;
            n--;
        }
        return temp->data;
    }

    ~LinkedList(){
        Node* temp = head;
        while(temp){
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main(){
    LinkedList list;
    
    list.append(50);
    list.append(30);
    list.append(40);
    list.append(20);
    list.append(10);

    list.display();

    list.sort();

    list.display();

    std::cout<<list.displayAt(3)<<std::endl;

    std::cout<<list.n<<std::endl;
    return 0;
}



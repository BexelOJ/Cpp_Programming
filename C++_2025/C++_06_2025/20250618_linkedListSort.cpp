#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    Node(int val):data(val), next(nullptr){}
};

class LinkedList{
Node* head;
public:
    LinkedList(){
       head = nullptr; 
    }
    
    static int n; 
    
    void append(int value){
        n++;
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data;
            if(temp->next){
                cout<<" -> ";
            }
            temp = temp->next;
        }
        cout<<endl;
    }
    
    void displayAt(int n){
        Node* temp = head;
        int dup = n;
        while(n){
            n--;
            temp = temp->next;
        }
        cout<<"at "<<dup<<" : "<<temp->data<<endl;
    }

    void sort() {
        if (!head || !head->next) return;  // No need to sort 0 or 1 node

        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current->next) {
                if (current->data > current->next->data) {
                    // Swap data
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }
};

int LinkedList::n = 0; 

int main(){
    LinkedList list;
    int m;

    list.append(40);
    list.append(50);
    list.append(30);
    list.append(10);
    list.append(20);
    
    list.display();
    
    list.displayAt(2);
    list.displayAt(3);    
    
    //cout<<"n: "<<LinkedList::n<<endl;
    cout<<"n: "<<list.n<<endl;
    m = list.n/2;
    list.displayAt(m);
    //list.sort();
    
    //list.display();
    
    return 0;
}



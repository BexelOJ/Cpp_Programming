#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    deque<int> myDeque;
    deque<int> deq2 = {11,12,13,14,15};
    //deq2.resize(10);
    cout<<"2 size: "<<deq2.size()<<endl;
    // Insert 10 elements
    myDeque.push_back(5);
    myDeque.push_back(2);
    myDeque.push_back(7);
    myDeque.push_back(3);
    myDeque.push_back(8);
    myDeque.push_back(6);

    myDeque.push_back(4);
    myDeque.push_back(9);
    myDeque.push_front(1);
    myDeque.push_front(10);

    myDeque.pop_front();
    myDeque.pop_back();
  
    cout<<"1 Size: "<<myDeque.size()<<endl;
    
    // Print the contents of the deque
    cout << "Deque contents: ";
    for (const auto& elem : myDeque) {
        cout << elem << " ";
    }   
    cout << endl;

    
    // Sort the deque
    sort(myDeque.begin(), myDeque.end());
    cout << "Sorted deque contents: ";
    for (const auto& elem : myDeque) {
        cout << elem << " ";
    }
    cout << endl;

    // Find an element
    int target = 7;
    auto it = find(myDeque.begin(), myDeque.end(), target);
    if (it != myDeque.end()) {
        cout << "Found element: " << *it << endl;
    } else {
        cout << "Element not found" << endl;
    }

    // Remove an element
    myDeque.erase(it);
    cout << "Deque contents after removal: ";
    for (const auto& elem : myDeque) {
        cout << elem << " ";
    }   
    cout << endl;
    
    // Clear the deque
    myDeque.clear();
    cout << "Deque contents after clear: ";
    for (const auto& elem : myDeque) {
        cout << elem << " ";
    }
    cout << endl;

    // Check if the deque is empty
    if (myDeque.empty()) {
        cout << "Deque is empty" << endl;
    } else {
        cout << "Deque is not empty" << endl;
    }

    // Insert 10 elements again loop    
    for (int i = 0; i < 10; ++i) {
        myDeque.push_back(i+20);
    }

    // Print the contents of the deque
    cout << "Deque contents: ";
    for (const auto& elem : myDeque) {
        cout << elem << " ";
    }
    cout << endl;

    // Sort the deque
    sort(myDeque.begin(), myDeque.end());   
    cout << "Sorted deque contents: ";  
    for (const auto& elem : myDeque) {
        cout << elem << " ";
    }

    cout << endl;

    // get_allocator().deallocate(deq2.data(), deq2.size());
    // cout << "Deque contents: ";
    // for (const auto& elem : deq2) {
    //     cout << elem << " ";
    // }
    // cout << endl;
    cout << "2 Size: "<<deq2.size()<<endl;
    cout << "2 Max Size: "<<deq2.max_size()<<endl;
    cout << "2 Front: "<<deq2.front()<<endl;
    cout << "2 Back: "<<deq2.back()<<endl;
    cout << "2 At: "<<deq2.at(1)<<endl;
    cout << "2 Begin: "<<*(deq2.begin())<<endl;
    cout << "2 End: "<<*(deq2.end()-1)<<endl;
    cout << "2 Rbegin: "<<*deq2.rbegin()<<endl;
    cout << "2 Rend: "<<*(deq2.rend()-1)<<endl;
    //cout << "2 Data: "<<deq2.data()<<endl;
    cout << "2 Empty: "<<deq2.empty()<<endl;
    cout << "2 Size: "<<deq2.size()<<endl;
    return 0;
}



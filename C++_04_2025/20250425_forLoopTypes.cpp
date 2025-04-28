#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
vector<int> v1(7);

cout<<"Size: "<<v1.size()<<endl;
cout<<"Capacity: "<<v1.capacity()<<endl;

v1.reserve(10); // Capacity is increased to 10
cout<<"Size: "<<v1.size()<<endl;
cout<<"Capacity: "<<v1.capacity()<<endl;

v1.resize(5,1); // Resizes the vector to 5 elements, filling with 1
// v1 becomes: {1, 1, 1, 1, 1}
// Note: The original vector was of size 7, but now it is resized to 5
// and the extra elements are discarded.
cout<<"Size: "<<v1.size()<<endl;
cout<<"Capacity: "<<v1.capacity()<<endl;


// Index based access
// v1[0] = 1;
for(int i=0; i < v1.size(); ++i)
{
    v1[i] = i + 1;
    cout<<v1[i]<<" ";
}
cout<<endl;
// v1 becomes: {1, 2, 3, 4, 5}


// Range based for loop
for(int x : v1)
    cout<<x<<" ";
cout<<endl;
// v1 becomes: {1, 2, 3, 4, 5}
// Note: The original vector was of size 7, but now it is resized to 5
// and the extra elements are discarded.
// v1 becomes: {1, 2, 3, 4, 5}


// Iterator based for loop
for(vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    cout<<*it<<" ";
cout<<endl;
// v1 becomes: {1, 2, 3, 4, 5}
// Note: The original vector was of size 7, but now it is resized to 5
// and the extra elements are discarded.


// Auto keyword based for loop
for(auto it = v1.begin(); it != v1.end(); ++it)
    cout<<*it<<" ";
cout<<endl;
// v1 becomes: {1, 2, 3, 4, 5}
// Note: The original vector was of size 7, but now it is resized to 5
// and the extra elements are discarded.


// For each loop with lambda function
for_each(v1.begin(), v1.end(), [](int x){cout<<x<<" ";});
cout<<endl;
// v1 becomes: {1, 2, 3, 4, 5}
// Note: The original vector was of size 7, but now it is resized to 5
// and the extra elements are discarded.



// Push back a new element
v1.push_back(20);
// v1 becomes: {1, 2, 3, 4, 5, 20}

cout<<"Size: "<<v1.size()<<endl;
cout<<"Capacity: "<<v1.capacity()<<endl;

for(int x : v1)
    cout<<x<<" ";
cout<<endl;

    return 0;
}


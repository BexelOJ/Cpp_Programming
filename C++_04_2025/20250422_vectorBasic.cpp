#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
vector<int> v1(7);

cout<<"Size: "<<v1.size()<<endl;
cout<<"Capacity: "<<v1.capacity()<<endl;

v1.reserve(10);
cout<<"Size: "<<v1.size()<<endl;
cout<<"Capacity: "<<v1.capacity()<<endl;

//v1.resize(5,1);
cout<<"Size: "<<v1.size()<<endl;
cout<<"Capacity: "<<v1.capacity()<<endl;

for(int i=0; i < v1.size(); ++i)
{
    v1[i] = i + 1;
    cout<<v1[i]<<" ";
}
cout<<endl;

for(int x : v1)
    cout<<x<<" ";
cout<<endl;

for(vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    cout<<*it<<" ";
cout<<endl;

for(auto it = v1.begin(); it != v1.end(); ++it)
    cout<<*it<<" ";
cout<<endl;

for_each(v1.begin(), v1.end(), [](int x){cout<<x<<" ";});
cout<<endl;

v1.push_back(20);

cout<<"Size: "<<v1.size()<<endl;
cout<<"Capacity: "<<v1.capacity()<<endl;

for(int x : v1)
    cout<<x<<" ";
cout<<endl;

//push_back(value)
v1.push_back(30);
v1.push_back(40);
v1.push_back(50);
v1.push_back(60);
v1.push_back(70);

cout<<"Size: "<<v1.size()<<endl;
cout<<"Capacity: "<<v1.capacity()<<endl;

//insert(position, value)
vector<int> v = {1, 2, 4};
v.insert(v.begin() + 2, 3);  // Insert 3 at index 2
for(int x : v)
    cout<<x<<" ";
cout<<endl;

// v becomes: {1, 2, 3, 4}

// insert multiple elements:
v.insert(v.begin(), 3, 100);  // inserts 100, three times at the start
for(int x : v)
    cout<<x<<" ";
cout<<endl;

//emplace_back(value)
//Similar to push_back, but constructs the element in place (faster for objects).
v.emplace_back(20);
for(int x : v)
    cout<<x<<" ";
cout<<endl;

//emplace(position, value)
v.emplace(v.begin() + 1, 99);

//assign()
v.assign(5, 42);  // v becomes {42, 42, 42, 42, 42}
for(int x : v)
    cout<<x<<" ";
cout<<endl;

cout<<"Size: "<<v.size()<<endl;
cout<<"Capacity: "<<v.capacity()<<endl;

/*

push_back(val)	    Add at end
insert(pos, val)	Insert at a specific position
emplace_back(val)	Faster insert at end (for objects)
emplace(pos, val)	Insert in-place at position
assign(n, val)	    Replace vector with n copies of val

*/


return 0;
}

/*
OUTPUT:

Size: 7
Capacity: 7
Size: 7
Capacity: 10
Size: 7
Capacity: 10
1 2 3 4 5 6 7 
1 2 3 4 5 6 7 
1 2 3 4 5 6 7 
1 2 3 4 5 6 7 
1 2 3 4 5 6 7 
Size: 8
Capacity: 10
1 2 3 4 5 6 7 20 
Size: 13
Capacity: 20

*/





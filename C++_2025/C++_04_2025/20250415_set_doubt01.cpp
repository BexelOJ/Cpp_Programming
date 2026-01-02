#include <iostream>
#include <set>
#include <vector>
#include <array>

using namespace std;

int main()
{
set<int> pp = {1,2,3,4,5};

// for(int i=0; i<5; i++)
// {
//     cout<<pp[i]<<" ";
// }
// cout<<pp.count()<<endl;

//pp.insert(2);
pp.insert(6);
pp.find(5);
cout<<pp.size()<<endl;
cout<<"Count: "<<pp.count(10)<<endl;

pp.insert(7);
pp.insert(8);
cout<<pp.size()<<endl;
pp.erase(5);
cout<<pp.size()<<endl;

bool b = pp.empty()?true:false;
cout<<b<<endl;


return 0;
}

/*
OUTPUT:

6
Count: 0
8
7
0

*/




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
vector<int> vec = {1,11,3,4,5,8,10,15};
for(size_t i=0; i<vec.size(); i++)
{
    cout<<vec.at(i)<<" ";
}
cout<<endl;

cout<<"1st Element: "<<vec.front()<<endl;
cout<<"Last Element: "<<vec.back()<<endl;
//cout<<vec.at(20)<<" ";
cout<<"1st Element: "<<*(vec.begin())<<endl;
cout<<"Last Element: "<<*(vec.end()-1)<<endl;

int* ptr = vec.data();
for(size_t i=0; i<vec.size(); i++)
{
    cout<<*(ptr+i)<<" ";
}
cout<<endl;

sort(vec.begin(),vec.end());
for(size_t i=0; i<vec.size(); i++)
{
    cout<<vec.at(i)<<" ";
}
cout<<endl;

vector<int>::iterator it = vec.end()-1;
cout <<"Iterator: "<< *(it); // prints 10
cout<<endl;

vector<int>::iterator it2 = vec.cbegin();
cout<<*it<<endl;
return 0;
}





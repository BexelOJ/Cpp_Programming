#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

void printVector(const vector<int>& v) {
    cout << "Vector: ";
    for (const auto& elem : v) {
        cout << elem << " ";
    }
    cout << endl;
}


int main(){
    vector<long long int> nums = {1,1,2,2,2,3,3,3,4,4,4,4,5,5,5,5,5};
    vector<char> chr = {'a','b','c','d','e','f','g','h','i','j'};
    vector<string> str = {"hello","world","this","is","a","test"};

    int target = 3;
    // auto it = find(nums.begin(), nums.end(), target);
    // if (it != nums.end()) {
    //     cout << "Found " << target << " at index " << distance(nums.begin(),it) << endl;
    // } else {
    //     cout << target << " not found" << endl;
    // }
    cout<<"nums: ";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout<<nums.size()<<endl;
    cout<<nums.capacity()<<endl;
    cout<<nums.max_size()<<endl;
    cout<<nums.front()<<endl;
    cout<<nums.back()<<endl;
    cout<<nums.data()<<endl; // pointer to the first element
    cout<<*nums.data()<<endl; // value of the first element
    cout<<(nums.data()+1)<<endl; // value of second element
    cout<<(nums.data()+2)<<endl; // value of fourth element
    cout<<nums.at(0)<<endl;
    cout<<nums.at(1)<<endl;
    cout<<nums.at(16)<<endl;

    cout<<"Ch Size: "<<chr.size()<<endl;
    cout<<chr.capacity()<<endl;
    cout<<chr.max_size()<<endl;
    cout<<chr.front()<<endl;
    cout<<chr.back()<<endl;
    cout<<chr.data()<<endl; // pointer to the first element
    cout<<*chr.data()<<endl; // value of the first element
    cout<<*(chr.data()+'c')<<endl; // value of second element
    cout<<*(chr.data()+2)<<endl; // value of third element
    // cout<<chr.at(0)<<endl;
    // cout<<chr.at(1)<<endl;
    // cout<<chr.at(16)<<endl;

    cout<<"Str Size: "<<str.size()<<endl; 
    cout<<str.capacity()<<endl;
    cout<<str.max_size()<<endl;
    cout<<str.front()<<endl;
    cout<<str.back()<<endl;
    cout<<str.data()<<endl; // pointer to the first element
    cout<<*str.data()<<endl; // value of the first element
    cout<<(str.data()+1)<<endl; // value of second element
    cout<<(str.data()+2)<<endl; // value of third element
    cout<<str.at(0)<<endl;
    cout<<str.at(1)<<endl;
    cout<<str.at(str.size()-1)<<endl;
    cout<<str.at(0).size()<<endl;
    cout<<str.at(1).size()<<endl;
    cout<<str.at(3).size()<<endl;
    cout<<str.at(0).at(0)<<endl;
    cout<<str.at(0).at(1)<<endl;
    cout<<str.at(0).at(2)<<endl;
    cout<<str.at(0).at(3)<<endl;
    cout<<str.at(0).at(4)<<endl;
    // cout<<str.at(0).at(5)<<endl;  // error
    // cout<<str.at(0).at(6)<<endl;  // error
    return 0;
}
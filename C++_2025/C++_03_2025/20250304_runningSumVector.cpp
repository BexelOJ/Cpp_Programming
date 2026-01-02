#include <iostream>
#include <vector>

using namespace std;

int main()
{
int a=0, b=0, c=0;
vector<int> nums = {1,2,3,4,5};
int arr[] = {11,22,33,44,55};
nums.push_back(6);

// vector - a dynamic array
cout<<"Enter the Number of Elements to be added: "<<endl;
cin>>a;
for(int i=0; i<a; i++){   
    cin>>b;
    nums.push_back(b);
}

// Using a Range-Based For Loop
for (int x : nums) {
    cout << x << " ";
}
cout << endl;

for (int x : arr) {
    cout << x << " ";
}
cout << endl;
int ar = (sizeof(arr)/sizeof(int));
int nu = (sizeof(nums)/sizeof(int));
cout<<"Size of Array: "<<ar<<endl;
cout<<"Size of Vector: "<<nu<<endl;

int k;
for(int i=0; i<nu; i++)
    {
        k = num[i];
                                                                                                                       
    }  

for (int x : nums) {
    cout << x << " ";
}
cout << endl;

return 0;
}



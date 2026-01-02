#include<iostream>
#include<string>
using namespace std;

int main()  {
    string A, B;
    cin>>A>>B;
    // YOUR CODE GOES HERE
    int len1 = A.size();
    int len2 = B.size();
    string c = A+B;
    char temp;
    temp = A[0];
    A[0] = B[0];
    B[0] = temp;
    cout<<len1<<" "<<len2<<endl;
    cout<<c<<endl;
    cout<<A<<" "<<B<<endl;
    return 0;
}

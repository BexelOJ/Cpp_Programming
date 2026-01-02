#include <iostream>
#include <vector>

using namespace std;

vector<int>* reverseArray(vector<int> a) {
    int s = a.size();
    vector<int>* rv = new vector<int>(s);
    for(int i=0, j=(s-1); i<s; i++, j--)
    {
        rv[i] = a[j];
    }
    return rv;
}

int main()
{
int n=0;
cin>>n;
vector<int> v(n);
for(int i=0; i <n; i++)
{
    cin>>v[i];
}
vector<int>* res = reverseArray(v);



return 0;
}


#include <iostream>
#include <vector>

using namespace std;

int lonelyinteger(vector<int> a) {
    int s = a.size();
    
    for(int i=0; i<s; ++i)
    {
        int count = 0;
        for(int j=0; j<s; ++j)
        {
            if(a[i] == a[j])
            {
                count++;
            }
        }
        if(count == 1)
        {
            return a[i];
        }
    }
    return -1;
}

int main()
{
int n;
cin >>n;
vector<int> v(n);
for(int i=0; i<n ; i++)
{
    cin>>v[i];
}

for(int x : v)
    cout<<x<<" ";
cout<<endl;

cout<<lonelyinteger(v)<<endl;

return 0;
}


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> p1;

    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v2 = {11,12,13,14,15};
    vector<int> v3 = {16,17,18,19,20};

    vector<vector<int>> v2D = {v1,v2,v3};

    for(int i=0; i<v2D.size(); i++)
    {
        for(int j=0; j<v2D[i].size(); j++)
        {
            cout<<v2D[i][j]<<" ";
        }
        cout<<endl;
    }

return 0;
}



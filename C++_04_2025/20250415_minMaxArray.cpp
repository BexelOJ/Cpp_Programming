#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void minMaxSum(vector<int>);

int main()
{
vector<int> arr = {1, 2, 3, 4, 5};
minMaxSum(arr);

return 0;
}

void minMaxSum(vector<int> arr) {
int size = arr.size();
int min=arr[0], max = arr[0];
for(int i=0; i<size; i++)
{
   // min = arr[i];
    if(arr[i] < min)
    {
        min = arr[i];
    }
    // max = arr[i];
    if(arr[i] > max)
    {
        max = arr[i];
    }
}
cout<<"Min:"<<min<<endl;
cout<<"Max:"<<max<<endl;
vector<int> vmin = arr, vmax = arr;
auto minIndex = find(vmin.begin(), vmin.end(), min);
auto maxIndex = find(vmax.begin(), vmax.end(), max);

vmin.erase(minIndex);
vmax.erase(maxIndex);

cout<<vmin.size()<<endl;
cout<<vmax.size()<<endl;

int sumMin = 0, sumMax = 0;

for(int i=0; i< vmax.size(); i++)
{
sumMax = sumMax + vmax[i];
}
cout<<sumMax<<" ";

for(int i=0; i< vmin.size(); i++)
{
sumMin = sumMin + vmin[i];
}
cout<<sumMin<<endl;

}


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 = { 1,2,3 };
    vector<int> v2 = { 4,5,6 };

    cout << "Before Swap :" << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    swap(v1, v2);
    cout << "After Swap :" << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    return 0;
}




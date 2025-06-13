#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<vector<int>> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    vector<vector<int>> vec= {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    display(vec);

    vec[0].push_back(10);  // now first row is {1, 2, 3, 10}
    display(vec);

    vec.push_back({ 10, 20, 30 });
    vec.push_back({ 40, 50, 60 });
    display(vec);

    return 0;
}


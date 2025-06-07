#include <iostream>

using namespace std;

int main(){
    int n=0, m=0, **arr=nullptr;
    cout << "Enter the number of Rows and Columns: ";
    cin >> n >> m;

    // array of pointers
    arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
    }   
    // input values
    cout << "Enter the values for the array: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //cout << "arr[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }
    }   
    // output values
    cout << "The values in the array are: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;
            cout<<arr[i][j] << " ";
        }
        cout << endl;
    }   

    return 0;
}


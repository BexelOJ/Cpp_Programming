#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &A, int B) {
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < A.size(); ++i) {
        // Remove indices out of the current window
        if (!dq.empty() && dq.front() <= i - B) {
            dq.pop_front();
        }

        // Remove elements smaller than the current from the back
        while (!dq.empty() && A[dq.back()] <= A[i]) {
            dq.pop_back();
        }

        // Push current index
        dq.push_back(i);

        // Window has started to form, start storing max
        if (i >= B - 1) {
            result.push_back(A[dq.front()]);
        }
    }

    return result;
}

int main()  {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        int B;
        cin >> B;
        vector<int> ans = solve(A, B);
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}


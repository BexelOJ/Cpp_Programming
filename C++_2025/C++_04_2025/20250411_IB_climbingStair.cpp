#include <iostream>
using namespace std;

int solve(int* A, int n1) {
    if (n1 == 1) return A[0];
    if (n1 == 2) return A[0] + A[1];

    int dp1 = A[0];       // Cost to reach stair 1
    int dp2 = A[0] + A[1]; // Cost to reach stair 2
    int current;
    int i;
    cout<<"DP1 = "<<dp1<<endl;
    cout<<"DP2 = "<<dp2<<endl;

    for (i = 2; i < n1; ++i) {
        current = A[i] + (dp1 < dp2 ? dp1 : dp2);
        dp1 = dp2;
        cout<<"dp1 = "<<i<<" "<<dp1<<endl;
        dp2 = current;
        cout<<"dp2 = "<<i<<" "<<dp2<<endl;    
    }

    return dp2;
}

int main() {
    // int A[] = {10, 15, 20, 5, 25, 35};
    int A[] = {10, 10, 10, 10, 10, 10};    
    int n1 = sizeof(A) / sizeof(A[0]);
    printf("Minimum cost to reach the Nth stair: %d\n", solve(A, n1));
    return 0;
}
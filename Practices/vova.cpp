/**
 * @file vova.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-29
 * 
 * @copyright Copyright (c) 2024
 * 
Array A has n elements; array B has m elements, m and n > 1. 
We divide each array into the same k > 0 groups; each group has consecutive elements from each array, 
and total of elements in k groups of each array is n and m. 
the minimum element of each group is 1, 
and the id of each group is 1,2,3,...k. Assume n>=m and k is unknown

Minimize the expression:
c = c[1] + c[2] + ... + c[k] with c[i] = (s[i] - u[i]) * (t[i] - v[i]) where:
s[i] is the sum of elements in group i of array A
u[i] is the number of elements in group i of array A
t[i] is the sum of elements in group i of array B
v[i] is the number of elements in group i of array B

 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<ll>> vvi;

#define INF LLONG_MAX

#define EL printf("\n")
#define sz(A) (int) A.size()

#define FOR(i,start,end) for (int i = start; i < end; i++)
#define FOD(i,start,end) for (int i = end; i > start; i--)

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

// Function to compute the prefix sum of an array
vector<ll> computePrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<ll> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }
    return prefixSum;
}

// Function to calculate the sum of a subarray using prefix sums
ll subArraySum(const vector<ll>& prefixSum, int start, int end) {

    return prefixSum[end + 1] - prefixSum[start];
}
// Function to compute the cost between two groups
ll calculateCost(int s, int u, int t, int v) {
    return (s - u) * (t - v);
}


// Function to minimize the cost function using dynamic programming with prefix sums
ll minimizeCost(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    int m = B.size();
    int k = min(n, m);  // Maximum number of partitions

    // Compute prefix sums for both arrays A and B
    vector<ll> prefixSumA = computePrefixSum(A);
    vector<ll> prefixSumB = computePrefixSum(B);

    // DP table dp[i][j] represents the minimum cost to divide the first i elements of A
    // and first j elements of B into groups.
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INF));

    // Base case: no elements, no groups, cost is 0.
    dp[0][0] = 0;

    // Iterate over the number of elements considered from A (i) and B (j)
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // DP recurrence: try every possible previous partition point but limit to k partitions
            for (int g = max(0, i - k); g < i; ++g) {
                for (int h = max(0, j - k); h < j; ++h) {
                    ll cost = calculateCost(prefixSumA, prefixSumB, g, i, h, j);
                    cout << "cost: " << cost << endl;
                    // Update the DP value for dp[i][j]
                    if (dp[g][h] != INF) {
                        dp[i][j] = min(dp[i][j], dp[g][h] + cost);
                    }
                }
            }
        }
    }

    // Print the DP table for debugging
    cout << "DP Table:" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // The final answer is the minimum cost to divide the entire arrays A and B
    return dp[n][m];
}



int main() {
    faster;
    FILE* file = freopen("INP/VoVa.TXT", "r", stdin);
    int m,n;
    cin >> m >> n;
    vector<int> A(m);
    vector<int> B(n);
    FOR(i,0,m) cin >> A[i];
    FOR(i,0,n) cin >> B[i];

    // Output the minimum cost
    long long result = minimizeCost(A, B);
    cout << result << endl;

    return 0;
}
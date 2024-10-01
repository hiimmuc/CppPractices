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

#include <omp.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<vector<ll>> vvi;

#define INF numeric_limits<ll>::max() 

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

// Function to calculate the cost for the group (A[g:i], B[h:j])
ll calculateCost(const vector<ll>& prefixSumA, const vector<ll>& prefixSumB, int g, int i, int h, int j) {
    ll s_i = subArraySum(prefixSumA, g, i - 1);
    ll u_i = i - g;
    ll t_i = subArraySum(prefixSumB, h, j - 1);
    ll v_i = j - h;
    ll cost = (s_i - u_i) * (t_i - v_i);

    // Debugging output
    cout << "Calculating cost for A[" << g << ":" << i - 1 << "] and B[" << h << ":" << j - 1 << "]" << " with ";
    cout << "s_i: " << s_i << ", u_i: " << u_i << ", t_i: " << t_i << ", v_i: " << v_i << ", cost: " << cost << endl;

    return cost;
}

// Function to minimize the cost function using dynamic programming with prefix sums and return DP table
vector<vector<ll>> minimizeCost(const vector<int>& A, const vector<int>& B) {
    int n = A.size(), m = B.size();
    int k = min (n, m);
    vector<ll> prefixSumA = computePrefixSum(A);
    vector<ll> prefixSumB = computePrefixSum(B);
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INF));

    dp[0][0] = 0; // Initialize base case
    int total_loops = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = INF;  // Ensure all values are initialized to INF
            for (int g = max(0, i -k); g < i; ++g) {
                for (int h = max(0, j - k); h < j; ++h) {
                    total_loops++;
                    ll cost = calculateCost(prefixSumA, prefixSumB, g, i, h, j);
                    if (dp[g][h] != INF) {  // Check if previous state is feasible
                        dp[i][j] = min(dp[i][j], dp[g][h] + cost);
                    }
                }
            }
        }
    }
    
    cout << "Total loops: " << total_loops << endl;
    return dp;  // Return the entire DP table
}


int main() {
    faster;
    FILE* file = freopen("INP/VoVa.TXT", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    FOR(i,0,n) cin >> A[i];
    FOR(i,0,m) cin >> B[i];

    vector<int> longer = (m >= n) ? A : B;
    vector<int> shorter = (m < n) ? A : B;
    n = longer.size();
    m = shorter.size();

    // Output the minimum cost
    vvi dp = minimizeCost(longer, shorter);
    // 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[n][m] << endl;

    return 0;
}
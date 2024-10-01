/**
 * @file VoVa.cpp
 * @author Vieoney (thaovan.140902@gmail.com)
 * @version 0.1
 * @date 2024-09-29
 *
 * @copyright Copyright (c) 2024
 * @brief C++ implementation
    Given two arrays A and B of integers.
    Array A has n elements; array B has m elements, n and m > 1 
    We divide each array into the same k > 0 groups(k is unknown).; 
    each group has consecutive elements from each array, 
    the minimum number of elements of each group is 1,
    and total of elements in k groups of each array is n and m. 

    Minimize the expression:
    c = c[1] + c[2] + ... + c[k] with c[i] = (s[i] - u[i]) * (t[i] - v[i]) where:
    s[i] is the sum of elements in ith group of array A
    t[i] is the sum of elements in ith group of array B
    u[i] is the number of elements in ith group of array A
    v[i] is the number of elements in ith group of array B

    Constraints:
    sum(s[i]) = sum(A[j]) for i = 1,2,...,k and j = 1,2,...,n
    sum(t[i]) = sum(B[j]) for i = 1,2,...,k and j = 1,2,...,m
    sum(u[i]) = n and sum(v[i]) = m

    @example: A = [3,7,4] and B = [5, 2] minimum cost is 17 with k = 2
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;

#define INF numeric_limits<ull>::max() 

#define FOR(i,start,end) for (int i = (start); i < (end); i++)
#define FOD(i,start,end) for (int i = (end); i > (start); i--)

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


ll minimizeCost1(const vi& A, const vi& B) {
    // NOTE: brute force solution, TLE and MLE but handle overflow
    int n = A.size(), m = B.size();
    int k = min (n, m);

    vll prefixSumA(n + 1, 0), prefixSumB(m + 1, 0);
    FOR(i,1,n + 1) prefixSumA[i] = prefixSumA[i-1] + A[i];
    FOR(i,1,m + 1) prefixSumB[i] = prefixSumB[i-1] + B[i];

    vector<vll> dp(n + 1, vll(m + 1, INF));

    dp[0][0] = 0; // Initialize base case

    FOR(i, 1, n + 1) {
        FOR(j, 1, m + 1) {
            FOR(g, max(1, i - k + 1), i + 1) {
                FOR(h, max(1, j - k + 1), j + 1) {
                    long long sA = prefixSumA[i] - prefixSumA[i - g];
                    long long sB = prefixSumB[j] - prefixSumB[j - h];
                    long long cost = (sA - g) * (sB - h);
                    if (dp[i - g][j - h] != INF) {
                        dp[i][j] = min(dp[i][j], dp[i - g][j - h] + cost);
                    }
                }
            }
        }
    }

    return dp[n][m];
}


ll minimizeCost2(const vi& A, const vi& B) {
    /*NOTE:  MEMORY LIMIT EXCEEDED and OVERFLOW 
    --> change to unsigned long long and save only current and previous state
    */
    int n = A.size(), m = B.size();

    vector<vll> dp(n + 1, vll(m + 1, INF));

    dp[0][0] = 0;  // Base case: no cost if there are no remaining elements

    FOR(x, 1, n + 1){
        FOR(y, 1, m + 1){
            dp[x][y] = min({dp[x -1][y -1], dp[x][y - 1] , dp[x - 1][y]}) + (ll)((A[x - 1] - 1) * (B[y - 1] - 1));
        }
    }

    return dp[n][m];  // Return the entire DP table
}


// Function to minimize the cost function using dynamic programming with prefix sums and return DP table
ull minimizeCost(const vi& A, const vi& B) {
    int n = A.size(), m = B.size();
    vector<ull> prev(m + 1, INF), curr(m + 1, INF);  // Only two 1D vectors

    prev[0] = 0;  // Base case initialization

    // Rolling array processing
    FOR(x, 1, n + 1) {
        curr[0] = INF;  // Reset current row start
        FOR(y, 1, m + 1) {
            curr[y] = min({prev[y - 1], prev[y], curr[y - 1]}) + (ull)(A[x - 1] - 1) * (B[y - 1] - 1);
        }
        prev = curr;  // Move current row to previous for next iteration
    }

    return curr[m];  // Return the minimum cost found
}


int main() {
    faster;

    int n, m;
    cin >> n >> m;

    vi A(n, 0), B(m, 0);
    FOR(i,0,n) cin >> A[i];
    FOR(i,0,m) cin >> B[i];

    cout << minimizeCost(A, B) << endl;
    
    return 0;
}
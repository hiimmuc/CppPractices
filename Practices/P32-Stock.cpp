/**
 * @file P32-Stock.cpp
 * @author Vieoney (thaovan.140902@gmail.com)
 * @brief Matrix prices (S x D) represents the S stocks in D days. The value of prices[i][j] is the price of stock i on day j. 
 * ------ Having initial M dollars, find the maximum profit that can be made by buying and selling stocks. 
 * @version 0.1
 * @date 2024-10-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;

#define INF 1e9

#define EL cout << endl;
#define sz(A) (int) A.size()

#define FOR(i,start,end) for (int i = start; i < end; i++)
#define FOD(i,start,end) for (int i = end; i > start; i--)

#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b
#define sum(a) accumulate(a, a + sizeof(a)/sizeof(a[0]), 0)

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// start here
int solve(vvi& prices, int S, int D, int M) {
    vi dp(D + 1, 0);
    FOR(i, 1, D + 1){
        dp[i] = M;
        FOD(k, i - 1,  0) FOR(j, 1, S + 1) {
            dp[i] = max(dp[i], max(dp[k] / prices[j][k]  * prices[j][i] + dp[k] % prices[j][k], M / prices[j][k] * prices[j][i] + M % prices[j][k]));
        }
    }

    return dp[D];
}


int main(){
    faster;
    // input
    FILE* inp = freopen("INP/P32-Stock.TXT", "r", stdin);

    int S, D, M;
    cin >> S >> D >> M;
    vvi prices(S, vi(D));
    FOR(i, 0, S) FOR(j, 0, D) cin >> prices[i][j]; 

    // solve
    cout << solve(prices, S, D, M) << endl;
    return 0;
}
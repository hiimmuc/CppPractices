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
#include "bits/stdc++.h"

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

#define _min(a,b) ((a) < (b) ? (a) : (b))
#define _max(a,b) ((a) > (b) ? (a) : (b))
#define _sum(a) accumulate(a, a + sizeof(a)/sizeof(a[0]), 0)
#define clr(x, c) memset(x, c, sizeof(x))

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// start here
const int maxD = 19, maxN = 500009, maxS = 59;
int prices[maxS][maxD], dp[maxN];
int S,D,M;

int solve() {
    FOR(j, 0, D-1){
        clr(dp, 0);
        FOR(i, 0, S){
            FOR(k, prices[i][j], M+1){
                dp[k] = _max(dp[k], dp[k - prices[i][j]] + prices[i][j+1] - prices[i][j]);
            }   
        }
        M += *max_element(dp, dp + M + 1);
    }
    return M;
}


int main(){
    faster;
    // input
    FILE* inp = freopen("INP/P32-Stock.TXT", "r", stdin);
    // 
    cin >> S >> D >> M;
    FOR(i, 0, S) FOR(j, 0, D) cin >> prices[i][j]; 
    // solve
    cout << solve() << endl;
    return 0;
}
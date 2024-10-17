#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;

#define INF numeric_limits<int>::max() 

#define FOR(i,start,end) for (int i = (start); i < (end); i++)
#define FOD(i,start,end) for (int i = (end) -1; i >= (start); i--)
#define FOR_INC(i,start,end,inc) for (int i = (start); i < (end); i += (inc))
#define FORA(i, arr) for (auto& i: arr)
#define fill_array(a, x) memset(a, x, sizeof(a))
#define max(a, b) a > b ? a : b

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// NOTE: start here
int MAX_N = 1e5;
int MAX_W = 1e3;
int MAX_T = 40;

template<class T>
struct Knapsack{
    int n, W;
    vector<T> dp, vl;
    vi ans, opt, wg;

    Knapsack(int n_, int W): n(0), W(W),
    dp(W + 1), vl(n_), opt(W + 1), wg(n_){}

    void Add(T v, int w){
    vl[n] = v;
    wg[n++] = w;
    }

    T conquer(int l, int r, int W){
        if(l == r){
            if(W >= wg[l])
            return ans.push_back(l), vl[l];
            return 0;
        }

        FOR(i, 0, W + 1)
            opt[i] = dp[i] = 0;
        int m = (l + r) >> 1;

        for(int i = l; i <= r; i++)
            for(int sz = W; sz >= wg[i]; sz--){
            T dpCur = dp[sz - wg[i]] + vl[i];
            if(dpCur > dp[sz]){
                dp[sz] = dpCur;
                opt[sz] = i <= m ? sz : opt[sz - wg[i]];
            }
            }

        T ret = dp[W];
        int K = opt[W];
        T ret2 = conquer(l, m, K) + conquer(m + 1, r, W - K);
        assert(ret2 == ret);
        return ret;
    }

    T Solve(){
        return conquer(0, n - 1, W);
    }
};


int main() {
    faster;
    
    FILE* file = freopen("INP/P32.TXT", "r", stdin);

    int rep;
    cin >> rep;
    while (rep--) {
        int N, M;
        cin >> N >> M;
        vi weights(N, 0), values(N, 0);
        FOR(i, 0, N) cin >> weights[i];
        FOR(i, 0, N) cin >> values[i];
        Knapsack<int> knapsack(N, M);
        FOR(i, 0, N) knapsack.Add(values[i], weights[i]);
        
        cout << knapsack.Solve() << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;

#define INF numeric_limits<int>::max() 

#define FOR(i,start,end) for (int i = (start); i < (end); i++)
#define FOD(i,start,end) for (int i = (end); i > (start); i--)
#define FORA(i, arr) for (int& i: arr)

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int minimumOperations1(const vi& A, int n, int h) {
    // NOTE: Brute force solution O(n * h) time
    if (h > n) return -1; // Cannot have a subarray of length h if h > n
    
    int minOperations = INF;

    // Check each possible window of size h
    FOR(start, 0, n - h + 1) {
        int currentOperations = 0;
        bool valid = true;

        FOR(i, 0, h) {
            int currentValue = A[start + i];
            int targetValue = 1 + i;
            
            if (currentValue > targetValue) {
                valid = false;
                break; // If any value in the window is greater than its target, it's impossible to transform
            } else {
                currentOperations += targetValue - currentValue;
            }
        }

        if (valid) {
            minOperations = min(minOperations, currentOperations);
        }
    }

    return minOperations == INF ? -1 : minOperations;
}

int minimumOperations(const vi& A, int n, int h) {
    // NOTE: Prefix sum, O(n) time
    if (h > n) return -1; // Not possible if h > n
    
    int minOperations = INF;
    
    vi prefixSum(n + 1, 0);

    FOR(i, 1, n+1) prefixSum[i] = prefixSum[i-1] + A[i-1];

    int sum_h = h * (h + 1) / 2;

    FOR(i, h - 1, n) {
        if (prefixSum[i] - prefixSum[i- h]  <= sum_h) {
            minOperations = min(minOperations, sum_h - (prefixSum[i] - prefixSum[i - h]));
        }
        else{
            continue;
        }
    }

    // Return the minimum operations found, or -1 if no valid window was found
    return minOperations == INF ? -1 : minOperations;
}



int main() {
    faster;
    FILE* file = freopen("./INP/P24.TXT", "r", stdin);
    
    int n, h;
    cin >> n >> h;
    vi arr(n);
    FORA(val, arr) cin >> val;

    int result = minimumOperations(arr, n, h);
    cout << result << endl;

    return 0;
}
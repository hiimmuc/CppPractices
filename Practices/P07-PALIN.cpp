/**
 * @file P07-PALIN.cpp  (Practices/P07-PALIN.cpp)
 * @author Vit hoc bai (thaovan.140902@gmail.com)
 * @brief Palindrome problem: Given a string S, and q queries, each query is a pair of integers (start, end). 
 * |S| <= 10^5, 1 <= q <= 10^5, 1 <= start <= end <= |S|; 
 * 1s time limit, 128MB memory limit
 * @version 0.1
 * @date 2024-09-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define INF 1e9

#define EL printf("\n")
#define sz(A) (int) A.size()

#define FOR(i,start,end) for (int i = start; i < end; i++)
#define FOD(i,start,end) for (int i = end; i > start; i--)

#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b
#define sum(a) accumulate(a, a + sizeof(a)/sizeof(a[0]), 0)

#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



// Hashing parameters
const long long MOD = 1e9 + 7;
const long long BASE = 31;

// Function to compute hash and power arrays
void computeHashesAndPowers(const string& S, vector<long long>& hash, vector<long long>& power) {
    int n = S.size();
    hash[0] = S[0] - 'a' + 1;
    power[0] = 1;

    for (int i = 1; i < n; ++i) {
        hash[i] = (hash[i - 1] * BASE + (S[i] - 'a' + 1)) % MOD;
        power[i] = (power[i - 1] * BASE) % MOD;
    }
}

// Function to compute the hash of a substring
long long getHash(const vector<long long>& hash, const vector<long long>& power, int l, int r) {
    long long result = hash[r];
    if (l > 0) {
        result = (result - hash[l - 1] * power[r - l + 1] % MOD + MOD) % MOD;
    }
    return result;
}

// Function to process queries to check if substrings are palindromes
void processQueries(const string& S, const vector<pair<int, int>>& queries) {
    int n = S.size();

    // Compute hashes for the original string
    vector<long long> hash(n), power(n);
    computeHashesAndPowers(S, hash, power);

    // Compute hashes for the reversed string
    string reversedS = S;
    reverse(reversedS.begin(), reversedS.end());
    vector<long long> revHash(n), revPower(n);
    computeHashesAndPowers(reversedS, revHash, revPower);

    for (const auto& query : queries) {
        int start = query.first - 1;
        int end = query.second - 1;

        // Length of the substring
        int len = end - start + 1;

        // Hash for the original substring
        long long originalHash = getHash(hash, power, start, end);
        cout << originalHash << endl;

        // Hash for the reversed substring
        long long reversedHash = getHash(revHash, revPower, n - end - 1, n - start - 1);
        cout << reversedHash << endl;

        if (originalHash == reversedHash) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    int q;
    string S;
    cin >> S;
    cin >> q;

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    processQueries(S, queries);

    return 0;
}

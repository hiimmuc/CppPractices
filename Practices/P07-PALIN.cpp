
// #include "bits/stdc++.h"
#include <iostream>

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

bool palindrome(string s){
    int left = 0, right = s.length() - 1; 
    while (left < right) { 
        if (s[left] != s[right]) { 
            return false; 
        } 
        left++; 
        right--; 
    } 
    return true; 
}

const int MAX_LEN = 1e5;
const int MAX_QUERY = 1e5;

char DP[MAX_LEN][MAX_QUERY];

int main () {
    bool debug = true;
    if(debug){
        FILE *inp, *out;
        int correct = 0;
        inp=freopen("INP/P07.TXT", "r", stdin);
        out=freopen("OUT/P07.TXT", "w", stdout);
        // input
        int q;
        string S;
        cin >> S;
        cin >> q;

        FOR(i, 0, q){
            int start, end;
            cin >> start >> end;
            if(palindrome(S.substr(start - 1, end - start + 1))){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
  
        }
    }
    else{
    }
    return 0;
}
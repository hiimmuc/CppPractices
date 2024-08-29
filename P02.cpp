
/*
Del segment problem:
*/

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sum(a) accumulate(a, a + sizeof(a)/sizeof(a[0]), 0)

const int N = 1e5;
int n, A[N];
FILE *inp, *out;

int main(){
    inp=freopen("INP/P02.txt", "r", stdin);
    out=freopen("OUT/P02.txt", "w", stdout);

    fscanf(inp,"%d",&n);
    FOR(i, 0, n-1) fscanf(inp,"%d",&A[i]);

    FOR(i, 0, n-1) cout << A[i];

    cout<<endl;

    int minAvg = 0;

    FOR(L, 1, n-1){
        FOR(windowSize, 0, n-2){
            int H = L + windowSize;
            FOR(k, L, H){
                A[k] = 0;
            }
            int avg = sum(A)/(n - windowSize);
            minAvg = minAvg<avg?minAvg:avg;
        }
    }
    fprintf(out,"%d", minAvg);
    cout<<minAvg<<endl;
    
    return 0;
}

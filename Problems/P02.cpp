
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


const int N = 10001;
int n, A[N];
FILE *inp, *out;

int main() {
    inp=freopen("INP/P02.TXT", "r", stdin);
    out=freopen("OUT/P02.TXT", "w", stdout);

    fscanf(inp,"%d",&n);

    for(int i=0; i < n; i++) fscanf(inp,"%d",&A[i]);

    // scanf("%d",&n);
    // cout << "Enter " << n << " numbers:" << endl;
    // FOR(i, 0, n-1) scanf("%d", &A[i]);

    float minAvg = INF;
    
    int dp[(n - 1) * (n - 2)/2][n];

    for(int L = 1; L < n; L++){
        for(int w = 0; w < n - (L + 1); w++ ){
            int H = L + w;
            for(int i = 0; i < n; i++){
                if (i < L || i > H) {
                    dp[w + (L - 1) * (n - 1)][i] = A[i];
                }
                else {
                    dp[w + (L - 1) * (n - 1)][i] = 0;
                }
            }
            
            for(int i = 0; i < n; i++) cout << dp[w + (L - 1) * (n - 1)][i] << " ";
            cout << endl;

            float avg = (float) sum(dp[w + (L - 1) * (n - 1)]) / (n - (w + 1));
            minAvg = min(minAvg, avg);
        }
    }

    // cout << minAvg << endl;
    fprintf(out,"%.3f", minAvg);
    fclose(inp);
    fclose(out);
    
    return 0;
}

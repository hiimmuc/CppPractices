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

const int N = 10001;
int n, a[N], b[N], F[2][N];
FILE *inp, *out;

int main() {
    inp = freopen("INP/P00.TXT", "r", stdin);
    out = freopen("OUT/P00.TXT", "w", stdout);

    fscanf(inp, "%d", &n);
    FOR(i,1,n) fscanf(inp, "%d%d", &a[i], &b[i]);

	// scanf("%d", &n);
	// FOR(i,1,n) scanf("%d%d", &a[i], &b[i]);

	F[1][1] = b[1];
	FOR(i,2,n) {
		int M = min(i,n/2), ii = i%2;
		F[ii][0] = F[1-ii][1] + a[i];
		F[ii][M] = F[1-ii][M-1] + b[i];
		FOR(j,1,M-1)
		F[ii][j] = min(F[1-ii][j-1] + b[i], F[1-ii][j+1] + a[i]);
	}
	// printf("%d\n", F[0][0]);

    fprintf(out, "%d\n", F[0][0]);
    fclose(inp);
    fclose(out);

	return 0;
}

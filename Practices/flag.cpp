#include "bits/stdc++.h"
#include <stdlib.h> 

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


using namespace std;


void drawFlags(int size){
    /*
    Description: This function draws the flag of Vietnam
    */
    int longEdge = size / 0.4 ; // scale depends on the terminal display size
    int shortEdge = 2 * size / 3;

    // cout<<longEdge<<" "<<shortEdge<<endl;

    // int outerRadius = size / 5;
    // int innerRadius = size / 10;
    // 
    FILE *inp;
    
    inp=freopen("./assets/Flag_of_Vietnam_cvt.txt", "r", stdin);

    FOR(i, 0, shortEdge){
        FOR(j, 0, longEdge){
            char c;
            cin >> c;
            if (c == '#') cout << "\033[31m" << c << "\033[0m"; // red
            else cout << "\033[33m" << c << "\033[0m"; // yellow
        }
        cout << endl;
    }
}

void exportFlags(int size){
    /*
    Description: This function exports the flag of Vietnam to a file
    */
    int longEdge = size / 0.4; // scale depends on the terminal display size
    int shortEdge = 2 * size / 3;

    
}


int main() {
    int size = 64;



    drawFlags(size);

    return 0;
}
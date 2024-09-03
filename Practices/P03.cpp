// smallest K digits number divisible by X
// C++ code to find smallest K-digit number
// divisible by X
#include "bits/stdc++.h"

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
 
// Function to compute the result
int answer(ll X, int K)
{   
    //check condition of X and K
    if (X > (int)1e15 || X < -1)    return -1;
    if (K > (int)1e5 || K < -1)     return -1;

    // Computing MIN
    int MIN = pow(10, K - 1);
    
    if (to_string(X).length() > to_string(MIN).length())    return -1; // if X is greater than 10^k
 
    // MIN is the result
    if (MIN % X == 0)
        return MIN;
 
    // returning ans
    return ((MIN + X) - ((MIN + X) % X));
}
 

// Driver Code
int main()
{
    bool debug = true;
    if(debug){
        int correct = 0;
        string inputFilename, outputFilename;


        for (int i = 1; i <= 50; i++) {
            ll X;
            int K;
            string S;

            if (i < 10){
                inputFilename = "./INP/P04/0" + to_string(i) + ".in";
                outputFilename = "./INP/P04/0" + to_string(i) + ".out";
            }
            else {
                inputFilename = "./INP/P04/" + to_string(i) + ".in";
                outputFilename = "./INP/P04/" + to_string(i) + ".out";
            }

            FILE *inp = freopen(inputFilename.c_str(), "r", stdin);
            fscanf(inp, "%d %llu", &K, &X);
            ifstream outputFile(outputFilename);
            getline(outputFile, S);
            
            int R = answer(X, K);

            cout << "Test " << "\t|Result: " 
            << (strcmp(to_string(R).c_str(), S.c_str()) == 0? "Correct" : "Incorrect") 
            << endl;

            if (strcmp(to_string(R).c_str(), S.c_str()) == 0) {
                correct++;
                
            } else {
                // cout << "Expected: " << S << endl;
                // cout << "Got: " << R << endl;
            }

            fclose(inp);
        }
        cout << "Correct: " << correct << "/50" << endl;
    }
    else{
        int X, K;
        cin >> K >> X;
        cout << answer(X, K) << endl;
    }
 
}
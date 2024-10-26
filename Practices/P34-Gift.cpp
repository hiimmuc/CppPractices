/** cSpell: ignore Vieoney thaovan
 * @file P34-Gift.cpp
 * @author Vieoney (thaovan.140902@gmail.com)
 * @brief Given a matrix  gifts (H x W) represents map of gifts. 
 *  --- if gifts[i][j] = ., it is an empty cell, treated as value 0. 
 *  --- if gifts[i][j] = *, it is a gift, treated as value 1.
 *  --- if gifts[i][j] = #, it is obstacle, treated as value -1.
 * First, you will travel from the top-left corner to the bottom-right corner.
 *  --- from each cell (i, j) you can move only to (i+1, j) or (i, j+1). And you need to avoid obstacles.
 *  Then, you will travel from the bottom-right corner to the top-left corner.
 *  --- from each cell (i, j) you can move only to (i-1, j) or (i, j-1), and you need to avoid obstacles.
 * Find the maximum number of gifts you can collect.
 * @version 0.1
 * @date 2024-10-26
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

// Function to calculate the maximum number of gifts collected
int maxGiftsCollected(int H, int W, vvi& grid) {
    // Initialize a 3D DP table: dp[x][y][t]
    vector<vvi> dp(H + 1, vvi(W + 1, vi(2, -1)));
    
    // Starting point with initial gift if present
    dp[1][1][0] = grid[0][0]; 

    // First pass: move from (1,1) to (H,W)
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (grid[i - 1][j - 1] == -1) continue; // Skip obstacles
            // Collect gifts while moving down or right
            if (i > 1 && dp[i - 1][j][0] != -1) 
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + grid[i - 1][j - 1]);
                // grid[i - 1][j - 1] = 0; // Collect gift at (i,j)
            if (j > 1 && dp[i][j - 1][0] != -1)
                dp[i][j][0] = max(dp[i][j][0], dp[i][j - 1][0] + grid[i - 1][j - 1]);
                // grid[i - 1][j - 1] = 0; // Collect gift at (i,j)
            // if (grid[i - 1][j - 1] == 1) grid[i - 1][j - 1] = 0; // Collect gift at (i,j)
        }
    }

    // Initialize the second pass starting point from (H,W)
    dp[H][W][1] = dp[H][W][0];

    // Second pass: move from (H,W) back to (1,1)
    for (int i = H; i >= 1; --i) {
        for (int j = W; j >= 1; --j) {
            if (grid[i - 1][j - 1] == -1) continue; // Skip obstacles
            // Collect gifts while moving up or left
            if (i < H && dp[i + 1][j][1] != -1)
                dp[i][j][1] = max(dp[i][j][1], dp[i + 1][j][1] + grid[i - 1][j - 1]);
            if (j < W && dp[i][j + 1][1] != -1)
                dp[i][j][1] = max(dp[i][j][1], dp[i][j + 1][1] + grid[i - 1][j - 1]);
            if (grid[i - 1][j - 1] == 1) grid[i -1][j - 1] = 0; // Collect gift at (i,j)
        }
    }

    // Result: maximum gifts collected at (1,1) after both passes
    return dp[1][1][1];
}

int main(){
    faster;
    FILE* file = freopen("INP/P34.TXT", "r", stdin);
    int H, W;
    cin >> H >> W;
    vvi grid(H, vi(W));
    FOR(i, 0, W) {
        FOR (j, 0, H) {
            char c;
            cin >> c;
            if (c == '.') grid[i][j] = 0;
            else if (c == '*') grid[i][j] = 1;
            else grid[i][j] = -1;
        }
    }
    // Output the maximum number of gifts collected
    cout << maxGiftsCollected(H, W, grid) << endl;
    return 0;
}

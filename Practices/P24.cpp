#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;

#define INF numeric_limits<ll>::max() 

#define FOR(i,start,end) for (int i = (start); i < (end); i++)
#define FOD(i,start,end) for (int i = (end); i > (start); i--)

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int minimumTransforms(int n, int h, const vector<int>& arr) {
    int min_operations = numeric_limits<int>::max();
    int current_operations = 0;
    
    // Initialize the operations needed for the first window
    for (int i = 0; i < h; ++i) {
        int target_value = i + 1; // Increasing sequence starts at 1
        if (arr[i] > target_value) {
            // If the current value is greater than the target, no feasible way to decrement
            return -1;
        }
        current_operations += target_value - arr[i];
    }

    min_operations = min(min_operations, current_operations);

    // Slide the window across the array
    for (int i = 1; i <= n - h; ++i) {
        // Remove the impact of the element going out of the window
        current_operations -= (i - 1 + h) - arr[i - 1];
        // Add the impact of the new element entering the window
        int new_index = i + h - 1;
        int new_target = h; // The last element in the increasing sequence
        if (arr[new_index] > new_target) {
            // If the current value is greater than the target, no feasible way to decrement
            return -1;
        }
        current_operations += new_target - arr[new_index];

        min_operations = min(min_operations, current_operations);
    }

    return (min_operations == numeric_limits<int>::max()) ? -1 : min_operations;
}

int old_sol(int n, int h, const vector<int>& arr) {
    vll prefix(n + 1, 0);
    int curr = 1;
    ll minVal = LLONG_MAX;

	for (int i = 1;i <= n;i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}
	for (int i = 1;i <= n;i++) {
		if (arr[i] <= curr) {
			curr = min(curr + 1, h);
			if (curr == h) minVal = min(minVal,(ll)h*(h + 1)/2 - (prefix[i] - prefix[i - h]));
		} else {
			curr = 1;
			while (arr[i] > 1 && i <= n) i++;
		}
	}
 
	if (minVal == LLONG_MAX) cout << -1;
	else cout << minVal;
}

int main() {
    faster;
    FILE* file = freopen("./INP/P24.TXT", "r", stdin);
    
    int n, h;
    cin >> n >> h;
    vector<int> arr(n);
    for (int& val : arr) cin >> val;

    int result = old_sol(n, h, arr);
    if (result == -1) {
        cout << "-1\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}


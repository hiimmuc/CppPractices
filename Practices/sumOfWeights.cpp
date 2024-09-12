#include "bits/stdc++.h"

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

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


//1 Function to calculate the sum of weights of all subarrays
int sumOfWeights1(const vector<int>& arr) {
    int n = arr.size();
    int totalWeight = 0;

    for (int i = 0; i < n; ++i) {
        int currentMax = arr[i];
        int currentMin = arr[i];
        
        for (int j = i; j < n; ++j) {
            currentMax = max(currentMax, arr[j]);
            currentMin = min(currentMin, arr[j]);
            totalWeight += (currentMax - currentMin);
        }
    }
    
    return totalWeight;
}

//2 using stack
// Function to calculate the sum of weights of all subarrays
int sumOfWeights2(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nextGreater(n, n), prevGreater(n, -1);
    vector<int> nextSmaller(n, n), prevSmaller(n, -1);
    stack<int> s;

    // Calculate next and previous greater elements
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            nextGreater[s.top()] = i;
            s.pop();
        }
        if (!s.empty()) prevGreater[i] = s.top();
        s.push(i);
    }
    
    s = stack<int>(); // Clear stack for next calculation

    // Calculate next and previous smaller elements
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            nextSmaller[s.top()] = i;
            s.pop();
        }
        if (!s.empty()) prevSmaller[i] = s.top();
        s.push(i);
    }

    int totalWeight = 0;

    // Calculate the contribution of each element as max and min
    for (int i = 0; i < n; ++i) {
        int maxContribution = (i - prevGreater[i]) * (nextGreater[i] - i);
        int minContribution = (i - prevSmaller[i]) * (nextSmaller[i] - i);
        totalWeight += arr[i] * (maxContribution - minContribution);
    }

    return totalWeight;
}

int main() {
    FILE *inp = freopen("INP/SOW.TXT", "r", stdin);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = sumOfWeights2(arr);
    cout << "Sum of weights of all subarrays: " << result << endl;
    return 0;
}
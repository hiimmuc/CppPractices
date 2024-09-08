/**
 * @file P10-KthSmallest.cpp (done)
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

#define INF 1e9

#define EL printf("\n")
#define sz(A) (int) A.size()

#define FOR(i,start,end) for (int i = start; i < end; i++)
#define FOD(i,start,end) for (int i = end; i > start; i--)

#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b
#define sum(a, start, end) accumulate(a + start, a + end, 0)

#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

// This function returns the kth smallest element in an array
int kthSmallest(int arr[], int n, int k) {
    // First, find the maximum element in the array
    int max_element = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    // Create an array to store the frequency of each 
   // element in the input array
    int freq[max_element + 1] = {0};
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Keep track of the cumulative frequency of elements 
   // in the input array
    int count = 0;
    for (int i = 0; i <= max_element; i++) {
        if (freq[i] != 0) {
            count += freq[i];
            if (count >= k) {
                // If we have seen k or more elements, 
              // return the current element
                return i;
            }
        }
    }
    return -1;
}

// Driver Code
int main() {
    int T, K, N;
    int arr[1000];
    cin >> T;

    FOR(i, 0, T){
        // Input the number of elements in the array and the value of k
        cin >> N;
        FOR(j, 0, N){
            cin >> arr[j];
        }
        cin >> K;
        // Function call
        cout << kthSmallest(arr, N, K) << endl;
    }
    
    return 0;
}
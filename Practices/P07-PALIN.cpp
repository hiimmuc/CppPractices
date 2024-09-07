/**
 * @file P07-PALIN.cpp  (Practices/P07-PALIN.cpp)
 * @author Vit hoc bai (thaovan.140902@gmail.com)
 * @brief Palindrome problem: Given a string S, and q queries, each query is a pair of integers (start, end). 
 * |S| <= 10^5, 1 <= q <= 10^5, 1 <= start <= end <= |S|; 
 * 1s time limit, 128MB memory limit
 * @version 0.1
 * @date 2024-09-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <chrono>
#include <cstring>
#include <cstdint>

using namespace std;
using namespace std::chrono;

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

// bool palindrome(string s){
//     int left = 0, right = s.length() - 1; 
//     while (left < right) { 
//         if (s[left] != s[right]) { 
//             return false; 
//         } 
//         left++; 
//         right--; 
//     } 
//     return true; 
// }


// bool isPalindrome(const std::string &str)
// {
//     // std::equal(str.begin(), str.begin()+str.size()/2, str.rbegin(), str.rbegin()+str.size()/2);

//   auto itStop = str.begin() + str.size() / 2;
//   auto itBegin = str.begin();
//   auto itReverse = str.rbegin();
//   while (itBegin != itStop) {
//     if (*itBegin != *itReverse)
//       return false;
//     else {
//       itBegin++;
//       itReverse++;
//     }
//   }

//   return true;

// }


bool IsPalindrome(const string& str)
{
    const size_t N = str.size();
    const size_t N_half = N / 2;
    for(size_t i=0; i<N_half; i++)
    {
        if( str[i] != str[N-1-i])
        {
            return false;
        }
    }
    return true;
}

inline uint32_t swap(const uint32_t& val)
{
  union {
    char c[4];
    uint32_t n;
  } data;
  data.n = val;
  std::swap(data.c[0], data.c[3]);
  std::swap(data.c[1], data.c[2]);
  return data.n;
}

inline bool IsPalindromeWord(const std::string& str)
{
    const size_t N = str.size();
    const size_t N_half = (N/2);
    const size_t S = sizeof(uint32_t);
    // number of words of size S in N_half
    const size_t N_words = (N_half / S);

    // example: if N = 18, half string is 9 bytes and
    // we need to compare 2 pairs of words and 1 pair of chars

    size_t index = 0;

    for(size_t i=0; i<N_words; i++)
    {
        uint32_t word_left, word_right;
        memcpy(&word_left, &str[index], S);
        memcpy(&word_right, &str[N - S - index], S);

        if( word_left != swap(word_right))
        {
            return false;
        }
        index += S;
    }
    // remaining bytes.
    while(index < N_half)
    {
        if( str[index] != str[N-1-index])
        {
            return false;
        }
        index++;
    }
    return true;
}



int main () {
    faster;
    bool debug = true;
    // Get starting timepoint
    auto start = high_resolution_clock::now();
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
        // use dp to store the result of each query, with from i,j, i++ , j-- util i = j
        // then if the next query is inside, we can return True, for example, 
        // if 1-5 is palindrome, then 2-4 is also palindrome

        FOR(i, 0, q){
            int start, end;
            cin >> start >> end;
            if(IsPalindromeWord(S.substr(start - 1, end - start + 1))){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
  
        }
         
        // // Get ending timepoint
        auto stop = high_resolution_clock::now();
    
        // Get duration. Substart timepoints to 
        // get duration. To cast it to proper unit
        // use duration cast method
        auto duration = duration_cast<microseconds>(stop - start);
    
        cout << "Time taken by function: "
            << duration.count() << " microseconds" << endl;
    
    }
    else{
        int q;
        string S;
        cin >> S;
        cin >> q;

        FOR(i, 0, q){
            int start, end;
            cin >> start >> end;
            if(IsPalindrome(S.substr(start - 1, end - start + 1))){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
  
        }
    }
    return 0;
}
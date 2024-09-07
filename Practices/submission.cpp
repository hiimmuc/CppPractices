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
#include <cstring>
#include <cstdint>

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

typedef long long ll;
typedef unsigned long long ull;

inline uint32_t Swap(const uint32_t& val)
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

inline bool IsPalindrome(const std::string& str)
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

        if( word_left != Swap(word_right))
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
    faster;
    
    int q;
    string S;
    cin >> S;
    cin >> q;

    for(int i = 0; i < q; i++){
        int start, end;
        cin >> start >> end;
        if(IsPalindrome(S.substr(start - 1, end - start + 1))){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
    return 0;
}
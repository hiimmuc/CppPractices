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

#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

bool palindrome(string s){
    int left = 0, right = s.length() - 1; 
    while (left < right) { 
        if (s[left] != s[right]) { 
            return false; 
        } 
        left++; 
        right--; 
    } 
    return true; 
}


bool isPalindrome(const std::string &str)
{
    // std::equal(str.begin(), str.begin()+str.size()/2, str.rbegin(), str.rbegin()+str.size()/2);

  auto itStop = str.begin() + str.size() / 2;
  auto itBegin = str.begin();
  auto itReverse = str.rbegin();
  while (itBegin != itStop) {
    if (*itBegin != *itReverse)
      return false;
    else {
      itBegin++;
      itReverse++;
    }
  }

  return true;

}

int main () {
    faster;
    bool debug = true;
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

        FOR(i, 0, q){
            int start, end;
            cin >> start >> end;
            if(isPalindrome(S.substr(start - 1, end - start + 1))){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
  
        }
    }
    else{
        int q;
        string S;
        cin >> S;
        cin >> q;

        FOR(i, 0, q){
            int start, end;
            cin >> start >> end;
            if(isPalindrome(S.substr(start - 1, end - start + 1))){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
  
        }
    }
    return 0;
}
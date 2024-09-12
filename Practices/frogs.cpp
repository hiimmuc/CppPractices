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

int MAX_N = 1e6;

vector<int> solution(const vector<int>& heights, const vector<int>& jumps) {
    int n = heights.size();
    vector<int> result(n, -1);

    for (int i = 0; i < n; ++i) {
        stack<int> s; s.push(-1);

        int current_height = heights[i]; 

        for (int j = i + 1; j < n && s.size() <= jumps[i]; ++j) {
            if (heights[j] > current_height) current_height =  heights[j]; s.push(heights[j]);
        }

        if (s.size() <= jumps[i]) result[i] = -1;
        else result[i] = s.top();
    }
    return result;
}

vector<int> solution2(const vector<int>& heights, const vector<int>& max_jumps) {
    int n = heights.size();
    vector<int> result(n, -1);  // Khởi tạo kết quả với -1 cho các ếch không nhảy được
    vector<int> jumps(n, 0);    // Số bước nhảy của mỗi con ếch
    
    stack<int> STACK1, STACK2;  // STACK1 lưu chỉ số theo chiều cao tăng dần, STACK2 lưu ếch đang nhảy
    
    for (int i = 0; i < n; ++i) {
        // Xử lý ếch trong STACK2 có thể nhảy tới vị trí i
        while (!STACK2.empty() && heights[i] > heights[STACK2.top()]) {
            int frogIndex = STACK2.top();
            STACK2.pop();
            // Tăng số bước nhảy của ếch
            jumps[frogIndex]++;
            
            // Nếu ếch hoàn thành số bước nhảy
            if (jumps[frogIndex] >= max_jumps[frogIndex]) {
                result[frogIndex] = heights[i];  // Cập nhật chiều cao của ếch tại bãi rác hiện tại
            }
        }

        // Xử lý STACK1 để kiểm tra các ếch có thể nhảy tới vị trí i
        while (!STACK1.empty() && heights[i] > heights[STACK1.top()]) {
            int frogIndex = STACK1.top();
            STACK1.pop();
            // Tăng số bước nhảy của ếch
            jumps[frogIndex]++;
            
            // Nếu ếch hoàn thành số bước nhảy
            if (jumps[frogIndex] >= max_jumps[frogIndex]) {
                result[frogIndex] = heights[i];  // Cập nhật chiều cao của ếch tại bãi rác hiện tại
            } else {
                STACK2.push(frogIndex);  // Đưa ếch vào STACK2 nếu chưa hoàn thành
            }
        }

        // Nếu không có ếch nào nhảy được đến bãi rác hiện tại, thêm nó vào STACK1
        if (STACK1.empty() || heights[i] <= heights[STACK1.top()]) {
            STACK1.push(i);
        }
    }

    return result;
}


int main() {
    faster;

    FILE *inp;
    inp=freopen("./INP/FROGS.TXT", "r", stdin);

    int n;
    vector<int> heights(MAX_N);
    vector<int> jumps(MAX_N);

    // inputs
    cin >> n;
    FOR(i, 0, n) cin >> heights[i];
    FOR(i, 0, n) cin >> jumps[i];

    // solve
    vector<int> outputs = solution2(heights, jumps);
    //
    FOR(i, 0, n) cout << outputs[i] << " ";
    //
    return 0;
}
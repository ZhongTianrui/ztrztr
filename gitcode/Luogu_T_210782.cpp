#include <bits/stdc++.h>

using namespace std;
/*
*/
int dp[100005], n, V, v, w;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> V;
    
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> v >> w;
        for (int j = 10000; j >= w; j --) {
            dp[j] = min(dp[j], dp[j - w] + v);
        }
    }
    for (int j = 10000; j >= 0; j --) {
        if (dp[j] <= V) {
            cout << j;
            break;
        }
    }
    return 0;
}
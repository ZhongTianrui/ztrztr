#include <bits/stdc++.h>

using namespace std;
/*
*/
int dp[105][105], n, m;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    dp[1][1] = 1;
    for (int j = 2; j <= m; j ++) {
        for (int i = 1; i <= m; i ++) {
            for (int k = 1; k <= n; k ++) {
                if (k != i) dp[i][j] += dp[k][j - 1];
            }
        }
    }
    cout << dp[1][m];
    return 0;
}
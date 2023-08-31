#include <bits/stdc++.h>

using namespace std;
/*
*/
#define int long long
signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, dp[205][205] = {0};
    cin >> n >> m;
    int a[1005] = {}, b[1005] = {};
    for (int i = 1; i <= m; i ++) cin >> a[i] >> b[i];
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) {
            for (int k = 0; k <= j; k ++) {
                int ans = a[i] * pow(k, b[i]);
                if (dp[i][j] == 0 or i == 1) dp[i][j] = dp[i - 1][j - k] + ans;
                else dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + ans);
            }
        }
    }
    cout << dp[m][n];
    return 0;
}
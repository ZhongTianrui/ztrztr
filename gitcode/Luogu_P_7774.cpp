    #include <bits/stdc++.h>

    using namespace std;
    /*
    dp[i] = i 能不能被取到
    */
    int main() {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int n, m, a[10005], b[10005], dp[10005];
        cin >> n >> m;
        dp[0] = 1;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        for (int i = 1; i <= m; i ++) cin >> b[i];
        for (int i = 1; i <= n; i ++) {
            for (int j = a[i]; j <= 1001; j ++) {
                dp[j % 360] = max(dp[j % 360], dp[(j - a[i]) % 360]);
                dp[j % 360] = max(dp[j % 360], dp[(j + a[i]) % 360]);
            }
        }
        for (int i = 1; i <= m; i ++) cout << (dp[b[i]] == 1 ? "YES\n" : "NO\n");
        return 0;
    }
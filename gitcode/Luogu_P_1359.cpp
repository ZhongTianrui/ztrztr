#include <bits/stdc++.h>

using namespace std;
/*
*/
int a[1005][1005], dp[100005], n;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 2; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            dp[i] = (!dp[j] ? dp[j] + a[j][i] : min(dp[i], dp[j] + a[j][i]));
        }
    }
    cout << dp[n];
    return 0;
}
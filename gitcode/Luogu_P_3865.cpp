#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, a[100005], dp[100005][20];
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        dp[i][0] = a[i];
    }
    for (int i = 1; i <= 16; i ++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j ++) {
            dp[j][i] = max(dp[j][i], dp[j + 1 << (i - 1)][i - 1]);
        }
    }
    while (m --) {
        int x, y; cin >> x >> y;
        int tmp = __lg(y - x + 1);
        cout << max(dp[tmp][x], dp[tmp][y - (1 << tmp) + 1]) << "\n";
    }
    return 0;
}
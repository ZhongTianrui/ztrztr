#include <bits/stdc++.h>

using namespace std;
/*
dp[i][j] = 前i本书选取j本的最小不整齐度 
*/
int n, k, dp[1005][1005];
struct node {
    int h, w;
} a[100005];
bool cmp(node x, node y) {
    return x.h < y.h;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].h >> a[i].w;
    }
    memset(dp, 20, sizeof(dp));
    int m = n - k;
    sort(a + 1, a + n + 1, cmp);
    //init
    for (int i = 1; i <= n; i ++) {
        dp[i][1] = 0;
    }
    for (int i = 2; i <= n; i ++) {
        for (int j = 1; j <= i - 1; j ++) {
            for (int k = 2; k <= min(m, i); k ++) {
                dp[i][k] = min(dp[i][k], dp[j][k - 1] + abs(a[i].w - a[j].w));
            }
        }
    }
    int ans = 0x7fffffff;
    for (int i = m; i <= n; i ++) {
        ans = min(ans, dp[i][m]);
    }
    cout << ans;
    return 0;
}
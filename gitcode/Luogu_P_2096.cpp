#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, m, a[101][20002], dis[20002], maxn = -1e9;
int fun() {
    int ans = 0;
    for (int i = 1; i <= m; i ++) {
        ans += dis[i];
        if (ans < 0) ans = 0;
        else maxn = max(ans, maxn);
    }
    return maxn;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) cin >> a[i][j];
    }
    for (int i = 1; i <= m; i ++) {
        dis[i] = -1e9;
        for (int j = 1; j <= n; j ++) {
            dis[i] = max(dis[i], a[j][i]);
        }
    }
    cout << fun();
    return 0;
}
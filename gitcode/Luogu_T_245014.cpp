#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, m, dp[1005][1005], M;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> M;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            dp[i][j] = 0x7fffffff;
        }
    }
    //init
    for (int i = 1; i <= m; i ++) {
        int x, y, z; cin >> x >> y >> z;
        dp[x][y] = z;
    }
    //input
    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                dp[i][j] = min(max(dp[i][k], dp[k][j]), dp[i][j]);
                //dp
            }
        }
    }
    while (M --) {
        int x; int y; cin >> x >> y;
        if (dp[x][y] == 0x7fffffff) cout << "-1\n";
        else cout << dp[x][y] << "\n";
    }
    //output
    return 0;
}
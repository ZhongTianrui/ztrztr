#include <bits/stdc++.h>

using namespace std;
/*

*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int V, n;
    cin >> V >> n;
    vector <int> a[1005], b[1005];
    set <int> cnt;
    int dp[100005];
    for (int i = 1; i <= n; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[z].push_back(x);
        b[z].push_back(y);
        cnt.insert(z);
    }
    for (int i = 1; i <= cnt.size(); i ++) {
        for (int k = V; k > 0; k --) {
            for (int j = 1; j <= a[i].size(); j ++) {
                if (j >= a[i][j]) dp[k] = max(dp[k], dp[k - a[i][j]] + b[i][j]);
            }
        } 
    }
    cout << dp[V];
    return 0;
}
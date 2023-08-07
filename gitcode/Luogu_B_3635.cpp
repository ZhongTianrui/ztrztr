#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int w[1005] = {0, 1, 5, 11}, dp[10005];
    for (int i = 1; i <= 3; i ++) {
        for (int j = w[i]; j <= n; j ++) {
            dp[j] = max(dp[j], dp[j - w[i]] + 1);
        }
    }
    cout << dp[n];
    return 0;
}
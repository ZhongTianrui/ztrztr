#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, V; cin >> n;
    int a[100005], dp[100005] = {0};
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        V += a[i];
    }
    V = V / 2;
    for (int i = 1; i <= n; i ++) {
        for (int j = V; j >= a[i]; j --) {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    cout << dp[V];
    return 0;
}
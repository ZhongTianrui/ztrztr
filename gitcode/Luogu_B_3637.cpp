#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, a[100005], maxn, dp[100005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        if (a[i + 1] > a[i]) {
            dp[i] = max(dp[i - 1], dp[i - 1] + 1)
        }
    }
    cout << maxn;
    return 0;
}
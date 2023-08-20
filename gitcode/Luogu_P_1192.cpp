#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, k, dp[100005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    dp[1] = 1;
    dp[0] = 1;
    for (int i = 2; i <= n; i ++) {
        for (int j = 1; j <= k; j ++) {
            if (i >= j) dp[i] = (dp[i] + dp[i - j]) % 100003; 
        }
    }
    cout << dp[n];
    return 0;
}
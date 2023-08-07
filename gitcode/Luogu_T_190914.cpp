#include <bits/stdc++.h>

using namespace std;
/*
*/
int sum[1005], dp[1005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int S; cin >> S;
    for (int i = 1; i <= S / 2; i ++) {
        for (int j = 2; j * i <= S; j ++) {
            sum[i * j] += i;
        }
    }
    for (int i = 1; i <= S; i ++) {
        for (int j = i; j <= S; j ++) {
            dp[j] = max(dp[j], dp[j - i] + sum[i]);
        }
    }
    cout << dp[S];
    return 0;
}
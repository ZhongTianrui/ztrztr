#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	//输入
	int n, dp[1005] = {0, 1, 2}; cin >> n;
    for (int i = 3; i <= n; i ++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
	return 0;
}
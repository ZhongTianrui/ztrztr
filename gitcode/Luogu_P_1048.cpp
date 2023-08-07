#include <bits/stdc++.h>

using namespace std;
/*
*/
int Ans = 0;
int n, V, a[100005], v[100005], w[100005];
int dfs(int nw, int lft) {
    if (nw == n + 1) {
        return 0;
    } 
    int cnt1 = 0, cnt2 = -114514;
    cnt1 = dfs(nw + 1, lft);
    if (lft >= w[nw]) cnt2 = dfs(nw + 1, lft - w[nw]) + v[nw];
    return max(cnt1, cnt2);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> V >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> w[i] >> v[i];
    }
    cout << dfs(1, V);
    return 0;
}
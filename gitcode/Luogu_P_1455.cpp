#include <bits/stdc++.h>

using namespace std;
/*
*/
int f[1000005], n, m, w, c[100005], d[100005], dp[100005];
set <int> st;
void init() {
    for (int i = 1; i <= n; i ++) {
        f[i] = i;
    }
}
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y) {
    f[find(x)] = find(y);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> w;
    init();
    for (int i = 1; i <= n; i ++) {
        cin >> c[i] >> d[i];
    }
    for (int i = 1; i <= m; i ++) {
        int x, y; cin >> x >> y;
        merge(x, y);
    }
    for (int i = 1; i <= n; i ++) {
        if (f[i] != i) {
            d[find(i)] += d[i];
            c[find(i)] += c[i];
            d[i] = c[i] = 0;
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = w; j >= c[i]; j --) {
            dp[j] = max(dp[j], dp[j - c[i]] + d[i]);
        }
    }
    cout << dp[w];
    return 0;
}
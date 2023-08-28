#include <bits/stdc++.h>

using namespace std;
/*
*/
#define int long long
int n, m, x, y, a[1000005];

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    while (m --) {
        int x, y; cin >> x >> y;
        if (x < 1 || x > n) continue;
        a[x] -= y;
    }
    for (int i = 1; i <= n; i ++) cout << a[i] << " ";
    return 0;
}
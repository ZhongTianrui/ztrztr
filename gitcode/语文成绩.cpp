#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, m, a[5000005], cf[5000005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        cf[i] += a[i];
        cf[i + 1] -= a[i];
    }
    for (int i = 1; i <= m; i ++) {
        int x, y, z; cin >> x >> y >> z;
        cf[x] += z;
        cf[y + 1] -= z;
    }
    for (int i = 1; i <= n; i ++) {
        cf[i] += cf[i - 1];
    }
    int minn = 1e9;
    for (int i = 1; i <= n; i ++) {
        minn = min(minn, cf[i]);
    }
    cout << minn;
    return 0;
}
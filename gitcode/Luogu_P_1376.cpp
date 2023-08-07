#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, m;
    cin >> n >> m;
    long long ans = 0, minn;
    for (int i = 1; i <= n; i ++) {
        long long x, y; cin >> x >> y;

        if (i == 1) minn = x;
        minn = min(minn + m, x);
        ans += y * minn;
    }
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
/*
*/
typedef long long ll;
ll l, n, m, a[1000005], ans;
bool check(int x) {
    ll fi = 0, ans = 0;
    for (int i = 1; i <= n + 1; i ++) {
        if (a[i] - a[fi] < x) ans ++;
        else fi = i;
    }
    return ans <= m;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int ll = 1, r = l;
    a[n + 1] = l;
    sort(a + 1, a + n + 1);
    while (ll <= r) {
        int mid = (ll + r) / 2;
        if (check(mid)) ans = mid, ll = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
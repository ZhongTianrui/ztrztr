#include <bits/stdc++.h>

using namespace std;
/*
*/
typedef long long ll;
ll n;
ll a[1000005], b[1000005];
bool check(ll x) {
    ll maxn = a[1] + b[1] + x;
    for (int i = 1; i < n; i ++) {
        if (a[i + 1] > maxn) return false;
        else maxn = max(maxn, a[i + 1] + b[i + 1] + x);
    }
    return true;
}
ll ans(ll l) {
    if (check(l - 1) and l - 1 >= 0) return l - 1;
    else if (check(l) and l >= 0) return l;
    else return l + 1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i];
    }
    ll l = 0, r = 2e9;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << ans(l);
    return 0;
}
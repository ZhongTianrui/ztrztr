#include <bits/stdc++.h>

using namespace std;
/*
*/
int a[1000005];
int n, m;
bool check(int x) {
    int la = 1, ans = 1;
    for (int i = 2; i <= n; i ++) {
        if (a[i] - la >= x) {
            la = a[i];
            ans ++;
        }
    }
    if (ans >= x) {
        return true;
    } else {
        return false;
    }
}
int erfen() {
    int l = 0, r = 1e9;
    int anss = -1;
    int mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid)) {
            anss = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return anss;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + n + 1);
    cout << erfen();
    return 0;
}
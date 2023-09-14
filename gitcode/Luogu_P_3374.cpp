#include <bits/stdc++.h>

using namespace std;
/*
*/
#define int long long 
int a[1000005], pre[1000005], n, m;
int lowbit(int x) {
    return ((-x) & x);
}
void update(int nw, int x) {
    for (int i = nw; i <= n; i += lowbit(i)) {
        pre[i] += x;
    }
}
int sum(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += pre[i];
    return ans;
}
int fun(int l, int r) {
    return sum(r) - sum(l - 1); 
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i], update(i, a[i]);
    while (m --) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            update(x, y);
        } else {
            int x, y; cin >> x >> y;
            cout << fun(x, y) << "\n";
        }
    }
    return 0;
}   
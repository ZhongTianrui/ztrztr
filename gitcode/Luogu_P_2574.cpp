#include <bits/stdc++.h>

using namespace std;
/*
*/
#define int long long
int st[1000005], n, m, mark[1000005], a[1000005];
void pushdown(int x, int len) {
    mark[x * 2] ^= mark[x];
    mark[x * 2 + 1] ^= mark[x];
    st[x * 2] ^= mark[x] * (len - len / 2);
    st[x * 2 + 1] += mark[x] * (len / 2);
    mark[x] = 0;
}
void build(int l, int r, int x) {
    if (l == r) {
        st[x] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, x * 2);
    build(mid + 1, r, n * 2 + 1);
    st[x] = st[x * 2] + st[x * 2 + 1];
}
void add(int l, int r, int ll, int rr, int nw, int x) {
    if (ll > r || rr < l) return;
    if (ll >= l && rr <= r) {
        st[nw] += x * (r - l + 1);
        if (rr > ll) mark[nw] += x;
        return;
    }
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return 0;
}
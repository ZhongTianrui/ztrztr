#include <bits/stdc++.h>

using namespace std;
/*
*/
int f[100005], n, m, cnt, maxn;
struct node{
    int f, t, d;
} a[100005];
bool cmp(node x, node y) {
    return x.d < y.d;
}
int find(int x) {
    return (f[x] == x ? x : f[x] = find(f[x]));
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i ++) {
        cin >> a[i].f >> a[i].t >> a[i].d;
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i ++) {
        int x = a[i].f, y = a[i].t;
        x = find(x);
        y = find(y);
        if (x == y) continue;
        f[x] = y;
        cnt ++;
        maxn = max(maxn, a[i].d);
        if (cnt > n) break;
    }
    cout << maxn;
    return 0;
}
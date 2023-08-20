#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, m, cnt, ans, f[100005];
struct edge{
    int f, t, v;
} a[1000005];
bool cmp(edge x, edge y) {
    return x.v < y.v;
}
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        cin >> a[i].f >> a[i].t >> a[i].v;
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i ++) {
        if (find(a[i].f) == find(a[i].t)) continue;
        if (cnt > n) break;
        f[find(a[i].f)] = find(a[i].t);
        ans += a[i].v;
        cnt ++;
    }
    if (cnt >= n - 1) cout << ans;
    else cout << "orz";
    return 0;
}
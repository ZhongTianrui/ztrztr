#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, m, f[1000005], cnt, ans;
struct node{
    int f, t, v;
} e[1000005];
bool cmp(node x, node y) {
    return x.v < y.v;
}
int find(int x) {
    if (f[x] == x) return x;
    else return f[x] = find(f[x]);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        cin >> e[i].f >> e[i].t >> e[i].v;
    }
    sort(e + 1, e + n + 1, cmp);
    for (int i = 1; i <= m; i ++) {
        int fx = find(e[i].f), fy = find(e[i].t);
        if (fx == fy) {
            continue;
        }
        f[fx] = fy;
        cnt ++;
        if (cnt > n) break;
        ans = max(ans, e[i].v);
    }
    cout << cnt << " " << ans;
    return 0;
}
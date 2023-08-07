#include <bits/stdc++.h>

using namespace std;
/*
贪心+图论+并查集
*/
int n, m, f[100005], cnt;
struct node{
    int from, to, data;
} a[1000005];
bool cmp(node x, node y) {
    return x.data < y.data;
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
        int x, y, z; cin >> x >> y >> z;
        a[i].from = x;
        a[i].to = y;
        a[i].data = z;
    }
    int ans = 0;
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i ++) {
        // cout << a[i].data << ' ' << ans << " " << cnt << "\n";
        int x = a[i].from, y = a[i].to;
        x = find(x);
        y = find(y);
        // cout << x << " " << y << "\n";
        if (x == y) continue;
        f[x] = y;
        cnt ++;
        if (cnt > n) break;
        ans += a[i].data;
    }
    if (cnt >= n - 1) cout << ans;
    else cout << "orz";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
/*
*/
long long n, m, u[1000005], v[1000005], c[1000005], d[1000005], ans = -1e9;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        cin >> u[i] >> v[i] >> c[i];
        if (c[i] < 0) continue;
        d[u[i]] += c[i];
        d[v[i]] += c[i];
    }
    for (int i = 1; i <= m; i ++) {
        if (c[i] > 0) ans = max(ans, d[u[i]] + d[v[i]] - c[i]);
        else ans = max(ans, d[u[i]] + d[v[i]] + c[i]);
    }
    cout << ans;
    return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;
int n, m;
int f[1000005];
long long ans;
bool flag[1000005];
vector <int> e[1000005], v[1000005];
int find(int x) {
    if (f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}
struct node2{
    int sum, ii;
} cnt[1000005];
struct node{
    int f, t, va;
} edge[1000005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i ++) {
        cin >> edge[i].f >> edge[i].t >> edge[i].va;
        f[find(edge[i].f)] = find(edge[i].t);
    }
    long long maxn = -3e9, fl = 0;
    for (int i = 1; i <= n; i ++) {
        cnt[f[i]].sum ++;
        cnt[f[i]].ii = f[i];
    }
    for (int i = 1; i <= n; i ++) {
        if (cnt[i].sum > maxn) {
            maxn = cnt[i].sum;
            fl = i;
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (f[i] == fl) {
            cout << i << " ";
            flag[i] = 1;
        }
    }
    for (int i = 1; i <= m; i ++) {
        if (flag[i]) {
            ans += edge[i].va;
        }
    }
    cout << "\n" << fl;
    return 0;
}*/
/*
#include <bits/stdc++.h>

using namespace std;
int n, m;
long long ans[1000005], f[1000005];
vector <int> e[1000005], v[1000005];
int find(int x) {
    if (f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}
struct node{
    int f, t;
} edge[1000005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i ++) {
        int x, y, z; cin >> x >> y >> z;
        e[x].push_back(y);
        v[x].push_back(z);
        e[y].push_back(x);
        v[y].push_back(z);
        f[find(x)] = find(y);
    }
    for (int i = 1; i <= n; i ++) {

    }
    return 0;
}
*/
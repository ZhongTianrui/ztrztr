#include <bits/stdc++.h>

using namespace std;
/*
贪心+图论+并查集
*/
int n, m, dis[100005], cnt, vis[100005], nw = 1, ans;
vector <int> e[100005], v[100005];
int mp[5001][5001];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(mp, 0x7f, sizeof(mp));
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int x, y, z; cin >> x >> y >> z;
        if (z < mp[x][y]) {
            e[x].push_back(y);
            v[x].push_back(z);
            e[y].push_back(x);
            v[y].push_back(z);
            mp[x][y] = mp[y][x] = z;
        }
    }
    int tot = 0;
    for (int i = 2; i <= n; i ++) dis[i] = 0x7fffffff;
    for (int i = 0; i < e[1].size(); i ++) {
        int nv = v[1][i], ne = e[1][i];
        dis[e[1][i]] = min(dis[e[1][i]], v[1][i]);
    }
    while (++ tot < n) {
        int minn = 0x7fffffff;
        vis[nw] = 1;
        for (int i = 1; i <= n; i ++) {
            if (vis[i] == 0 and minn > dis[i]) {
                minn = dis[i];
                nw = i;
            }
        }
        ans += minn;
        cnt ++;
        for (int i = 0; i < e[nw].size(); i ++) {
            if (dis[e[nw][i]] > v[nw][i] and vis[e[nw][i]] == 0) {
                dis[e[nw][i]] = v[nw][i];
            }
        }
    }
    if (cnt == n - 1) cout << ans;
    else cout << "orz";
    return 0;
}
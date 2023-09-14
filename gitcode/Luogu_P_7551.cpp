#include <bits/stdc++.h>

using namespace std;
/*
多轮 dijkstra
*/
#define int long long
#define inf 0x7fffffff
map <string, int> mp;
int top = 0;
int n, m;
#define MAXN 1005
vector <int> e[MAXN], v[MAXN];
struct node {
    int nw, v;
    bool operator < (const node &y) const {
        return v > y.v;
    }
};
int dij(int s, int t) {
    priority_queue <node> q;
    int dis[MAXN];
    memset(dis, 0x7f, sizeof(dis));
    dis[s] = 0;
    q.push((node){s, 0});
    while (q.size()) {
        int nw = q.top().nw;
        q.pop();
        for (int i = 0; i < e[nw].size(); i ++) {
            int t = e[nw][i];
            if (dis[t] > dis[nw] + v[nw][i]) {
                dis[t] = dis[nw] + v[nw][i];
                q.push((node){t, dis[t]});
            }
        }
    }
    return dis[t];
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        string xx, yy;
        int z;
        cin >> xx >> yy >> z;
        if (mp[xx] == 0) mp[xx] = ++top;
        if (mp[yy] == 0) mp[yy] = ++top;
        int x = mp[xx];
        int y = mp[yy];
        e[x].push_back(y);
        v[x].push_back(z);
    }
    int T;
    cin >> T;
    while (T --) {
        string s, t;
        cin >> s >> t;
        int ans = dij(mp[s], mp[t]);
        if (ans < inf) cout << ans << "\n";
        else cout << "Roger\n";
    }
    return 0;
}
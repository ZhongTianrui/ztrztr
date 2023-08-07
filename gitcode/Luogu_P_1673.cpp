#include <bits/stdc++.h>

using namespace std;
/*
*/
struct node {
    int dis, pos;
    bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};
bool cmp(node x, node y) {
    return x.dis < y.dis;
}
bool vis[100005];
priority_queue <node> pq;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, s;
    vector <int> u[100005], w[100005];
    cin >> n >> m;
    s = 1;
    for (int i = 1; i <= m; i ++) {
        int x, y, z; cin >> x >> y; 
        z = 1;
        u[x].push_back(y);
        w[x].push_back(z);
    }
    int dis[100005] = {};
    for(int i = 1; i <= n; ++i)dis[i] = 0x7fffffff;
    dis[s] = 0;
    pq.push((node){0, s});
    while (!pq.empty()) {
        node nw = pq.top();
        pq.pop();
        int xx = nw.pos, diss = nw.dis;
        if (vis[xx]) continue;
        vis[xx] = 1;
        for (int i = 0; i < u[xx].size(); i ++) {
            int yy = u[xx][i];
            if (dis[yy] > dis[xx] + w[xx][i]) {
                dis[yy] = dis[xx] + w[xx][i];
                if (vis[yy] == 0) {
                    
                    pq.push((node){dis[yy], yy});
                } 
            }
        }
    }
    cout << dis[n];
    return 0;
}
//pip install pynput
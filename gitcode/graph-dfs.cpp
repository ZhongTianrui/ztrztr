#include <bits/stdc++.h>

using namespace std;
/*
*/
vector <int> e[100005], v[100005];
int n, m, vis[100005], s, t, ans = 0x7fffffff;
void DFS(int nw, int sum) {
    if (nw > n) return;
    if (nw == t) {
        ans = min(ans, sum);
        vis[nw] = 0;
        return;
    }
    for (int i = 0; i < e[nw].size(); i ++) {
        if (vis[e[nw][i]] == 0) vis[e[nw][i]] = 1, DFS(e[nw][i], sum + v[nw][i]);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i ++) {
        int x, y, z; cin >> x >> y >> z;
        e[x].push_back(y);
        v[x].push_back(z);
    }
    DFS(s, 0);
    cout << ans;
    return 0;
}
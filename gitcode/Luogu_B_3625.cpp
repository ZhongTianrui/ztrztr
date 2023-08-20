#include <bits/stdc++.h>

using namespace std;
/*
bfs 学习
*/
int n, m, vis[1005][1005];
char a[1005][1005];
struct node{
    int x, y;
};
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) cin >> a[i][j];
    }
    queue <node> q;
    q.push((node){1, 1});
    while (q.size()) {
        int i, j;
        i = q.front().x;
        j = q.front().y;
        q.pop();
        if (vis[i][j]) continue;
        vis[i][j] = 1;
        if (i >= 1 && i <= n && j >= 1 && j <= m && a[i + 1][j] == '.') q.push((node){i + 1, j});
        if (i >= 1 && i <= n && j >= 1 && j <= m && a[i][j + 1] == '.') q.push((node){i, j + 1});
        if (i >= 1 && i <= n && j >= 1 && j <= m && a[i - 1][j] == '.') q.push((node){i - 1, j});
        if (i >= 1 && i <= n && j >= 1 && j <= m && a[i][j - 1] == '.') q.push((node){i, j - 1});
        if (i == n && j == m) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
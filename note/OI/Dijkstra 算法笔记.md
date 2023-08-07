# Dijkstra 算法笔记

dijkstra，一种通用的最短路算法。

## 思路

1. 将dis数组除了 s 初始化为 inf。
2. 提取出队头，标记，并将所有合法的连接入队。
3. 重复 `2` 直到队列为空（全部已经标记）
4. 输出。

代码：

```cpp
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
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i ++) {
        int x, y, z; cin >> x >> y >> z;
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
    for (int i = 1; i <= n; i ++) {
        cout << dis[i] << " ";
    }
    return 0;
}
```


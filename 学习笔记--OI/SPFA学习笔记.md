# SPFA学习笔记

> SPFA，他死了！——某次 noi T1 的出题人。

感觉和 DIJ 很像。

使用范围：负边权，判断负环，随机图

不适用于构造图。容易超时。

思路：

对于出发的点，向所有可以到达，并且没到达过的点的边都进行松弛（见 图论——dijkstra），将松弛的点入队，注意是队列不是优先队列。

继续重复上面的操作，直到队列为空。

```cpp
#include <bits/stdc++.h>

using namespace std;
/*
spfa.
*/
#define MAX 100005
#define node int
#define INF 0x7fffffff
vector <long long> edge[MAX], edgeValue[MAX];
long long n, m, minDistance[MAX], visited[MAX];
node start;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> start;
    for (int i = 1; i <= m; i ++) {
        int from, to, value;
        cin >> from >> to >> value;
        edge[from].push_back(to);
        edgeValue[from].push_back(value);
    }
    //This is input.
    for (int i = 1; i <= n; i ++) minDistance[i] = INF;
    minDistance[start] = 0;
    visited[start] = 1;
    queue <int> nodeQueue;
    nodeQueue.push(start);
    // cout << minDistance[start] << "\n";
    //Push the first node.
    while (!nodeQueue.empty()) {
        int lastNode = nodeQueue.front();
        nodeQueue.pop();
        visited[lastNode] = 0;
        for (int i = 0; i < edge[lastNode].size(); i ++) {
            int nowNode = edge[lastNode][i];
            // cout << lastNode << " " << nowNode << " " << minDistance[nowNode] << " " << minDistance[start] << " \n";
            if (minDistance[nowNode] > minDistance[lastNode] + edgeValue[lastNode][i]) {
                minDistance[nowNode] = minDistance[lastNode] + edgeValue[lastNode][i];
                if (visited[nowNode] == 0) {
                    visited[nowNode] = 1;
                    nodeQueue.push(nowNode);
                }
            }
        }
        //Get the min distance of ${start} and other nodes.
    }
    for (int i = 1; i <= n; i ++) {
        cout << minDistance[i] << " ";
    }
    //Print minDistance.
    return 0;
}
```



除了最短路，我们还可以在判断负环的时候运用spfa算法。

而且在判断负环的时候，spfa的效率是 $O(n)$ 的。（不确定，有没有大佬来指点一下）

思路：

如果入队次数大于 n-1，有负环，否则没有



**注意**

切记设置初始值=0的时候要放在初始化后面！



负边权，适合spfa

单源最短路，求和的适合dijkstra

求路径的适合floyd

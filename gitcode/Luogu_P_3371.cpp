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
#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, m, f[1000005], cnt;
map <double, int> mp;
double ans;
struct node{
    double f, t, v;
} e[1000005];
bool cmp(node x, node y) {
    return x.v < y.v;
}
int find(int x) {
    if (f[x] == x) return x;
    else return f[x] = find(f[x]);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n * 2; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        cin >> e[i].f >> e[i].t;
        e[i].v = sqrt(e[i].t * e[i].t - e[i].f * e[i].f);
        mp[e[i].f] = i;
        mp[e[i].t] = n + i;
    }
    sort(e + 1, e + n + 1, cmp);
    for (int i = 1; i <= m; i ++) {
        int fx = find(e[i].f), fy = find(e[i].t);
        if (fx == fy) {
            continue;
        }
        f[fx] = fy;
        cnt ++;
        if (cnt > n) break;
        ans += e[i].v;
    }
    printf("%.2lf", ans);
    return 0;
}
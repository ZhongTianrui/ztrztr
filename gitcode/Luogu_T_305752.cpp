#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, m, f[100005];
int find(int x) {
    if (f[x] == x) return x;
    else return f[x] = find(f[x]);
}
void merge(int x, int y) {
    f[find(x)] = find(y);
    return;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) f[i] = i;
    while (m --) {
        int x, y, z; cin >> z >> x >> y;
        if (z == 1) merge(x, y);
        else cout << (find(x) == find(y) ? "Y" : "N") << "\n";
    }
    return 0;
}
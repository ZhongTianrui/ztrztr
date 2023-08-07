#include <bits/stdc++.h>

using namespace std;
/*
*/
int f[1000005], n, m, k, cnt;
set <int> st;
void init() {
    for (int i = 0; i <= n + 1; i ++) {
        f[i] = i;
    }
}
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;      
    init();
    while (m --) {
        cnt = 0;
        int x, y; cin >> x >> y;
        y = find(y);
        while (x <= y) {
            if (x != y and find(x) == y) continue;//已经被标记
            f[y] = find(y - 1);
            cnt ++;
            y = find(y);
        }
        cout << n + cnt << "\n";
    }
    return 0;
}
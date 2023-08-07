#include <bits/stdc++.h>

using namespace std;
int n, m, tmp[100005], f[100005], x[100005], y[100005], z[100005];
int find(int x) {
    if (f[x] == x) return x;
    else return f[x] = find(f[x]);
}
void merge(int x, int y) {
    f[find(x)] = find(y);
    if (find(x) == find(y)) return;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T --) {
        int n; cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> x[i] >> y[i] >> z[i];
            tmp[++m] = x[i];
            tmp[++m] = y[i];
        }
        sort(tmp + 1, tmp + m + 1);
        for (int i = 1; i <= n; i ++) {
            x[i] = lower_bound(tmp + 1, tmp + m + 1, x[i]) - tmp;
            y[i] = lower_bound(tmp + 1, tmp + m + 1, y[i]) - tmp;
        }
        for (int i = 1; i <= m; i ++) f[i] = i;
        for (int i = 1; i <= n; i ++) {
            if (z[i]) merge(x[i], y[i]);
        }
        bool bl = 1;
        for (int i = 1; i <= n; i ++) {
            if (!x[i] && find(x[i]) == find(y[i])) {
                bl = 0;
                break;
            }
        }
        cout << (bl ? "YES\n" : "NO\n");
    }
    return 0;
}
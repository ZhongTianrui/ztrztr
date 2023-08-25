#include <bits/stdc++.h>

using namespace std;
int n;
struct str{
    int v, id;
} a[1000005];
map <int, int> mp;//建立映射 
bool cmp(str x, str y) {
    if (x.v == y.v) return x.id < y.id;
    return x.v < y.v;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> n >> T;
    for (int  i = 1; i <= n; i ++) {
        cin >> a[i].v;
        a[i].id = i;
        mp[i] = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++) mp[i] = a[i].id;
    while (T --) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            a[mp[x]].v = y;
            for (int i = 2; i <= n; i ++) {
                if (cmp(a[i], a[i - 1])) swap(a[i], a[i - 1]);
            }
            for (int i = n; i >= 2; i ++) {
                if (cmp(a[i], a[i - 1])) swap(a[i], a[i - 1]);
            }
            for (int i = 1; i <= n; i ++) mp[i] = a[i].id;
        } else {
            int x; cin >> x;
            cout << mp[x] << "\n";
        }
    }
    return 0;
}
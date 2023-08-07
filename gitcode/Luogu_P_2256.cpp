#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, m, f[100005];
map <string, int> mp;
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
    for (int i = 1; i <= n; i ++) {
        f[i] = i;
        string s; cin >> s;
        mp[s] = i;
    }
    while (m --) {
        string y, x; cin >> x >> y;
        merge(mp[x], mp[y]);
    }
    int k; cin >> k;
    for (int i = 1; i <= k; i ++) {
        string x, y; cin >> x >> y;
        cout << (find(mp[x]) == find(mp[y]) ? "Yes." : "No.") << "\n";
    }
    return 0;
}
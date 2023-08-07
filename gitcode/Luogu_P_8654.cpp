#include <bits/stdc++.h>

using namespace std;
/*
*/
int f[1000005], n, m, k;
set <int> st;
void init() {
    for (int i = 1; i <= n; i ++) {
        f[i] = i;
    }
}
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y) {
    f[find(x)] = find(y);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    n = n * m;
    init();
    cin >> k;
    while (k --) {
        int x, y; cin >> x >> y;
        merge(x, y);
    }
    for (int i = 1; i <= n; i ++) {
        st.insert(find(i));
    }
    cout << st.size();
    return 0;
}
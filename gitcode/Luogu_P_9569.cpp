#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, m, maxn = -1, flag;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        if (x * (m - y) > maxn) maxn = x * (m - y), flag = i;
    }
    cout << flag;
    return 0;
}
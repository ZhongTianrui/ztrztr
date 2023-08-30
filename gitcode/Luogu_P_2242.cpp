#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, m, a[100005], b[100005], ans;
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    ans = a[n] - a[1] + 1;
    //如果 n == m，ans就等于答案
    for (int i = 1; i < n; i ++) b[i] = a[i + 1] - a[i];
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i < m; i ++) ans = ans - b[i] + 1;
    cout << ans;
    return 0;
}
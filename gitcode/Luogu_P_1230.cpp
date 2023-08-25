#include <bits/stdc++.h>

using namespace std;
/*
*/
struct s{
    int t, v;
} a[1000005];
int  vis[1000005], n, m, ans;
bool cmp(s a, s b) {
    return a.v >  b.v;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i].t;
    for (int i = 1; i <= n; i ++) cin >> a[i].v;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++) {
        for (int j = a[i].t; j > 0; j --) {
            // cout << i << " " << j << " " << vis[j] << "\n"; 
            if (vis[j] == 1) continue;
            vis[j] = 1;
            a[i].v = 0;
            break;
        }
    }
    for (int i = 1; i <= n; i ++) ans += a[i].v;
    cout << m - ans;
    return 0;
}
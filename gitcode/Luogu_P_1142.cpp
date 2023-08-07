#include <bits/stdc++.h>

using namespace std;
/*
(x1 - x2) / (y1 - y2) = (x1 - x3) / (y1 - y3)
*/
int n, x[1005], y[1005];
map <pair <int, int>, int> mp;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> x[i] >> y[i];
    }
    int maxn = -1e9;
    for  (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            int ans = 2;
            for (int k = 1; k <= n; k ++) {
                if (k == i or k == j) {
                    continue;
                }
                //检查三点是否在一条线上
                if ((x[i] - x[j]) * (y[i] - y[k]) == (y[i] - y[j]) * (x[i] - x[k])) ans ++;
            }
            maxn = max(maxn, ans);
        }
    }
    cout << maxn;
    return 0;
}
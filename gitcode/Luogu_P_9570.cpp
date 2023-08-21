#include <bits/stdc++.h>

using namespace std;
/*
离线计算，统计
*/
int n, m, cnt;
char a[1000005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        cin >> a[i];
        if (a[i] == 'N') cnt ++;
    }
    if (cnt > n || a[1] == 'Y') {
        cout << "No solution";
        return 0;
    }
    cnt = 0;
    for (int i = 1; i <= m; i ++) {
        if (a[i] == 'N') {
            cnt ++;
            cout << cnt << " ";
        } else {
            cout << 1 << " ";
        }
    }
    return 0;
}
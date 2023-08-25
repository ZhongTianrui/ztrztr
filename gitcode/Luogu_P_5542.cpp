#include <bits/stdc++.h>

using namespace std;
/*
*/
int a[1005][1005]; 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    while (n --) {
        int X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2;
        a[X1 + 1][Y1 + 1] ++;
        a[X2 + 1][Y2 + 1] ++;
        a[X1 + 1][Y2 + 1] --;
        a[X2 + 1][Y1 + 1] --;
    }
    int cnt = 0;
    for (int i = 1; i <= 1000; i ++) {
        for (int j = 1; j <= 1000; j ++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
            if (a[i][j] == m) cnt ++;
        } 
    }
    cout << cnt;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
/*
*/
int a[100005], n, maxn, cnt;
void input() {
    int i = 0;
    while (cin >> a[i + 1]) {
        i ++;
    }
    n = i;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    for (int i = 1; i <= n; i ++) {
        int cntt = 1;
        while (a[i + 1] <= a[i] && i <= n) {
            i ++;
            cntt ++;
        }
        cnt ++;
        maxn = max(maxn, cntt);
    }
    cout << maxn << "\n" << cnt;
    return 0;
}
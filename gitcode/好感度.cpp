#include <bits/stdc++.h>

using namespace std;
int a[100005], b[100005], n, m, sum = 0;
void fun() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i] * m;
    }
    for (int i = 1; i <= m; i ++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    if (a[n] > b[1]) {
        cout << "-1\n";
        return;
    }
    if (n == 1) {
        for (int i = 1; i <= m; i ++) {
            if (a[1] != b[i]) {
                cout << "-1\n";
                return;
            }
        }
        cout << sum << "\n";
        return;
    }
    if (m == 1) {
        for (int i = 1; i <= n; i ++) {
            if (a[i] == b[1]) {
                cout << sum << "\n";
                return;
            }
        }
        cout << "-1" << "\n";
        return;
    }
    for (int i = 1; i <= m; i ++) {
        sum += b[i] - a[n];
    }
    if (a[n] != b[1]) sum += a[n] - a[n - 1];
    cout << sum << "\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T --) {
        sum = 0;
        fun();
    }
    return 0;
}
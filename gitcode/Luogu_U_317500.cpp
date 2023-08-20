#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int l = -1, r = -1;
    int a[100005] = {};
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        if (a[i]) {
            l = i;
            break;
        }
    }
    for (int i = n; i >= 1; i --) {
        if (a[i]) {
            r = i;
            break;
        }
    }
    if (l == -1 && r == -1) {
        cout << 0;
        return 0;
    }
    cout << r - l + 1;
    return 0;
}
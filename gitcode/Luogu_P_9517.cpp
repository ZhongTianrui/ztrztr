#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, a[100005], l = -1, r = -1;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
                // cout << a[i] << " " << (a[i] == 1) << "\n";
        if (a[i] == 1) {
            l = i;
            break;
        }
    }
    for (int i = n; i >= 1; i --) if (a[i] == 1)  {
        r = i;
        break;
    }
    if (l == r == -1) cout << 0;
    else cout << r - l + 1;
    return 0;
}
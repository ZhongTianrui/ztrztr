#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, m, va[1000005], op[1000005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> op[i] >> va[i];
    cin >> m;
    for (int i = n; i >= 1; i --) {
        if (op[i] == 1) m += va[i];
        else m -= va[i];
    }
    cout << m;
    return 0;
}
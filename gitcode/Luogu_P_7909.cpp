#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, l, r; cin >> n >> l >> r;
    if (l / n == r / n) cout << r % n;
    else cout << n - 1;
    return 0;
}
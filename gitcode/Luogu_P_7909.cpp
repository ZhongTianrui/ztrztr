#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long n, l, r;
    cin >> n >> l >> r;
    if (l - r >= n) {
        cout << n - 1;
    } else {
        cout << max(l % n, r % n);
    }
    return 0;
}
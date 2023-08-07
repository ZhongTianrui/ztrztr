#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long T; cin >> T;
    while (T --) {
        long long n, e, d, m;
        cin >> n >> d >> e;
        m = n - e * d + 2;
        long long l = 1, r = m / 2;
        while (l <= r) {
            long long p = (l + r) / 2;
            long long q = m - p;
            //和同近积大
            if (p * q < n) l = p + 1;
            else r = p - 1;
        }
        if (l * (m - l) == n) cout << l << " " << m - l << "\n";
        else cout << "NO\n";
    }
    return 0;
}
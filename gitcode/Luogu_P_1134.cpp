#include <bits/stdc++.h>

using namespace std;
/*

*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        ans *= i;
        while (ans % 10 == 0) {
            ans /= 10;
        }
        ans %= 100000000;
    }
    cout << ans % 10;
    return 0;
}
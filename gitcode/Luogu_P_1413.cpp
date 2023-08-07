#include <bits/stdc++.h>

using namespace std;
/*
*/
typedef long long ll;
ll n;
ll ans, num[1000005], a[9][1000005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        ll p, t;
        cin >> p >> t;
        a[p][t] = 1;
        num[p] = max(num[p], t);
    }
    for (int i = 1; i <= 6; i ++) {
        for (int j = 1; j <= num[i]; 1) {
            if (a[i][j] == 1) ans ++, j += 60;
            else j ++;
        }
    }
    cout << ans;
    return 0;
}
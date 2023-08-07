#include <bits/stdc++.h>

using namespace std;
/*
*/
typedef long long ll;
ll n;
ll ans, sum, minn = 1e9;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        sum += x;
        minn = min(minn, sum);
    }
    cout << (minn <= 0 ? abs(minn) + 1 : minn);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
/*
*/
typedef long long ll;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll sum = 0;
    while (n --) {
        ll a, b; cin >> a >> b;
        if (b == 0) sum += 10;
        else sum += a;
    }
    cout << sum;
    return 0;
}
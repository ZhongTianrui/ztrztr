#include <bits/stdc++.h>

using namespace std;
/*
*/
long long check(long long x) {
    long long su = 0;
    while (x > 0) {
        su += x % 10;
        x /= 10;
    }
    return su;
}
bool isprime(long long x) {
    for (long long i = 2; i * i <= x; i ++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long l, r, sum = 1; cin >> l >> r;
    for (long long i = ceil(sqrtl(l)); i <= floor(sqrtl(r)); i ++) {
        if (i * i >= l && i * i <= r && isprime(check(i * i))) {
            sum = (((sum * i) % 998244353) * i) % 998244353;
        }
    }
    if (sum == 1) sum = 0;
    cout << sum;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long a, b, ans;
    cin >> a >> b;
    if ((a < 0 && b < 0) || (a > 0 && b > 0)) cout << max(a, b);
    else a = abs(a), b = abs(b),cout << min(a, b) * 2 + max(a, b);
    return 0;
}
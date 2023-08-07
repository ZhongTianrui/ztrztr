#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long a, b, c, d, e, f, k;
    cin >> a >> b >> c >> d >> e >> f >> k;
    cout << max(k / b * a * c, k / e * d * f);
    return 0;
}
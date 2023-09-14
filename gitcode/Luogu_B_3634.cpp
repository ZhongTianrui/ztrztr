#include <bits/stdc++.h>

using namespace std;
/*
*/
long long a, b, ggcd, llcm;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    ggcd = __gcd(a, b);
    llcm = a * b / ggcd;
    cout << ggcd << " " << llcm;
    return 0;
}
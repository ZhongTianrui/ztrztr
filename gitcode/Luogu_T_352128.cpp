#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long a, b, c;
    cin >> a >> b >> c;
    cout << ((a + b + c) <= 100 && b % 5 == 0 && c % 7 == 0 && (a - b) > (b - c) ? "Yes" : "No");
    return 0;
}
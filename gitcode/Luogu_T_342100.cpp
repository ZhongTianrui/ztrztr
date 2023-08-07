#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    double a, h;
    cin >> a >> h;
    if (a < 10) cout << "Drizzle\n";
    else if (a < 25) cout << "Moderate Rain\n";
    else if (a < 50) cout << "Heavy Rain\n";
    else cout << "Torrential Rain\n";
    if (h == 1) {
        if (a >= 20) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
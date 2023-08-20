#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int m = a + b + c + d + e;
    if (m < 100) cout << "Gray";
    else if (m < 120) cout << "Blue";
    else if (m < 170) cout << "Green";
    else if (m < 230) cout << "Orange";
    else cout << "Red";
    return 0;
}
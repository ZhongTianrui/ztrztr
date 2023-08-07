#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T --) {
        string a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a[0] == 'y' && b[0] == 'y' && c == "ding" && d == "zhen") cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
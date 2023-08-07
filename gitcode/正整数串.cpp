#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s = "";
    for (int i = 1; i <= 1000005; i ++) {
        s += to_string(i);
    }
    int T; cin >> T;
    while (T --) {
        string x; cin >> x;
        cout << s.find(x) + 1 << "\n";
    }
    return 0;
}
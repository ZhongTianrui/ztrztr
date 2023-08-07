#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T --) {
        long double a, b;
        cin >> a >> b;
        a = log2(a);
        b = log2(b);
        if (a == int(a)) a --;
        if (b == int(b)) b --;
        cout << int(abs(a - b)) << "\n"; 
    }
    return 0;
}
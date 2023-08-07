#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    string maxn = s;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '1') {
            for (int j = i; j < n; j ++) {
                string tmp = s.substr(i, j - i + 1);
                reverse(tmp.begin(), tmp.end());
                maxn = min(maxn, s.substr(0, i) + tmp + s.substr(j + 1, n - j));
            }
        }
    }
    cout << maxn;
    return 0;
}
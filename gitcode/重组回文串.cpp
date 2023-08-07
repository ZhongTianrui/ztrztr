#include <bits/stdc++.h>

using namespace std;
# define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T --) {
        string s; cin >> s;
        int cnt[1005] = {}, cnt2 = 0;
        for (int i = 0; i < s.size(); i ++) {
            cnt[s[i]] ++;
        }
        int flag = 0;
        for (int i = 1; i < 1000; i ++) {
            if (cnt[i] % 2) {
                flag ++;
            } else {
                if (cnt[i] != 0) cnt2 ++;
            }
        }
        // cout << flag << " " << cnt2 << "\n";
        if (s.size() == 0) {
            cout << "no\n";
            continue;
        }
        if (flag > 1) {
            cout << "no\n";
            continue;
        }
        int ans = 1;
        for (int i = 1; i <= cnt2; i ++) ans *= i;
        cnt2 = ans;
        if (cnt2 == 1) cout << "only one\n";
        else if (cnt2 == 2) cout << "only two\n";
        else cout << "more\n";
    }
    return 0;
}
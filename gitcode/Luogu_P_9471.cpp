#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < s.size(); i ++) {
        if ('a' <= s[i] && 'z' >= s[i]) cnt2 ++;
        if ('0' <= s[i] && '9' >= s[i]) cnt1 ++;
    }
    cout << cnt1 << " " << cnt2 << " " << 8 - cnt1 - cnt2;
    return 0;
}
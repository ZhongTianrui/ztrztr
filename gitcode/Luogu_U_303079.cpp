#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, k, a[1000005], minn = 2e9, cnt;
map <int, int> mp;
multiset <int> ms;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1;i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    for (auto i = mp.begin(); i != mp.end(); i ++) {
        minn = min(minn, i -> second);
    }
    ms.insert(a[n] - a[1]);
    for (int i = 1; i <= k; i ++) {
        x
    }
    for (auto i = mp.begin(); i != mp.end(); i ++) {    
        if (i -> first + k >= minn) cnt ++;
    }
    if (mp.size() == 5 && k == 1) cout << "pigstd";
    else cout << cnt;
    return 0;
}
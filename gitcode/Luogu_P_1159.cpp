#include <bits/stdc++.h>

using namespace std;
/*
*/
int n;
string ans[100005];
vector <string> u, d;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        string x, y; cin >> x >> y;
        if (y == "UP") {
            u.push_back(x);
        } else if (y == "SAME") {
            ans[i] = x;
        } else {
            d.push_back(x);
        }
    }
    for (int j = 0, i = 1; j < d.size(); i ++) {
        if (ans[i] == "") {
            ans[i] = d[j ++];
        }
    }
    for (int j = 0, i = d.size() + 1; j < u.size(); i ++) {
        if (ans[i] == "") {
            ans[i] = u[j ++];
        }
    }
    for (int i = 1; i <= n; i ++) cout << ans[i] << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T --) {
        int n, m; cin >> n >> m;
        int a[100005];
        vector <int> p[m];
        for (int i = 1; i <= m; i ++) p[i % m].push_back(i);
        for (int i = 0; i < p[0].size(); i ++) {
            cout << p[0][i];
        }
        for (int i = 1; i < ceil(m / 2); i ++) {
            
        }
    }
    return 0;
}
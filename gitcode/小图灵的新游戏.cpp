#include <bits/stdc++.h>

using namespace std;
struct node{
    int x, id;
};

bool cmp(node x, node y) {
    return x.x < y.x;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T --) {
        int n; cin >> n;
        node a[400005];
        for (int i = 1; i <= n; i ++) {
            cin >> a[i].x;
            a[i].id = i;
        }
        sort(a + 1, a + n + 1, cmp);
        vector <int> rankk;
        for (int i = 0; i < n; i ++) {
            if (a[i + 1].x != a[i].x) rankk.push_back(i + 1);
        }
        int nn = rankk.size();
        int i = a[rankk[nn - 3]].id, j = a[rankk[nn - 2]].id, k = a[rankk[nn - 1]].id;
        cout << a[i].x + a[j].x + a[k].x - min(i, min(j, k)) - max(i, max(j, k)) << "\n";
    }
    return 0;
}
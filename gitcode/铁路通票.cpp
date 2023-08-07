#include <bits/stdc++.h>

using namespace std;
/*
*/
long long n, k, sum, t[1000005], fa;
int f[1000005], sz[1000005];
int find(int x) {
    return (f[x] == x ? x : f[x] = find(f[x]));
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        f[i] = i;
        sz[1] = 1;
    }
    t[1] = 1 - k;
    for (int i = 2; i <= n; i ++) {
        cin >> t[i] >> fa;
        t[i] = 1 - t[i];
        if (t[i] == t[fa]) {
            f[i] = fa;
            sz[find(fa)] ++;
        }
        else sz[i] = 1;
        sum += 2 * (i - sz[find(i)]) + t[i] * (sz[find(i)] - 1);
        cout << sum << "\n";
    }
    return 0;
}
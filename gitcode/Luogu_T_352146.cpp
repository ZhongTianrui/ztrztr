#include <bits/stdc++.h>

using namespace std;
/*
*/
typedef long long ll;
ll xiangxian[100005], n, k, a[1000005]; 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= 2 * n; i ++) {
        cin >> a[i];
        xiangxian[i % k] += a[i];
    }
    for (int i = 1; i <= n; i ++) {
        int ii = 2 * i - 1;
        int p = ii % k;
        a[ii] = xiangxian[p] % ii;
    }
    for (int i = 1; i <= 2 * n; i ++) {
        cout << a[i] << " ";
    }
    return 0;
}
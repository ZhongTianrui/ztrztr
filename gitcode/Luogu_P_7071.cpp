#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a[1005] = {}, cnt = 0;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    if (n % 2) {
        cout << "-1";
        return 0;
    }
    int maxn = 1;
    while (maxn * 2 <= n) {
        maxn *= 2;
        cnt ++;
    }
    int tmp = cnt;
    while (maxn > 1) {
        if (n - maxn >= 0) {
            n -= maxn;
            a[tmp] = 1;
        }
        tmp --;
        maxn /= 2;
    }
    for (int i = 1000; i >= 0; i --) {
        if (a[i] == 0) continue;
        cout << a[i] * pow(2, i) << " ";
    }
    return 0;
}
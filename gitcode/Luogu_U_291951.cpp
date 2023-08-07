#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, m, k, s;
    cin >> n >> m >> k >> s;
    int a[100005];
    for (int i = 1; i <= n; i ++) {
        a[i] = s / n;
    }
    for (int i = 1; i <= s % n; i ++) {
        a[i] ++;
    }
    for (int i = 1; i <= n; i ++) {
        cout << a[i] << " ";
    }
    return 0;
}
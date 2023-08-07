#include <bits/stdc++.h>

using namespace std;
/*
*/
int a[100005], n, sum;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++) {
        if (a[i] != a[i - 1]) sum ++;
    }
    cout << sum;
    return 0;
}   
#include <bits/stdc++.h>

using namespace std;
/*
答案范围：0~n
l < r

*/
long long n, m;
long long a[100005];
bool check(int x) {
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        sum += a[i] / x;
    }
    return sum >= m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    long long l = 0, r = 1000000001;
    while (l + 1 < r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l;
    return 0;
}
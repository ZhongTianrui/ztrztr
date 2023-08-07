#include <bits/stdc++.h>

using namespace std;
/*
*/
int prime[105], tim[10000005];
int m[105] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int make_prime() {
    for (int i = 1; i <= 100; i ++) {
        if (!prime[i]) {
            for (int j = i; j <= 100; j += i) {
                prime[j] = 1;
            }
        }
    }
    for (int i = 1; i <= 100) {
        prime[i] = prime[i - 1] + prime[i];
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    make_prime();
    int T; cin >> T;
    while (T --) {
        int ans = 1, flag = 0;
        int a[10], b[10];
        for (int i = 1; i <= 5; i ++) cin >> a[i];
        for (int i = 1; i <= 5; i ++) cin >> b[i];
        for (int i = 1; i <= 5; i ++) {
            flag = i;
            if (a[i] != b[i]) {
                break;
            }
        }
        if (flag == 5 and a[5] == b[5]) {
            cout << "0\n";
            continue;
        }
        for (int i = a[flag]; i <= 5; i ++) {
            if (i != flag and b[i] <= a[i]) b[i] += 10;
            if (i == 1) {
                ans += 
            }
        }
    }
    return 0;
}
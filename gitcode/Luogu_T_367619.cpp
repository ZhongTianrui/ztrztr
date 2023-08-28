#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    if (n <= floor(m / 2.0)){
        cout << 0;
        return 0;
    }
    int cnt = 0, tmp = n;
    int a[1005] = {0};
    for (int i = floor(m / 2.0); i <= n; i ++) {
        int canput = 0;
        for (int j = 1; j <= m; j ++) {
            if (tmp == 0) {
                a[m + 1] = a[1];
                for (int ii = 2; ii <= m + 1; ii ++) {
                    if (a[ii] == a[ii - 1] && a[ii] == 1) {
                        for (int jj = )
                    }
                }
            }
            if (a[j] == 0) {
                canput = (canput + 1) % 2;
                if (canput) {
                    a[j] = 1;
                    tmp --;
                }
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int n;
double r, ans, pai = 3.1415926, x[1000005], y[1000005];
/*
*/
int main() {
    cin >> n >> r;
    for (int i = 1; i <= n; i ++) cin >> x[i] >> y[i];
    //破环为链
    x[n + 1] = x[1];
    y[n + 1] = y[1];
    for (int i = 1; i <= n; i ++) {
        ans += sqrt(abs(x[i] - x[i + 1]) * abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]) * abs(y[i] - y[i + 1]));
    }
    printf("%.2lf", ans + r * pai * 2);
    return 0;
}
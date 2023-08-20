#include <bits/stdc++.h>

using namespace std;
long long a[1005];
unsigned long long findMaxPowerOfTwo(unsigned long long x) {
    unsigned long long k = 0;
    while ((1ULL << k) <= x) {  // 使用位运算计算 2 的指数
        k++;
    }
    return (1ULL << (k-1));  // 使用位运算得到结果
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T --) {
        unsigned long long x; cin >> x;
        cout << findMaxPowerOfTwo(x) << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
/*
*/
long long dp[105][105], n, q, b[1005];
struct node{
    long long x, y;
} a[1005];
bool cmp(node x, node yy) {
    return x.y < yy.y;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].x;
        a[i].y = a[i].x % q;    
    }
    sort(a + 1, a + n + 1, cmp);
    dp[1][1] = a[1].y;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            dp[i][j] = max((dp[i - 1][j]) % q, (dp[i - 1][j - 1] + a[i].y) % q);
        }
    }
    long long maxn = 0;
    for (int i = 0; i <= n; i ++) {
        maxn = max(maxn, dp[n][i] % q);
    }
    cout << maxn;
    return 0;
}
/*
找到题目的方法：
打开http://aisichuang.net/，登录
打开浏览器控制台（按右键，点击”检查“，在上面点击控制台）
输入：
window.location.href = "http://aisichuang.net/main/questionBank/solve"
localStorage.setItem("storedData", "{\"id\" : 2270}")//2270是第一道题的id，2271是T2的，以此类推
window.location.replace("http://aisichuang.net/main/questionBank/solve")
*/
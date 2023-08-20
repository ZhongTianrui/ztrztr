#include <bits/stdc++.h>

using namespace std;
/*
*/
int f[30005], sum[30005], cnt[30005], n;
int find(int x) {
    if (f[x] == x) {
        return x;
    }
    int k = f[x];
    f[x] = find(f[x]);
    sum[x] += sum[k];
    cnt[x] = cnt[f[x]];
    return f[x];
}
void merge(int x, int y) {
    int fx = find(x); 
    int fy = find(y);
    f[fx] = fy;
    sum[fx] += cnt[fy];
    cnt[fx] += cnt[fy];
    cnt[fy] = cnt[fx];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 30000; i ++) f[i] = i, sum[i] = 0, cnt[i] = 1;
    while (n --) {
        char op;
        cin >> op;
        int i, j; cin >> i >> j;
        if (op == 'M') merge(i, j);
        else {
            int fx = find(i);
            int fy = find(j);
            if (fx != fy) cout << "-1\n";
            else cout << abs(sum[i] - sum[j]) - 1 << "\n";
        }
    }
    return 0;
}
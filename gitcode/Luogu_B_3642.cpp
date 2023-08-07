#include <bits/stdc++.h>

using namespace std;
/*
*/
int a[1000005] = {1, 1};
void qian(int x) {
    if (a[x] == -1) return;
    cout << a[x] << " ";
    qian(x * 2);
    qian(x * 2 + 1);
}
void zhong(int x) {
    if (a[x] == -1) return;
    zhong(x * 2);
    cout << a[x] << " ";
    zhong(x * 2 + 1);
}
void hou(int x) {
    if (a[x] == 0) return;
    hou(x * 2);
    hou(x * 2 + 1);
    cout << a[x] << " ";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        a[i * 2] = x;
        a[i * 2 + 1] = y;
    }
    for (int i = 1; i <= 10; i ++) cout << a[i] << " ";
    qian(1); cout << "\n";
    zhong(1); cout << "\n";
    hou(1); cout << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
/*
*/
#define int long long
int n, a[1000005], vis[1000005];
struct node{
    int x, y, z;
};
queue <node> q1, q2;
signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int tmp = 1;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    a[n + 1] = !a[n];
    for (int i = 2; i <= n + 1; i ++) if (a[i] != a[i - 1]) q1.push((node){tmp, i - 1, a[i - 1]}), tmp = i;
    int kkksc03 = n;
    while (kkksc03) {
        while (q1.size()) {
            node tmp2 = q1.front();
            q1.pop();
            while (tmp2.x <= tmp2.y && vis[tmp2.x] == 1) tmp2.x ++;
            if (tmp2.x > tmp2.y) continue;
            vis[tmp2.x] = 1;
            cout << tmp2.x << " ";
            kkksc03 --;
            if(tmp2.x == tmp2.y) continue;
            tmp2.x ++;
            q2.push(tmp2);
        }
        cout << "\n";
        while (q2.size()) {
            node nw = q2.front();
            q2.pop();
            while (q2.size()) {
                node nw2 = q2.front();
                if (nw.z == nw2.z) {
                    q2.pop();
                    nw2.x = nw.x;
                    swap(nw, nw2);
                    // q1.push(nw2);
                } else break;
            }
            q1.push(nw);
        }
    }
    if (kkksc03 == 0) kkksc03 = 0; /*kkksc03 was dead*/
    return 0;
}
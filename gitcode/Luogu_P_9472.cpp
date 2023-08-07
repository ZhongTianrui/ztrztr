    #include <bits/stdc++.h>

    using namespace std;
    /*
    */
    int n, m;
    struct node{
        int a1, id;
    } a[100005];
    bool cmd(node x, node y) {
        if (x.a1 != y.a1) return x.a1 < y.a1;
        else return x.id < y.id;
    }
    int main() {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        cin >> n >> m;
        for (int i = 1; i <= n; i ++) cin >> a[i].a1, a[i].id = (a[i].a1 < 0 ? -i : i);
        sort(a + 1, a + n + 1, cmd);
        for (int i = 1; i <= n; i ++) cout << (a[i].id < 0 ? -a[i].id : a[i].id) << " ";
        return 0;
    }
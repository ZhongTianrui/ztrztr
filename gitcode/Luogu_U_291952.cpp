#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    int cmd[100005][10], warx[100005], wary[100005];
    vector <int> a3;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> warx[i] >> wary[i];
    }
    for (int i = 1; i <= m; i ++) {
        cin >> cmd[i][1];
        if (cmd[i][1] == 1) {
            cin >> cmd[i][2] >> cmd[i][3];
        } else if (cmd[i][1] == 3) {
            a3.push_back(i);
            cin >> cmd[i][2];
        } else {
            cin >> cmd[i][2];
        }
    }
    for (int i = 0; i < a3.size(); i ++) {
        long long x = warx[cmd[a3[i]][2]], y = wary[cmd[a3[i]][2]];
        for (int j = 1; j <= a3[i]; i ++) {
            if (cmd[j][1] == 1) {   
                x += cmd[j][2];
                y += cmd[j][3];
            } else {
                swap(x, y);
            }
        }
        cout << x << " " << y << "\n";
    }
    return 0;
}
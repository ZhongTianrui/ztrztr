#include <bits/stdc++.h>

using namespace std;
/*
*/
int m;
queue <int> q;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m;
    while (m --) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            q.push(x);
        } else if (op == 2) {
            if (q.empty()) cout << "ERR_CANNOT_POP\n";
            else q.pop(); 
        } else if (op == 3) {
            if (q.empty()) cout << "ERR_CANNOT_QUERY\n";
            else cout << q.front() << "\n";
        } else cout << q.size() << "\n";
    }
    return 0;
}
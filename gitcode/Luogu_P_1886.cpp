#include <bits/stdc++.h>

using namespace std;
int a[1000005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    deque <int> dq;
    for (int i = 1; i < n; i ++) {
        cin >> a[i];
    }
    for (int i = m; i <= n; i ++) {
        if (dq.size() != 0 and i - dq.front() <= m) {
            dq.pop_front();
        }
        while (dq.size() != 0 and a[i] < dq.back()) {
            dq.pop_back();
        }
        dq.push_back(a[i]);
        cout << a[dq.front()] << " ";
    }
    cout << "\n";
    while (!dq.empty()) dq.pop_back();
    for (int i = m; i <= n; i ++) {
        if (dq.size() != 0 and i - dq.front() >= m) {
            dq.pop_front();
        }
        while (dq.size() != 0 and a[i] > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(a[i]);
        cout << a[dq.front()] << " ";
    }
    return 0;
}
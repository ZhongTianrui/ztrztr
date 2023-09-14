#include <bits/stdc++.h>

using namespace std;
int a[1000005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    deque <int> dq, dq2;
    for (int i = 1; i < n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        while (dq.size() and a[dq.back()] > a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=m){
            while (i - m >= dq.front()) {
                dq.pop_front();
            }
            cout << a[dq.front()] << " ";
        }
    }
    cout << "\n";
    // while (!dq.empty()) dq.pop_back();
    for (int i = 1; i <= n; i ++) {
        while (dq2.size() != 0 and a[dq2.back()] < a[i]) {
            dq2.pop_back();
        }
        dq2.push_back(i);
        if(i>=m) {
            while (i - m >= dq2.front()) {
                dq2.pop_front();
            }
            cout << a[dq2.front()] << " ";
        }
    }
    return 0;
}
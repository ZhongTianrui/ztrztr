#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, ans[5000005], a[5000005];
stack <int> st; 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i --) {
        while (st.size() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (st.size() == 0) ans[i] = 0;
        else ans[i] = st.top();
        st.push(i);
    }
    for (int i = 1; i <= n; i ++) cout << ans[i] << " ";
    return 0;
}
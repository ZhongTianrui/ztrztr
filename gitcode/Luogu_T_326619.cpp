#include <bits/stdc++.h>

using namespace std;
/*
*/
int a[1000005];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    set <int> st;
    int lastsize = 0;
    for (int i = 1; i <= m; i ++) {
        cin >> a[i];
        st.insert(0);
        int tmp = a[i] % n;
        if (n % a[i] == 0) {
            for (int j = 0; j <= n; j += a[i]) {
                st.insert(j % n);
            }
        }
        else {for (int j = 1; tmp != 0; j ++) {
            st.insert(tmp);
            tmp += a[i];
            tmp = tmp % n;
//            cout << tmp << " ";
        }}
        cout << st.size() - lastsize << " ";
        lastsize = st.size();
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector <string> v;
    int n; cin >> n;
    while (n --) {
        string s; cin >> s;
        if (s[0] + s[3] - s[1] - s[2] > 0) v.push_back(s);
    }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i ++) cout << v[i] << " ";
    return 0;
}
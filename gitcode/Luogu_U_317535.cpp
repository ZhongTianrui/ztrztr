#include <bits/stdc++.h>

using namespace std;
/*
*/
map <string, int> mp;
string a[1000005];
int ed = 1, fr = 0, T;
string x, y;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T --) {
        string s; cin >> s;
        if (s == "start") {
            if (ed == fr + 1) cout << "Error\n";
            else {
                if (x != "") a[mp[x]] = " ", a[++ fr] = x;
                if (y != "") a[mp[y]] = " ", a[++ fr] = y;
                ed += (x != "") + (y != "");
                while (mp[a[ed]] == -1) ed ++;
                
                string xx, yy;
                xx = a[ed];
                yy = a[ed + 1];
                cout << xx << " " << yy << "\n";

                
                x = xx;
                y = yy;
                
            }
        }
        if (s == "arrive") {
            string ch; cin >> ch;
            if ((mp[ch] && mp[ch] != -1) || ch == x || ch == y) cout << "Error\n";
            else {
                mp[ch] = fr;
                a[++ fr] = ch;
                cout << "OK\n";
            }
        }
        if (s == "leave") {
            string ch; cin >> ch;
            if (!mp[ch] || ch == x || ch == y) cout << "Error\n";
            else {
                a[mp[ch]] = "";
                mp[ch] = -1;
                cout << "OK\n";
            }
        }
    }
    return 0;
}
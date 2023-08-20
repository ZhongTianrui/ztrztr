#include <bits/stdc++.h>

using namespace std;
/*
*/
int T;
string x, y;
list <string> li;
map <string, int> mp;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T --) {
        string op; cin >> op;
        if (op == "start") {
            // cout << "*" << x << " " << y << "\n";
            if (x != "") li.push_back(x);
            if (y != "") li.push_back(y);
            if (li.empty()) {
                cout << "Error\n";
                continue;
            }
            if (li.front() != "") {
                x = li.front();
                li.pop_front();
                cout << x << " ";
            }
            if (li.front() != "") {
                y = li.front();
                li.pop_front();
                cout << y << " ";
            }
            cout << "\n";
        }
        if (op == "arrive") {
            string s; cin >> s;
            if (mp[s]) {
                cout << "Error\n";
                continue;
            }
            else {
                li.push_back(s);
                mp[s] = 1;
            }
            cout << "OK\n";
        }
        else if (op == "leave") {
            string s; cin >> s;
            if (mp[s] == 0) {
                cout << "Error\n";
                continue;
            }
            if (x == s || y == s) {
                cout << "Error\n";
                continue;
            }
            for (auto i = li.begin(); i != li.end(); i ++){ 
                if (*i == s) {
                    li.erase(i);
                    mp[s] = 0;
                    break;
                }
            }
            cout << "OK" << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string mid, back;
    cin >> mid;
    stack <char> num, op;
    for (int i = 0; i < mid.size(); i ++) {
        if (mid[i] <= '9' and mid[i] >= '0') {
            num.push(mid[i]);
        } else {
            if (mid[i] != '(' and mid[i] != ')') op.push(mid[i]);
            else {
                if (mid[i] == '(') {
                    
                }
            } 
        }
    }
    return 0;
}
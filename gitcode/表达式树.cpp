#include <bits/stdc++.h>

using namespace std;
/*
   *
  / \
 1   2
 中序遍历是中序表达式
 其他同理
*/
char tr[1000005];
void qian(int nw) {
    if (tr[nw] == ' ') {
        return;
    }
    cout << tr[nw] << " ";
    qian(nw * 2);
    qian(nw * 2 + 1);
}
void zhong(int nw) {
    if (tr[nw] == ' ') {
        return;
    }
    zhong(nw * 2);
    cout << tr[nw] << " ";
    zhong(nw * 2 + 1);
}
void how(int nw) {
    if (tr[nw] == ' ') {
        return;
    }
    how(nw * 2);
    how(nw * 2 + 1);
    cout << tr[nw] << " ";
}
void new_l_tr(int nw, char x) {
    tr[nw * 2] = x;
}
void new_r_tr(int nw, char x) {
    tr[nw * 2 + 1] = x;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);   
    string exp;
    cin >> exp;
    
    return 0;
}
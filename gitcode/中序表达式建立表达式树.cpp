/*

 problem :
 by : ztrztr(luogu 602124)
 date : 2022/10/16
 update : 2022/10/16

*/
#include <bits/stdc++.h>
using namespace std;
int lch[10005], rch[10005], n;
char data[10005], op[10005];
int build_exp_tree(char s[], int l, int r) {
	int cnt1, cnt2, p;
	p = 0;
	cnt1 = cnt2 = -1;
	int u;
	if (r - l == 1) {
		u = ++n;
		lch[u] = rch[u] = 0;
		op[u] = s[l];
	}
	for (int i = l; i < r; i ++) {
		if (s[i] == '(') p ++;
		if (s[i] == ')') p --;
		if (s[i] == '+' or s[i] == '-') if (p == 0) cnt1 = i;
		if (s[i] == '*' or s[i] == '/') if (p == 0) cnt2 = i;
	}
	if (cnt1 < 0) cnt1 = cnt2;
	if (cnt1 < 0) return build_exp_tree(s, l + 1, r - 1);
	u = ++n;
	lch[u] = build_exp_tree(s, l, cnt1);
	rch[u] = build_exp_tree(s, cnt1 + 1, r);
	op[u] = s[cnt1];
	return u;
}
namespace fun{
	void d2(int nw) {
		if (lch[nw] == 0 && rch[nw] == 0) {
			return;
		}
		d2(lch[nw]);
		cout << op[nw] << " ";
		d2(rch[nw]);
	}
}
namespace OI{
	void run() {
		char s[10005];
		cin >> s;
		cout << build_exp_tree(s, 0, strlen(s));
//		fun::d2(0);
	}
}
int main() {
	ios::sync_with_stdio(false);
	OI::run();
	return 0;
}



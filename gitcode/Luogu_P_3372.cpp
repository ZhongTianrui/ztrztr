/*

 problem :
 by : ztrztr(luogu 602124)
 date : 2022/10/16
 update : 2022/10/16

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int seg[1000005], n, mark[1000005], a[1000005];
namespace fun{
	void pd(int nw, int len) {
		mark[nw * 2] += mark[nw];
		mark[nw * 2 + 1] += mark[nw];
		//Update mark.
		seg[nw * 2] += mark[nw] * (len - len / 2);
		seg[nw * 2 + 1] += mark[nw] * (len / 2);
		//Update SegTree.
		mark[nw] = 0;
		//Free mark.
	}
	void build(int nw, int l, int r) {
		if (l == r) {
			seg[nw] = a[l];
			//Leaf node.
//			cout << "[Debug] Finded leaf node " << nw << "\n";
			return; 
		}
        int mid = (l + r) / 2;
//        cout << "11\n";
        build(nw * 2, l, mid);
        build(nw * 2 + 1, mid + 1, r);
		seg[nw] = seg[nw * 2] + seg[nw * 2 + 1];
		//update
	}
	void update(int l, int r, int nw, int x, int nl, int nr) {
		if (nl > r || nr < l) return;
		if (nl >= l && nr <= r) {
			seg[nw] += (nr - nl + 1) * x;
			if (nr > nl) mark[nw] += x;
			return;
		}
		pd(nw, nr - nl + 1);
		update(l, r, nw * 2, x, nl, (nl + nr) / 2);
		update(l, r, nw * 2 + 1, x, (nl + nr) / 2 + 1, nr);
		seg[nw] = seg[nw * 2] + seg[nw * 2 + 1];
		//update
	}
	int find(int l, int r, int nw, int nl, int nr) {
		if (nl > r || nr < l) return 0;
		if (nl >= l && nr <= r) return seg[nw];
		pd(nw, nr - nl + 1);
		int leftAns = find(l, r, nw * 2, nl, (nl + nr) / 2);
		int rightAns = find(l, r, nw * 2 + 1, (nl + nr) / 2 + 1, nr);
		return leftAns + rightAns;
	}
}
using namespace fun;
namespace OI{
	void run() {
		int m;
		cin >> n >> m;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		build(1, 1, n);
//		cout << "[Debug] Build OK!\n";
		while (m --) {
			int op; cin >> op;
			if (op == 1) {
				int x, y, z; cin >> x >> y >> z;
				update(x, y, 1, z, 1, n);
			} else {
				int x, y; cin >> x >> y;
				cout << find(x, y, 1, 1, n) << "\n";
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	OI::run();
	return 0;
}


/*

 problem :
 by : ztrztr(luogu 602124)
 date : 2022/10/16
 update : 2022/10/16

*/
#include <bits/stdc++.h>
using namespace std;
int lch[1005], rch[1005], d[1005], n; 
namespace fun{
	void d1(int nw) {
		if (d[nw] <= 0) return;
		cout << d[nw] << " ";
		d1(lch[nw]);
		d1(rch[nw]); 
	}
	void d2(int nw) {
		if (d[nw] <= 0) {
			return;
		}
		d2(lch[nw]);
		cout << d[nw] << " ";
		d2(rch[nw]);
	}
	void d3(int nw) {
		if (d[nw] <= 0) return;
		d3(lch[nw]);
		d3(rch[nw]);
		cout << d[nw] << " ";
	}
}
namespace OI{
	void run() {
		cin >> n;
		for (int i = 1; i <= n; i ++) d[i] = -1e9;
		for (int i = 1; i <= n; i ++) cin >> lch[i] >> rch[i] >> d[i];
		fun::d1(1); cout << "\n";
		fun::d2(1); cout << "\n";
		fun::d3(1); cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	OI::run();
	return 0;
}



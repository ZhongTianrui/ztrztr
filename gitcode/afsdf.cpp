/*

 problem :
 by : ztrztr(luogu 602124)
 date : 2022/10/16
 update : 2022/10/16

*/
#include <bits/stdc++.h>
using namespace std;
namespace fun{
}
namespace OI{
	void run() {
		int n, a[1005], r, t[1005], sum = 0;
		cin >> n >> r;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= r; i ++) {
			t[i] = a[i];
		}
		for (int i = r + 1; i <= n; i ++) {
			t[i] = t[i - r] + a[i];
		}
		for (int i = 1; i <= n; i ++) sum += t[i];
		cout << sum;
	}
}
int main() {
	ios::sync_with_stdio(false);
	OI::run();
	return 0;
}



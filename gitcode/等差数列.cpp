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
		int T; cin >> T;
		while (T --) {
			int n; cin >> n;
			int a[500005];
			set <int> s;
			for (int i = 1; i <= n; i ++) {
				cin >> a[i];
			}
			for (int i = 2; i < n; i ++) if (i > 1 && i < n) s.insert(a[i + 1] - a[i])/*, cout << a[i] << " " << a[i + 1 ] << " | "*/  ;
			if (s.size() > 2) cout << "No\n";
			else cout << "Yes\n";
		} 
	}
}
int main() {
	ios::sync_with_stdio(false);
	OI::run();
	return 0;
}



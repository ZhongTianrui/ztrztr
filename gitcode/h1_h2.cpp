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
		freopen("bef.md", "r", stdin);
		freopen("data.md", "w", stdout);
		string s;
		while (getline(cin, s)) {
			string ans;
			for (int i = 0; i < s.size(); i ++) {
				if (s[i] != '#') {
					ans = s;
					break;
				}
				ans = '#' + s;
				break;
			}
			cout << ans << "\n";
		} 
	}
}
int main() {
	ios::sync_with_stdio(false);
	OI::run();
	return 0;
}



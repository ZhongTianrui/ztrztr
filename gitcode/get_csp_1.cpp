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
struct node{
	string a;
	int b;
} ar[1005];
bool cmp(node x, node y) {
	return x.b > y.b;
}
namespace OI{
	void run() {
		freopen("csp_2022_notinit.txt", "r", stdin);
		map <string, int> mp;
		string s;
		while (cin >> s) {
			mp[s] ++;
		}
		int j = 1;
		for (auto i = mp.begin(); i != mp.end(); i ++, j ++) {
			ar[j].a = i -> first;
			ar[j].b = i -> second; 
//			cout << ar[j].a << " " << ar[j].b << "\n";
		}
		freopen("csp_2022_data.txt", "w", stdout);
		sort(ar + 1, ar + mp.size() + 1, cmp);
//		cout << ar[mp.size()].a << "\n";
		for (int i = 1; i <= mp.size(); i ++) {
			cout << ar[i].a << " " << ar[i].b << "\n";
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	OI::run();
	return 0;
}



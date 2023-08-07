#include <bits/stdc++.h>
using namespace std;
int T;

namespace Mker {
	typedef unsigned long long ull;
	ull SA, SB, SC, p = -1;
	int base;
	void init(){scanf("%llu%llu%llu%d", &SA, &SB, &SC, &base); p = p << (65 - base) >> (65 - base);}
	ull rand() {
		ull now = SC; now += !(now & 1);
	    SA ^= SA << 32, SA ^= SA >> 13, SA ^= SA << 1;
	    ull t = SA;
		return SA = SB, SB = SC, SC ^= t ^ SA, (now & p) + p + 1;
	}
}
typedef unsigned long long ull;
int main() {
	scanf("%d", &T); Mker::init(); // 不要忘记 init
//	cout << Mker::base << endl; 你可以通过这种方式输出得到 base 的值 
	while (T--) {
		unsigned long long k = Mker::rand(); // 通过这种方式，获得一次询问的 k
        ull tmp;
        tmp = (k + 1) / 2;
        tmp = floor(sqrt(tmp * 2 + sqrt(tmp * 2)));
        ull ans = (tmp * (tmp + 1) * (2 * tmp + 1)) / 6;
        ans += ((k + 1) / 2 - tmp * (tmp + 1) / 2) * tmp;
        cout << ans << "\n";
//		cout << k << endl;  k 以调试代码 
	}
	return 0;
}

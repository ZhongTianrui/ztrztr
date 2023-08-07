#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	long long cnt = 0;
	long long n; cin >> n;
    long long a[50] = {}, j = 0;
    while (n > 0) {
		a[j] = n % 2;
		n /= 2;
		j ++;
	}
	if (n % 2) cout << -1;
    else {
        for (int i = j - 1; i >= 0; j --) {
            if (a[i]) cout << pow(2, j);
        }
    }
	return 0;
}
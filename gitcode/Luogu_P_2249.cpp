#include <bits/stdc++.h>
using namespace std;
bool check(int n, int a[], int x) {
	if (a[n] == x) return 1;
	else return 0;
}

int find(int a[], int n, int x) {
    int ans = -1;
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid, a, x)) {
            r = mid - 1;
        }
		else if (x > a[mid]) l = mid + 1;
		else r = mid - 1;
	}
	return (a[l] == x ? l : -1);
}
int main() {	
	cin.tie(0); cout.tie();
	int n, a[100005], x;
	cin >> n >> x;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	while (x --) {
	    int xx; cin >> xx;
	    cout << (a[lower_bound(a + 1, a + n + 1, xx) - a] == xx ? lower_bound(a + 1, a + n + 1, xx) - a : -1) << " ";
	}
	return 0;
}
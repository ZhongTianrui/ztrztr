#include <bits/stdc++.h>
using namespace std;
int a[1005][2005];
int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
    	int x, y, z; cin >> x >> y >> z;
    	a[x][y] = z;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long a, b, ans;
    cin >> a >> b;
	if(a >= 0 && b >= 0) cout << (max(a, b));
	else if(a <= 0 && b <= 0) cout << (max(-a, -b));
	else if(a < 0 && b > 0) cout << (min(-a, b) + b - a);
	else cout << (min(a, -b) + a - b);
    return 0;
}
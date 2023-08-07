#include <bits/stdc++.h>

using namespace std;
long long popcnt(long long n) {
    int count = 0;
while(n != 0)
{
    if(n % 2 == 1)
    {
        count++;
        if (count >= 3) return count;
    }
    
    n = n >> 1;
}
return count;
}
long long popls(long long n) {
    int count = 0, i = 0;
while(n != 0)
{
    
    if(n % 2 == 1)
    {
        return i;
        count = i;
    }
    i ++;
    n = n >> 1;
}

return count;
}
long long mp(long long x) {
    long long sum = 1;
    for (int i = 1; i <= x; i ++) {
        sum *= 2;
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T --) {
        long long n; cin >> n;
        if (popcnt(n) >= 3) cout << "No,Commander\n";
        else {
            
                if (popcnt(n) == 1) {
                    cout << n + 1 << "\n";
                }
                else if (popcnt(n) == 2) {
                    cout << n - mp(popls(n)) + mp(popls(n) + 1) << "\n";
                } else cout << 1 << "\n";
            }
    }
    return 0;
}
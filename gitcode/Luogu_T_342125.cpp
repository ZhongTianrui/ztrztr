#include <bits/stdc++.h>

using namespace std;
/*
*/
long long n;
double k;
struct node{
    long long id;
    double sum;
}a[100005];
bool cmp(node x, node y) {
    if (x.sum != y.sum) return x.sum > y.sum;
    else return x.id < y.id;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= k; j ++) {
            long long x; cin >> x;
            a[i].sum += x;
        }
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    cout << a[1].id << "\n" << a[2].id; 
    return 0;
}
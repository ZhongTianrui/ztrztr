#include <bits/stdc++.h>

using namespace std;
/*
*/
int n, arr[1000005];
void merge_sort(int *a, int l, int r) {
    if (r - l <= 1) return;
    int mid = l + ((r - l) >> 1);
    merge_sort(a, l, mid), merge_sort(a, mid, r);
    int tmp[10005] = {}; 
                        
    merge(a + l, a + mid, a + mid, a + r, tmp + l); 
    for (int i = l; i < r; ++i) a[i] = tmp[i];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> arr[i];
    merge_sort(arr, 1, n + 1);
    for (int i = 1; i <= n; i ++) cout << arr[i] << " ";
    return 0;
}
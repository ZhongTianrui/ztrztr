#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    long long y, w;
    char x, z;
    scanf("%c %lld %c %lld", &x, &y, &z, &w);
    if (!(('a' <= x && x <= 'z') || ('a' <= z && z <= 'z')) || x != z) {
        cout << "Invalid\n-1";
        return 0;
    }
    if (y > w) swap(y, w);
    cout << "valid\n";
    cout << w - y + 1;
    return 0;
}
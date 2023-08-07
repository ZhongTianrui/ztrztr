#include <bits/stdc++.h>

using namespace std;
/*
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string a, b, k;
    long long a_i, b_i;
    cin >> a >> b;
    long long k_i;
    a_i = stoll(a.c_str());
    b_i = stoll(b.c_str());
//    k = b.substr(b.size() - 6, 6);
//    k_i - abs(stoll(k.c_str()) - a_i);
    long long tmp_i, tmp_i2;
    string tmp = "", tmp2 = "";
    for (int i = 0; i < 12 - b.size(); i ++) {
        if (i == 0) tmp += '1';
        else tmp += '0';
    }
    tmp += b.substr(b.size() > 12 ? b.size() - 12 : 0, b.size() - 6);
    tmp += a;
    tmp_i = stoll(tmp.c_str());
    tmp2 = tmp;
    tmp_i2 = stoll(tmp2.c_str());
    long long temp = llabs(tmp_i - 1000000);
    if (to_string(temp).size() < 12) {
        temp = llabs(tmp_i - b_i);
    } else {
        temp = llabs(tmp_i - 1000000 - b_i);
    }
//    cout << tmp << " " << to_string(abs(tmp_i - 1000000 - b_i)) <<"\n";
//    
//    cout << min(llabs(tmp_i - b_i), temp);
cout << min(llabs(tmp_i - b_i), temp);

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;

    int cntRow = (n + x - 1) / x;
    int cntCol = (m + y - 1) / y;

    int days = (cntRow * cntCol + k - 1) / k; // 向上取整
    int totalPoints = (cntRow - 1) * (cntCol);

    cout << "至少需要的天数：" << days << endl;
    cout << "至少需要撒点的数量：" << totalPoints << endl;

    return 0;
}

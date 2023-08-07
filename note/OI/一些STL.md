# 一些STL

## next_permutation

用于全排列。用法：`next_permutation(ARR_BEGIN_ADR, ARR_END_ADR)` 就可以得到下一个全排列。

### 题目

[T190986 [NOIP2004 普及组\] 火星人 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/T190986)

### 代码

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k, a[10005];
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i ++) {
        next_permutation(a + 1, a + n + 1);
    }
    for (int i = 1; i <= n; i ++) {
        cout << a[i] << " ";
    }
    return 0;
}
```

## nth_element

顾名思义，求一个数列的第 $i$ 项的用法：`nth_element(ARR_BEGIN_ADR, ARR_BEGIN_ADR + i, ARR_END_ADR)`

### 题目

[T191059 【深基9.例4】求第 k 小的数 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/T191059)

### 代码

```cpp
#include <bits/stdc++.h>

using namespace std;
int n, a[5000005], k;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    nth_element(a + 1, a + k + 1, a + 1 + n);
    cout << a[k + 1];
    return 0;
}
```


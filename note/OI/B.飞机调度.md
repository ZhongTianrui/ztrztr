# 题面

## 描述

Darko 因为成绩太差，大学毕业分配工作被派到了机场当调度员。

今天天气不好，本来原计划是从第 1 时刻到第 n 时刻各起飞一架飞机的，但是现在只能从第 k + 1 时刻到第 k + n 时刻各起飞一架飞机了。

这可让 Darko 十分焦急，因为飞机停留在地上也会有成本的，对于原计划在第 i 时刻的飞机，停留成本为 ci，如果安排它在第 j 时刻起飞，那么机场需要付出 ci * j 的成本。

Darko 的上司跟 Darko 说，机场不能付出太多成本，于是 Darko 决定调整飞机起飞的顺序，不一定按照原顺序依次起飞。

但是如果有乘客看到自己的飞机延误了而其它飞机没延误又会觉得不公平，会投诉。所以 Darko 要保证每架飞机都必须晚于原定起飞时间起飞。

在这样苛刻的条件下，Darko 想知道机场付出的总停留成本最少是多少。

## 输入

第一行，两个正整数 n, k

第二行，n 个正整数 ci，表示每架飞机的停留成本

## 输出

一行，一个正整数，表示答案

## 样例输入

```
3 2
4 2 1
```

## 样例输出

```
25
```

## 提示

对于 10% 的数据，1 <= k <= n <= 10

对于 30% 的数据，1 <= k <= n <= 20

对于 60% 的数据，1 <= k <= n <= 1000

对于 100% 的数据，1 <= k <= n <= 10^5, 1 <= c_i <= 10^6

# 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
struct pl {
	long long num;
	int id;
	bool operator <(const pl tmp) {
		return num > tmp.num;
	}
}
a[100005];
bool flag[100005];
int main() {
	int n;
	int k;
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a[i].num);
		a[i].id = i;
	}
	sort(a+1,a+n+1);
	long long ans = 0;
	int nowlow = k+1;
	for (int i = 1; i <= n; i++) {
		int j;
		for (j = nowlow; j <= k+n; j++) {
			if(flag[j-k] == 1) continue;
			if(j > a[i].id) {
				flag[j-k] = 1;
				if(j == nowlow) {
					for (int kkk03 = j+1; kkk03 <= k+n; kkk03++) {
						if(flag[kkk03-k] == 0) {
							nowlow = kkk03;
							break;
						}
					}
				}
				break;
			}
		}
		ans += a[i].num * j;
	}
	cout << ans << "\n";
	return 0;
}
```


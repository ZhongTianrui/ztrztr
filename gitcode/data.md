## 「ZTOI R1」字符串问题

### 题目描述

给定两个长度为 $n,m$ 的字符串 $s,t$。记字符串 $a$ 的下标在区间 $[l,r]$ 内的子串为 $a_{l\cdots r}$。

你需要回答 $Q$ 次询问，每次询问给出 $l_1,r_1,l_2,r_2$，请计算通过下面三种操作将 $s_{l_1\cdots r_1}$ 变为 $t_{l_2\cdots r_2}$ 的最小代价：

1. 在 $s$ 中添加一个字符 $x$。此操作需要花费 $A_x$ 的代价。
2. 在 $s$ 中删除一个字符 $x$。此操作需要花费 $B_x$ 的代价。
3. 在 $s$ 中将一个字符 $x$ 改为字符 $y$。此操作需要花费 $C_{x,y}$ 的代价。

特别地，如果 $A,B,C$ 中有元素为 $-1$，代表不能进行这个操作。

询问之间相互独立。

### 输入格式

第 $1\sim 26$ 行，一个大小为 $26\times 26$ 的整数矩阵，第 $i$ 行第 $j$ 列的元素为 $C_{i,j}$。

第 $27$ 行，一个长度为 $26$ 的整数数列，第 $i$ 项为 $A_i$。

第 $28$ 行，一个长度为 $26$ 的整数数列，第 $i$ 项为 $B_i$。

第 $29$ 行，三个整数 $n,m,q$。

第 $30$ 行，长度为 $n$ 的字符串 $s$。

第 $31$ 行，长度为 $m$ 的字符串 $t$。

第 $32\sim 32+q-1$ 行，每行四个整数 $l_1,r_1,l_2,r_2$。

### 输出格式

共 $q$ 行，每行一个整数代表询问的答案。特别地，若无法达成目标，输出 $-1$。

### 样例 #1

#### 样例输入 #1

```
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
20 20 20
acaaabbccabcabccabab
bbcabbccbaaaccaaccba
3 9 3 17
1 1 3 4
5 19 11 16
1 3 5 13
3 6 9 13
1 11 5 17
1 18 1 14
5 12 11 19
5 11 11 13
5 13 1 1
1 15 1 6
5 20 1 7
6 13 5 11
1 7 1 13
1 19 16 17
1 13 10 17
3 9 7 17
1 11 11 13
1 20 2 19
1 17 5 11
```

#### 样例输出 #1

```
10
1
9
7
2
8
9
5
5
8
9
9
2
9
17
6
7
8
9
10
```

### 提示

**样例解释**

即求 $s_{l_1\cdots r_1}$ 和 $t_{l_2\cdots r_2}$ 的编辑距离。

---

**数据范围**

- 子任务一（$30$ 分）：$1 \leq n,m,q\leq 100$。
- 子任务二（$20$ 分）：$l_2=r_2$。
- 子任务三（$20$ 分）：$n=2$。
- 子任务四（$30$ 分）：无特殊性质。

对于 $100\%$ 的数据，$1 \leq n\times m\leq 10^5$，$n,m\geq 1$，$1 \leq q\leq 10^5$，$1 \leq A_i,B_i,C_{i,j}\leq 10^9$，$1\le l_1\le r_1\le n$，$1\le l_2\le r_2\le m$。

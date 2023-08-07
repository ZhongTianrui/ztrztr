#include <bits/stdc++.h>

using namespace std;
/*
*/

// head存储链表头，e[]存储节点的值，ne[]存储节点的next指针，idx表示当前用到了哪个节点
int head, e[1005], ne[1005], idx;

// 初始化
void init()
{
    head = -1;
    idx = 0;
}

// 在链表头插入一个数a
void insert(int a)
{
    e[idx] = a, ne[idx] = head, head = idx ++ ;
}

// 将头结点删除，需要保证头结点存在
void remove()
{
    head = ne[head];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    init();
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        insert(x);
    }
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 30000;
int dis[30005],num[30005],fa[30005];
int t;
int find(int x)
{
	if(x == fa[x])	return x;//基础的并查集代码
	int k = fa[x];
	fa[x] = find(fa[x]);
	dis[x]+=dis[k];//更新dis的距离为原队头到队头的距离加上其到原队头的距离
	num[x] = num[k];//更新其所在列的数量
	return fa[x];
}
 
void merge(int x,int y)
{
	int r1 = find(x),r2 = find(y);
	if(r1!=r2)
	{
		fa[r1] = r2;
		dis[r1] = num[r2];//如思路所说,r1到新队头的距离等于原本那列原有的数量
		num[r2] += num[r1];//更新那一列的数量
		num[r1] = num[r2];
	}
}
int main()
{
	char c;
	int i,j;
	for(int i = 1;i<=30000;++i)
	{
		fa[i] = i;
		dis[i] = 0;
		num[i] = 1;	
	}	
	cin>>t;
	while(t--)
	{
		cin>>c>>i>>j;
		if(c=='M')
			merge(i,j);
		else
		{
			int r1 = find(i),r2 = find(j);
			if(r1!=r2)	cout<<-1<<endl;
			else{
				cout<<abs(dis[j]-dis[i])-1<<endl;
			}
		}
	}
	return 0;
}
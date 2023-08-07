
#include<cstdio>
#include<iostream>
#define M 100010
using namespace std;
int f[M][4][2][4],a[M][4],n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=3;j++)
        scanf("%d",&a[i][j]);
    f[1][1][0][1]=a[1][1];
    f[1][2][0][2]=a[1][2];
    f[1][2][1][2]=a[1][2];
    f[1][3][1][3]=a[1][3];
    for(int i=2;i<=n;i++)
      for(int j=1;j<=3;j++)
      {
        f[i][1][0][j]=max(f[i-1][2][1][j],f[i-1][3][1][j])+a[i][1];
        f[i][2][0][j]=f[i-1][3][1][j]+a[i][2];
        f[i][2][1][j]=f[i-1][1][0][j]+a[i][2];
        f[i][3][1][j]=max(f[i-1][1][0][j],f[i-1][2][0][j])+a[i][3];
      }
    int ans=0;
    for(int i=1;i<=3;i++)
      for(int j=1;j<=3;j++)
        if(i<j)ans=max(ans,f[n][i][0][j]);
        else if(j<i)ans=max(ans,f[n][i][1][j]);
    printf("%d",ans);
    return 0;
}
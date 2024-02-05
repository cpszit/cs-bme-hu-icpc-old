#include <stdio.h>

int n;
int list[301][301];
int c[301];
int visited[301];
int color[301];
int err=0;

void dfs(int p,int col)
{
  if (visited[p])
    {
      if (col!=color[p]) err=1;
      return;
    }
  visited[p]=1;
  color[p]=col;
  for (int i=0;i<c[p] && !err ;i++) dfs(list[p][i],!col);
}

int main()
{
  scanf("%d\n",&n);
  int i;
  for (i=1;i<=n;i++) c[i]=visited[i]=0;
  int a,b;
  while (scanf("%d %d\n",&a,&b)==2)
    {
      list[a][c[a]++]=b;
      list[b][c[b]++]=a;
    }
  dfs(1,0);
  if (err)
    {
      printf("YES\n");
    }
  else
    {
      printf("NO\n");
      int c1=0;
      for (i=1;i<=n;i++) c1+=color[i];
      int cc= c1 > n-c1 ? 1 : 0;
      printf("X:");
      for (i=1;i<=n;i++) if (color[i]==cc) printf(" %d",i);
      printf("\n");
    }
}









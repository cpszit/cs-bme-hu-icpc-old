#include <stdio.h>

int n, int *list[301], err=0;
int s[301],c[301],visited[301],int color[301];

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
  for (i=1;i<=n;i++)
    {
      c[i]=visited[i]=0;
      s[i]=10;
      list[i]=new int[10];
    }
  int a,b,*t;
  while (scanf("%d %d\n",&a,&b)==2)
    {
      if (c[a]==s[a])
	{
	  s[a]*=2;
	  t=new int[s[a]];
	  for (i=0;i<c[a];i++) t[i]=list[a][i];
	  delete list[a];
	  list[a]=t;
	}
      list[a][c[a]++]=b;
      if (c[b]==s[b])
	{
	  s[b]*=2;
	  t=new int[s[b]];
	  for (i=0;i<c[b];i++) t[i]=list[b][i];
	  delete list[b];
	  list[b]=t;
	}
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

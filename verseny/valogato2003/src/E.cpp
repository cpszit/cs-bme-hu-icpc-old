//
// Problem E: Tennis
//

#include <stdio.h>

int edges[100000][2];
int degree[10000];
int c[10000];
int *list1[10000],*list2[10000];
int visited[10000];

void traverse(int p)
{
  visited[p]=2;
  for (int i=0;i<degree[p];i++)
    {
      if (visited[list1[p][i]]!=2) traverse(list1[p][i]); 
    }
}
int findcycle(int p,int e)
{
  visited[p]=1;
  for (int i=0;i<degree[p];i++)
    {
      if (list2[p][i]!=e)
	{
	  if (!visited[list1[p][i]])
	    {
	      if (findcycle(list1[p][i],list2[p][i])) return 1;
	    }
	  else
	    {
	      return 1;
	    }
	}
    }
  return 0;
}

int main()
{
  int i,j,n,m;
  int p,q;
  for (;;)
    {
      scanf("%d %d\n",&n,&m);
      if (!n) break;
      for (i=0;i<n;i++) degree[i]=visited[i]=c[i]=0;
      for (i=0;i<m;i++)
	{
	  scanf("%d %d\n",&p,&q);
	  p--;q--;
	  edges[i][0]=p;
	  edges[i][1]=q;
	  degree[p]++;
	  degree[q]++;
	}
      for (i=0;i<n;i++)
	{
	  list1[i]=new int[degree[i]];
	  list2[i]=new int[degree[i]];
	}
      for (i=0;i<m;i++)
	{
	  p=edges[i][0];
	  q=edges[i][1];
	  list1[p][c[p]]=q;
	  list2[p][c[p]++]=i;
	  list1[q][c[q]]=p;
	  list2[q][c[q]++]=i;
	}
      for (i=0;i<n;i++)
	{
	  if (!visited[i])
	    {
	      if (!findcycle(i,-1)) break;
	      traverse(i);
	    }
	}
      if (i<n)
	{
	  printf("Suicide is possible.\n");
	}
      else
	{
	  printf("Suicides can be avoided.\n");
	}
      for (i=0;i<n;i++)
	{
	  delete [] list1[i];
	  delete [] list2[i];
	}

    }
}








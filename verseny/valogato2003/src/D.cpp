//
// Problem D: Billboard
//

#include <stdio.h>

int main()
{
  int k,n,t,c;
  int i,j;
  int x[1000],y[1000];
  int need[1000];
  int minv,maxv,l;
  for (;;)
    {
      scanf("%d %d\n",&k,&n);
      if (!k) break;
      minv=100000;maxv=-100000;
      for (i=0;i<n;i++)
	{
	  scanf("%d %d\n",x+i,y+i);
	  if (x[i]>y[i])
	    {
	      t=x[i];
	      x[i]=y[i];
	      y[i]=t;
	    }
	  if (x[i]<minv) minv=x[i];
	  if (y[i]>maxv) maxv=y[i];
	  if (y[i]-x[i]+1<k) need[i]=y[i]-x[i]+1; else need[i]=k;
	}
      l=maxv-minv;
      for (i=0;i<n;i++) {x[i]-=minv;y[i]-=minv;}
      c=0;
      for (i=0;i<=l;i++)
	{
	  for (j=0;j<n;j++)
	    {
	      if (i>=x[j] && i<=y[j] && i>=y[j]-need[j]+1) break;
	    }
	  if (j<n)
	    {
	      c++;
	      for (j=0;j<n;j++) if (i>=x[j] && i<=y[j]) need[j]--;
	    }
	}
      printf("%d\n",c);
    }
}

#include <stdio.h>
#include <math.h>

#define INF 1e10;

int main()
{
  FILE *f=fopen("cheese.in","r");
  int x[102],y[102],z[102],r[102],ready[102];
  int i,j,n,cs=1;
  double dist[102][102],d[102];
  for (;;)
    {
      fscanf(f,"%d",&n);
      if (n==-1) break;
      for (i=0;i<n;i++) fscanf(f,"%d %d %d %d",x+i,y+i,z+i,r+i);
      fscanf(f,"%d %d %d",x+n,y+n,z+n); r[n++]=0;
      fscanf(f,"%d %d %d",x+n,y+n,z+n); r[n++]=0;
      for (i=0;i<n;i++)
	for (j=0;j<n;j++)
	  {
	    int dx=x[i]-x[j],dy=y[i]-y[j],dz=z[i]-z[j];
	    dist[i][j]=sqrt(dx*dx+dy*dy+dz*dz)-r[i]-r[j];
	    if (dist[i][j]<0) dist[i][j]=0;
	  }
      int v=n-2;
      for (i=0;i<n;i++) {d[i]=INF;ready[i]=0;}
      d[n-2]=0;
      while (v!=n-1)
	{
	  ready[v]=1;
	  int mp=-1;
	  for (i=0;i<n;i++)
	    {
	      if (d[i]>d[v]+dist[v][i]) d[i]=d[v]+dist[v][i];
	      if (!ready[i] && (mp==-1 || d[i]<d[mp])) mp=i;
	    }
	  v=mp;
	}
      printf("Cheese %d: Travel time = %d sec\n",cs++,(int)(10*d[n-1]+0.5));
    }
}


























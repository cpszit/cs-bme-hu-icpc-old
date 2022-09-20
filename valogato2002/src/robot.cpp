//
// Problem H: Robots
//

#include <stdio.h>
#include <math.h>

#define MAXN 500
#define INF 10000000
#define dist(_x1,_y1,_x2,_y2) (sqrt( (_x1-_x2)*(_x1-_x2) + (_y1-_y2)*(_y1-_y2) ))
#define min(x,y) ((x)<(y)?(x):(y))
	  
int main()
{
  int i,j,k,n;
  int x1,x2,y1,y2;
  int x[MAXN+2];
  int y[MAXN+2];
  double d1[MAXN+2],d2[MAXN+2];
  double od1[MAXN+2],od2[MAXN+2];
  for (;;)
    {
      scanf("%d\n",&n);
      if (!n) break;
      scanf("%d %d\n",&x1,&y1);
      scanf("%d %d\n",&x2,&y2);
      for (i=0;i<n;i++) scanf("%d %d\n",x+i,y+i);
      x[n]=x1;x[n+1]=x2;
      y[n]=y1;y[n+1]=y2;
      for (i=0;i<n+2;i++) d1[i]=d2[i]=INF;
      d1[n+1]=dist(x1,y1,x[0],y[0]);
      d2[n]=dist(x2,y2,x[0],y[0]);
      for (i=1;i<n;i++)
	{
	  for (j=0;j<n+2;j++) {od1[j]=d1[j];od2[j]=d2[j];d1[j]=INF;d2[j]=INF;}
	  for (j=0;j<n+2;j++)
	    {
	      if (od1[j]<INF)
		{
		  d1[j]=min(d1[j],od1[j]+dist(x[i-1],y[i-1],x[i],y[i]));
		  d2[i-1]=min(d2[i-1],od1[j]+dist(x[j],y[j],x[i],y[i]));
		}
	      if (od2[j]<INF)
		{
		  d2[j]=min(d2[j],od2[j]+dist(x[i-1],y[i-1],x[i],y[i]));
		  d1[i-1]=min(d1[i-1],od2[j]+dist(x[j],y[j],x[i],y[i]));
		}
	    }
	}
      double best=INF;
      for (j=0;j<n+2;j++)
	{
	  best=min(best,d1[j]);
	  best=min(best,d2[j]);
	}
      printf("%d\n",(int)best);
    }
}

  







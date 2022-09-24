//
// Problem B: Cable
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  double length[10000];
  int n,k,i,j;
  for (;;)
    {
      scanf("%d %d\n",&n,&k);
      if (!n) break;
      for (i=0;i<n;i++)
	{
	  double z;
	  char buf[100];
	  fgets(buf,100,stdin);
	  length[i]=strtod(buf,NULL);
	}
      double u=200*1000;
      double l=0;
      double x;
      while ((fabs(u-l))>0.00001)
	{
	  x=(u+l)/2;
	  int c=0;
	  for (i=0;i<n;i++)
	    {
	      c+=(int)floor(length[i]/x);
	    }
	  if (c>=k) l=x; else u=x;
	}
      printf("%.2f\n",floor(x*100)/100);
    }
}



//
// Problem C: Necklace
//

#include <stdio.h>
#include <string.h>

int main()
{
  char buf[101000];
  int i,j,m,b,w,n;
  int total=0;
  int best[4][5],best2[4][5];
  scanf("%d\n",&m);
  for (j=0;j<m;j++)
    {
      total=0;
      gets(buf);
      n=strlen(buf);
      for (w=0;w<4;w++) for (b=0;b<5;b++) best[w][b]=-1000000;
      for (i=0;i<n;i++)
	{
	  if (buf[i]=='W')
	    {
	      for (w=0;w<4;w++)
		for (b=0;b<5;b++)
		  {
		    best2[w][b]=best[(w-1+4)%4][b]+1;
		  }	      
	      if (best2[1][0]<1) best2[1][0]=1;
	    }
	  else
	    {
	      for (w=0;w<4;w++)
		for (b=0;b<5;b++)
		  {
		    best2[w][b]=best[w][(b-1+5)%5]+1;
		  }	      
	      if (best2[0][1]<1) best2[0][1]=1;
	    }
	  for (w=0;w<4;w++) for (b=0;b<5;b++)
	    {
	      best[w][b]=best2[w][b];
	    }	  
	  if (best[3][2]>total) total=best[3][2];
	}
      printf("%d\n",n-total);
    }
}

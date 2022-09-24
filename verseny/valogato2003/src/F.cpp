//
// Problem F: Flip Game
//

#include <stdio.h>
#include <ctype.h>

/*
  0  1  2  3
  4  5  6  7
  8  9  10 11
  12 13 14 15
*/

int flip[16][5]={
  {0,1,4,4,4},
  {0,1,2,5,5},
  {1,2,3,6,6},
  {2,3,7,7,7},
  {0,4,5,8,8},
  {1,4,5,6,9},
  {2,5,6,7,10},
  {3,6,7,11,11},
  {4,8,9,12,12},
  {5,8,9,10,13},
  {6,9,10,11,14},
  {7,10,11,15,15},
  {8,12,13,13,13},
  {9,12,13,14,14},
  {10,13,14,15,15},
  {11,14,15,15,15}
};

int flip2[16];
int main()
{
  
  int d[0x10000];
  int dist[0x10000];
  int c=0,top=0;
  int b=0;
  int i,j,t;
  for (i=0;i<16;i++)
    for (j=0;j<5;j++)
      {
	flip2[i]|=1<<flip[i][j];
      }
  for (i=0;i<0x10000;i++) dist[i]=-1;
  d[top++]=0x0000;
  d[top++]=0xffff;
  dist[0]=dist[0xffff]=0;
  while (b<top)
    {
      for (i=0;i<16;i++)
	{
	  t=d[b]^flip2[i];
	  if (dist[t]==-1)
	    {
	      d[top++]=t;
	      dist[t]=dist[d[b]]+1;
	    }
	}
      b++;
    }
  int n;
  scanf("%d\n",&n);
  for (i=0;i<n;i++)
    {
      t=0;
      for (j=0;j<16;)
	{
	  int c=getchar();
	  if (!isspace(c))
	    {
	      if (c=='b') t|=1<<j;
	      j++;
	    }
	}
      if (dist[t]==-1)
	{
	  printf("Impossible\n");
	}
      else
	{
	  printf("%d\n",dist[t]);
	}
       
    }
}

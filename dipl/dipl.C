#include <stdio.h>
#include <string.h>

int main()
{
  char adj[10][10];
  char line[10][200];
  int used[10];
  int i,j,k;
  char *p,*q;
  int lang[256];
  for (i=0;i<10;i++)
    {
      for (k=0;k<10;k++) adj[i][k]=0;
      fgets(line[i],200,stdin);
      used[i]=0;
    }
  for (i=0;i<10;i++)
    {
      for (j=i;j<10;j++)
	{
	  p=strchr(line[i],' ')+1;
	  for (k=0;k<256;k++)lang[k]=0;
	  for (;*p!=' ';p++) lang[*p]=1;
	  q=strchr(line[j],' ')+1;
	  for (;*q!=' ';q++)
	    {
	      if (lang[*q]) adj[j][i]=adj[i][j]=*q;
	    }
	  if (*q!=' ') break;
	  char country[4];
	  strncpy(country,line[j],3);
	  country[3]=0;
	  if (!strstr(p,country)) adj[j][i]=adj[i][j]=0;
	}
    }
  int order[10];
  int pos=1;
  order[0]=0;
  used[0]=1;
  order[1]=-1;
  for (;;)
    {
      order[pos]++;
      if (order[pos]>=10)
	{
	  pos--;
	  if (pos==0)
	    {
	      printf("NO SOLUTION\n");
	      break;
	    }
	  used[order[pos]]=0;
	  continue;
	}

	  if (used[order[pos]] || 
	  (pos>0 && !adj[order[pos-1]][order[pos]]) ||
	  (pos==9 && !adj[order[0]][order[pos]]) )
	continue;
	  used[order[pos]]=1;
      pos++;
      if (pos==10)
	{
	  for (i=0;i<10;i++) printf("%d\n",order[i]);
	  for (i=0;i<10;i++)
	    {
	      int current=order[i];
	      int left=i?order[i-1]:order[9];
	      int right=i!=9?order[i+1]:order[0];
	      printf("%d %c %c%c%c %c\n",i+1,adj[current][left],
		     line[current][0],line[current][1],line[current][2],
		     adj[current][right]);
	      fflush(stdout);
	    }
	  break;
	}
      order[pos]=-1;

    }
}

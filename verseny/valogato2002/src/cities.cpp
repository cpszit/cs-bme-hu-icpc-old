//
// Problem B: Cities
// 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 2000
#define MAXM 25000

#define MAXC 10

struct city
{
  char name[MAXC+1];
  int e,type;
};

struct flight
{
  int from,to,date;
};

city cities[2*MAXM];
flight flights[MAXM];

int n,m;
char sortedcity[2][MAXN][MAXC+1];
int ec[2][MAXN],emax[2][MAXN];
flight *elist[2][MAXN];
int iso[MAXN],iso2[MAXN];
int visited[MAXN];
int citycomp(const void *a,const void *b)
{
  return strcmp(((city*)a)->name,((city*)b)->name);
}
int flightcomp(const void *a,const void *b)
{
  return (((flight*)a)->date)-(((flight*)b)->date);
}

int dfs(int c1,int c2)
{
  if (ec[0][c1]!=ec[1][c2]) return -1;
  int i;
  int c=ec[0][c1];
  visited[c1]=1;
  for (i=0;i<c;i++)
    {
      if (elist[0][c1][i].date!=elist[1][c2][i].date) return -1;
      if (iso[elist[0][c1][i].to]==-1 && iso2[elist[1][c2][i].to]==-1)
	{
	  iso[elist[0][c1][i].to]=elist[1][c2][i].to;
	  iso2[elist[1][c2][i].to]=elist[0][c1][i].to;
	}
      else
	{
	  if ( ( iso[elist[0][c1][i].to] != elist[1][c2][i].to ) ||
	       ( iso2[elist[1][c2][i].to] != elist[0][c1][i].to ) )
	    return -1;
	}
      if (!visited[elist[0][c1][i].to])
	if (dfs(elist[0][c1][i].to,elist[1][c2][i].to)==-1) return -1;
    }
  return 0;
}

int main()
{
  int i,j,k;
  char startname[2][MAXC+1];
  int start[2];
  start[0]=start[1]=-1;
  for (;;)
    {
      scanf("%d %d\n",&n,&m);
      if (!n) break;
      scanf("%s %s\n",startname[0],startname[1]);
      for (j=0;j<2;j++)
	{
	  for (i=0;i<m;i++)
	    {
	      int d1,d2;
	      scanf("%d:%d %s %s\n",&d1,&d2,
		    &cities[i*2].name,&cities[i*2+1].name);
	      flights[i].date=d1*60+d2;
	      cities[i*2].e=cities[i*2+1].e=i;
	      cities[i*2].type=0;
	      cities[i*2+1].type=1;
	    }
	  qsort(cities,2*m, sizeof(cities[0]),citycomp);
	  int c=-1;
	  for (i=0;i<2*m;i++)
	    {
	      if (!i ||  strcmp(cities[i].name,cities[i-1].name))
		{
		  c++;
		  strcpy(sortedcity[j][c],cities[i].name);
		}
	      if (!strcmp(startname[j],cities[i].name)) start[j]=c;
	      if (cities[i].type)
		flights[cities[i].e].to=c;
	      else
		flights[cities[i].e].from=c;
	    }
	  qsort(flights,m,sizeof(flights[0]),flightcomp);
	  for (i=0;i<n;i++)
	    {
	      emax[j][i]=10;
	      ec[j][i]=0;
	      elist[j][i]=new flight[emax[j][i]];
	    }
	  for (k=0;k<m;k++)
	    {
	      i=flights[k].from;
	      if (ec[j][i]==emax[j][i])
		{
		  emax[j][i]*=2;
		  flight *t=new flight[emax[j][i]];
		  memcpy(t,elist[j][i],sizeof(*elist[j][i])*ec[j][i]);
		  delete [] elist[j][i];
		  elist[j][i]=t;
		}
	      elist[j][i][ec[j][i]++]=flights[k];
	    }
	 }
      for (i=0;i<n;i++) iso[i]=iso2[i]=-1;
      for (i=0;i<n;i++) visited[i]=0;
      iso[start[0]]=start[1];
      iso2[start[1]]=start[0];
      if (dfs(start[0],start[1])==-1)
	{
	  printf("inconsistent\n");
	}
      else
	{
	  for (i=0;i<n;i++)
	    {
	      printf("%s %s\n",sortedcity[0][i],sortedcity[1][iso[i]]);
	    }
	}
      for (i=0;i<n;i++)
	{
	  delete [] elist[0][i];
	  delete [] elist[1][i];
	}
			  
     }
  
}

















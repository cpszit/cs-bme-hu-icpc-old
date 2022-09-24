//
// Problem C: Rock stars
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 50
#define MAXK 10000

#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

#define INF 10000000

struct event
{
  int city;
  int money;
  int startdate;
  int totalmoney;
};

int dist[MAXN][MAXN];
event events[MAXK];
int citycount[MAXN];
int *citylist[MAXN];
int needcity[MAXN];
int cityshort[MAXN];
int cmpdate(const void *a,const void *b)
{
  int r=((event*)a)->startdate-((event*)b)->startdate;
  if (r) return r;
  return ((event*)a)->money-((event*)b)->money;
}
int binsearch(int i,int maxdate)
{
  int left=0,right=citycount[i]-1;
  while (left<=right)
    {
      int m=(left+right+1)/2;
      if (events[citylist[i][m]].startdate+1<=maxdate)
	{
	  left=m;
	  if (left==right) return left;
	}
      else right=m-1;
    }
  return -1;
  
}

int main()
{
  int i,j,l,k,ec,n,m,t,d,x,y;
  for (;;)
    {
      int start=0;
      scanf("%d %d %d\n",&n,&m,&k);
      if (!n) break;
      for (i=0;i<n;i++)
	{
	  for (j=0;j<n;j++) dist[i][j]=INF;
	  citycount[i]=dist[i][i]=0;
	}
      for (i=0;i<m;i++)
	{
	  scanf("%d %d %d\n",&x,&y,&t);
	  x--;
	  y--;
	  dist[x][y]=min(dist[x][y],t);
	}
      for (l=0;l<n;l++)
	for (i=0;i<n;i++)
	  for (j=0;j<n;j++)
	      dist[i][j]=min(dist[i][j],dist[i][l]+dist[l][j]);
      int nc=0;
      for (i=0;i<k;i++)
	{
	  scanf("%d %d %d:%d %d\n",&j,&d,&x,&y,&t);
	  j--;
	  d--;
	  events[i].city=j;
	  events[i].startdate=d*24*60+x*60+y;
	  events[i].money=t;
	  events[i].totalmoney=0;
	  if (!citycount[j]++)
	    {
	      needcity[nc++]=j;
	    }
	}
      qsort(events,k,sizeof(*events),cmpdate);
      for (i=0;i<nc;i++)
	{
	  citylist[needcity[i]]=new int[citycount[needcity[i]]];
	  citycount[needcity[i]]=0;
	}
      for (i=0;i<k;i++)
	{
	  j=events[i].city;
	  citylist[j][citycount[j]++]=i;
	}
      int best=0;
      for (i=0;i<k;i++)
	{
	  if (dist[start][events[i].city]<=events[i].startdate)
	    events[i].totalmoney=events[i].money;
	  for (j=0;j<nc;j++)
	    {
	      int x=needcity[j];
	      l=binsearch(x,
		  events[i].startdate-dist[x][events[i].city]);
	      if (l>=0)
		{
		  int t=citylist[x][l];
		  events[i].totalmoney=max(events[i].totalmoney,
			 events[i].money+events[t].totalmoney);
		}
	    }
	  best=max(best,events[i].totalmoney);
	}
      printf("%d\n",best);
      for (i=0;i<nc;i++)  delete [] citylist[needcity[i]];
    }
  
}



















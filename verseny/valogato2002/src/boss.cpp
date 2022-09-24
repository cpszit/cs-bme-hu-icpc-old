//
// Problem G: Boss
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 4000
#define MAXM 40
#define MAXK 40
#define MAXC 10
#define INF 1000000

struct person
{
  char name[MAXC];
  char parent[MAXC];
  int id,parentid;
  int buildingnum,buildings[MAXK];
  int *children,cn,maxcn;
  int bestbuilding,bestcost,extracost;
};

int cost[MAXM];
int last[MAXM];
int extra[MAXM];
person persons[MAXN];

int cmpname(const void *a,const void *b)
{
  return strcmp(((person*)a)->name,((person*)b)->name);
}
int parentsort[MAXN];
int cmpparent(const void *a,const void *b)
{
  int x=*(int*)a;
  int y=*(int*)b;
  return strcmp(persons[x].parent,persons[y].parent);
}

int dfs(int c)
{
  int i,j,o=INF;
  for (i=0;i<persons[c].cn;i++) if (dfs(persons[c].children[i])==-1) return -1;
  int bb=0;
  for (i=0;i<persons[c].cn;i++)
    {
      person &p=persons[persons[c].children[i]];
      bb+=p.bestcost;
      if (last[p.bestbuilding]!=c) extra[p.bestbuilding]=0;
      last[p.bestbuilding]=c;
      extra[p.bestbuilding]+=p.extracost;
    }
  
  int s=INF,w,second=INF;
  for (j=0;j<persons[c].buildingnum;j++)
    {
      int t=persons[c].buildings[j];
      if (last[t]!=c) extra[t]=0;
      if (cost[t]+extra[t]<=s)
	{
	  second=s;
	  s=cost[t]+extra[t];
	  w=t;
	}
      else
	if (cost[t]+extra[t]<=second)
	  {
	    second=cost[t]+extra[t];
	  }
    }
  if (s==INF) return -1;
  persons[c].bestbuilding=w;
  persons[c].bestcost=bb+s;
  persons[c].extracost=second-s;
  return persons[c].bestcost;
}

int main()
{
  int i,j,k,n,m;
  int boss;
  for (;;)
    {
      scanf("%d %d\n",&n,&m);
      if (!n) break;
      for (i=0;i<m;i++) scanf("%d",cost+i);
      for (i=0;i<n;i++)
	{
	  scanf("%s %s %d",persons[i].name,persons[i].parent,&persons[i].buildingnum);
	  for (j=0;j<persons[i].buildingnum;j++)
	    {scanf("%d",persons[i].buildings+j);persons[i].buildings[j]--;}
	  persons[i].cn=0;
	  persons[i].maxcn=5;
	  persons[i].children=new int[persons[i].maxcn];
	  parentsort[i]=i;
	}
      qsort(persons,n,sizeof(*persons),cmpname);
      for (i=0;i<n;i++) persons[i].id=i;
      qsort(parentsort,n,sizeof(*parentsort),cmpparent);
      j=0;
      for (i=0;i<n;i++)
	{
	  while (strcmp(persons[j].name,persons[parentsort[i]].parent)) j++;
	  persons[parentsort[i]].parentid=j;
	}
      for (i=0;i<n;i++)
	{
	  if (persons[i].parentid!=persons[i].id)
	    {
	      k=persons[i].parentid;
	      if (persons[k].cn==persons[k].maxcn)
		{
		  persons[k].maxcn*=2;
		  int *t=new int [persons[k].maxcn];
		  memcpy(t,persons[k].children,sizeof(int)*persons[k].cn);
		  delete [] persons[k].children;
		  persons[k].children=t;
		}
	      persons[k].children[persons[k].cn++]=i;
	    }
	  else
	    {
	      boss=i;
	    }
	}
      for (i=0;i<m;i++) last[i]=-1;
      int s=dfs(boss);
      if (s>=INF)
	{
	  printf("No solution.\n");
	}
      else
	{
	  printf("%d\n",s);
	}
    }
}











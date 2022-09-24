//
// Problem E: Phone
//

#include <stdio.h>
#include <stdlib.h>

#define MAXN 5000
int f[MAXN],l[MAXN];

int cmp(const void *a,const void *b)
{
  return (*(int *)a)-(*(int*)b);
}

int main()
{
  int i,j;
  int n;
  for (;;)
    {
      scanf("%d\n",&n);
      if (!n) break;
      for (i=0;i<n;i++) scanf("%d\n",f+i);
      for (i=0;i<n;i++) scanf("%d\n",l+i);
      qsort(f,n,sizeof(*f),cmp);
      qsort(l,n,sizeof(*l),cmp);
      int s=0;
      for (i=0;i<n;i++) s+=(f[i]-l[i])*(f[i]-l[i]);
      printf("%d\n",s);
    }
}








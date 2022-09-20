#include <stdlib.h>
#include <iostream.h>
#include <stdio.h>

#define max(a,b) (a>b?a:b)
struct polynom { int d; int v[1000];} f,g,m,h,r; 
int main ( ) 
{
  int T;
  scanf("%d",&T);
  while (T--)
  {
    int i;
    cin>>f.d;
    f.d--;
    for (i=f.d;i>=0;i--) cin>>f.v[i];

    cin>>g.d;
    g.d--;
    for (i=g.d;i>=0;i--) cin>>g.v[i];

    cin>>h.d;
    h.d--;
    for (i=h.d;i>=0;i--) cin>>h.v[i];

    m.d=f.d+g.d;


    //for (i=f.d;i>=0;i--) printf(" %d",f.v[i]);

    for(i=0;i<=m.d;i++)
    {
      m.v[i]=0;
      for(int j=0;j<=i&&j<=f.d;j++) {
	if (i-j<=g.d) m.v[i]+=f.v[j]*g.v[i-j];
      }
      m.v[i]%=2;

      //for (int k=m.d;k>=0;k--) cout<<m.v[k];
      //cout<<"\n";

      r.d=m.d-h.d;
      for(int k=r.d;k>=0;k--)
	if (m.v[h.d+k])
	{
	  r.v[k]=1;
	  for(int j=k+h.d;j>=k;j--) m.v[j]^=h.v[j-k];
	}

    }
    while (m.d>1&&m.v[m.d]==0) m.d--; 
    printf("%d",m.d+1);
    for (i=m.d;i>=0;i--) printf(" %d",m.v[i]);
    printf("\n");
  }
  return 0;
}

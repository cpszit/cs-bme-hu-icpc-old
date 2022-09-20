#include <stdio.h>
void show(bool *v)
{
  int i;
  int d=0;
  for(i=0; i<1000; i++)
    if(v[i])
      d=i;
  printf("%d ", d+1);
  for(int i=d; i>=0; i--) {
    printf("%d%s", v[i]?1:0, (i==0)?"\n":" ");
  }
}

bool f[1010], g[1010], h[1010], s[1010];
int df, dh, dg;
int get()
{
  int r;
  scanf("%d", &r);
  return r;
}
void getvec(int &d, bool *v)
{
  int i;
  d=get()-1;
  //printf("d=%d\n", d);
  for(i=d; i>=0; i--)
    v[i]=(get()>0);
  for(i=d+1;i<1001; i++)
    v[i]=0;
}
void beolv()
{
  getvec(df, f);
  getvec(dg, g);
  getvec(dh, h);
}
void szamol()
{
  int i, j;
  for(i=0; i<1001; i++)
    s[i]=0;
  for(i=0; i<=dg; i++) {
    //ad
    if(g[i]) {
      for(j=0; j<dh; j++) {
	if(s[j])
	  if(f[j])
	    s[j]=false;
	  else
	    s[j]=true;
	else
	  if(f[j])
	    s[j]=true;
	  else
	    s[j]=false;
      }
    }
    //tol
    for(j=dh; j>=1; j--)
      f[j]=f[j-1];
    f[0]=0;
    //mod
    if(f[dh]) {
      //printf("mod...f=");
      //show(f);
      //printf("h=");
      //show(h);
      for(j=0; j<=dh; j++) {
	if(f[j])
	  if(h[j])
	    f[j]=false;
	  else
	    f[j]=true;
	else
	  if(h[j])
	    f[j]=true;
	  else
	    f[j]=false;
      }
    }
    //printf("tolva: ");
    //show(f);
  }
}
void kiir()
{
  show(s);
}
main()
{
  int n=get();
  for(int i=0; i<n; i++) {
    beolv();
    //show(f);
    //show(g);
    //show(h);
    szamol();
    kiir();
  }
}

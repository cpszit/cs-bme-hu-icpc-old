#include <stdio.h>
int n, h, f[25], d[25], t[24];
int get()
{
  int r;
  scanf("%d", &r);
  return r;
}
int maxfish, maxtimes[25];
int samp=0;
bool csinal()
{
  n=get();
  if(!n)
    return false;
  if(samp>0)
    printf("\n");
  samp++;
  maxfish=-1;
  h=get();
  for(int i=0; i<n; i++)
    f[i]=get();
  for(int i=0; i<n; i++)
    d[i]=get();
  for(int i=0; i<n-1; i++)
    t[i]=get();
  int fishes[25], times[25];
  int T;
  //printf("f[0]=%d\n", f[0]);
  for(int i=1; i<=n; i++) {
    T=h*12;
    for(int j=0; j<i-1; j++)
      T-=t[j];
    for(int j=0; j<i; j++)
      fishes[j]=f[j], times[j]=0;
    int mfishes=0;
    for(int j=0; j<T; j++) {
      int m=0;
      for(int k=0; k<i; k++)
	if(fishes[k]>fishes[m])
	  m=k;
      mfishes+=fishes[m];
      //printf("<%d> ", fishes[m]);
      times[m]++;
      fishes[m]-=d[m];
      if(fishes[m]<0)
	fishes[m]=0;
    }
    /*printf("%d [", mfishes);
    for(int j=0; j<i; j++)
      printf("%d, ", times[j]);
    printf("]\n");
    */

    if(maxfish>mfishes)
      continue;
    bool jobb=false;
    if(maxfish<mfishes)
      jobb=true;
    for(int j=0; j<n; j++) {
      if(times[j]<maxtimes[j]) {
	break;
      }
      if(times[j]>maxtimes[j]) {
	jobb=true;
	break;
      }
    }


     
    if(maxfish<mfishes) {
      maxfish=mfishes;
      for(int j=0; j<i; j++)
	maxtimes[j]=times[j];
      for(int j=i; j<n; j++)
	maxtimes[j]=0;
    }
  }
  for(int i=0; i<n; i++) {
    printf("%d%s", maxtimes[i]*5, (i==n-1)?"\n":", ");
  }
  printf("Number of fish expected: %d\n", maxfish);
  return true;
}

main()
{
  while(csinal());
}

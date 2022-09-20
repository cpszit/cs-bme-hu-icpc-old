#define debug
#include <stdio.h>
int meret;
int hossz;
int kupac[27];

void kupacol(int i) {
  int l=2*i+1;
  int r=2*i+2;
  int n; int t;
  if((l<meret)&&(kupac[l]<kupac[i]))
    n=l;
    else n=i;
  if((r<meret)&&(kupac[r]<kupac[n]))
    n=r;
  if(n!=i) {
    t=kupac[i];
    kupac[i]=kupac[n];
    kupac[n]=t;
    kupacol(n);
  }
}

void kupacepit() {
  //hossz mar elozoleg legyen beallitva
  int i;
  meret=hossz;
  for(i=hossz/2-1;i>=0;i--)
    kupacol(i);
}

void kupacrendez() {
  int i; int t;
  int p=meret;
  kupacepit();
  for(i=hossz-1;i>=1;i--) {
    t=kupac[i];
    kupac[i]=kupac[0];
    kupac[0]=t;
    meret--;
    kupacol(0);
  }
  meret=p;
}

int kupacbol() {
  int m;  
#ifdef debug
  if(meret<1) {fprintf(stderr,"underflow\n"); exit(-1);}
#endif
  m=kupac[0];
  kupac[0]=kupac[--meret];
  kupacol(0);
  return(m);
}

void kupacba(int x) {
  int i; int t;
  i=meret++;
  while((i>0)&&(kupac[t=(i-1)/2]>x)) {
    kupac[i]=kupac[t];
    i=t;
  }
  kupac[i]=x;
}

int process() {
  int s=0; int a; int b; int i;
  hossz=27;
  kupacepit();
  while(meret>=2) {
    b=kupacbol();
    a=b+kupacbol();
    if(b) s+=a;
    kupacba(a);
  }
  return(s);
}

int main() {
  int i; char c; int d; int e; int o;
  while(1) {
  for(i=0;i<27;i++) kupac[i]=0;
  scanf("%c",&c);
  d=1;
  e=0;
  while(c!='\n') {
    if(d>0) {
      if(d==1)
        {if(c=='E') d=2; else d=0;}
      else {
        if(d==2)
          {if(c=='N') d=3; else d=0;}
  	else
	  {if(d==3) { if (c=='D') d=4; else d=0;} else d=0;}
      }
    }
    if(c==95) c=64;
    c-=64;
    kupac[c]++;
    e+=8;
    scanf("%c",&c);
  }
  if(d==4) return(0);
  o=process();
  if(o==0) o=e/8;
  printf("%d %d %d.%d\n",e,o,e/o,(10*e/o)%10);
  }
}

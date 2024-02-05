#include <stdio.h>
int get()
{
  int r;
  scanf("%d", &r);
  return r;
}
int S[100], sl;
void show()
{
  for(int i=0; i<sl; i++)
    printf("%d ", S[i]);
  printf("\n");
}
bool jo(int x, int y, int i, int z, int m) {
  int s=1<<(2*i);
  int c=2*i-2;
  int pr;
  sl=1;
  S[0]=x;
  for(int a=0; a<2*i; a++) {
    //show();
    s>>=1;
    if(z&s) {
      S[sl]=S[sl-1];
      sl++;
    } else {
      switch((m>>c)&3) {
	case 0:
	  sl--;
	  S[sl-1]+=S[sl];
	  break;
	case 1:
	  sl--;
	  S[sl-1]=S[sl-1]-S[sl];
	  break;
	case 2:
	  sl--;
	  S[sl-1]*=S[sl];
	  break;
	case 3:
	  sl--;
	  if(S[sl]==0)
	    return false;
	  S[sl-1]=S[sl-1]/S[sl];
	  break;
      }
      c-=2;
    }
  }
    //show();

  return (sl==1)&&(S[0]==y);
}
void kiir(int i, int z, int m)
{
  if(i==0) {
    printf("Empty sequence\n");
    return;
  }
  
  int s=1<<(2*i);
  int c=2*i-2;
  for(int a=0; a<2*i; a++) {
    s>>=1;
    if(z&s)
      printf("DUP ");
    else {
      switch((m>>c)&3) {
	case 0:
	  printf("ADD");
	  break;
	case 1:
	  printf("SUB");
	  break;
	case 2:
	  printf("MUL");
	  break;
	case 3:
	  printf("DIV");
	  break;
      }
      printf((a!=2*i-1)?" ":"\n");
      c-=2;
    }
  }
}
bool jozar(int i, int z)
{
  int s=1<<(2*i);
  int d=0;
  for(int a=0; a<2*i; a++) {
    s>>=1;
    if(z&s)
      d++;
    else
      d--;
    if(d<0)
      return false;

  }
  return(d==0);
}
int C=1;
bool csinal()
{
  int n, x[10], y[10], i, j, k;
  n=get();
  if(!n)
    return false;
  if(C>1)
    printf("\n");
  printf("Program %d\n", C++);
  for(i=0; i<n; i++)
    x[i]=get();
  for(i=0; i<n; i++)
    y[i]=get();
  for(i=0; i<=5; i++) {
    for(int z=0; z<(1<<2*i); z++) {
      if(!jozar(i, z))
	continue;
      for(int m=0; m<1<<(2*i); m++) {
	int joo=true;
	for(j=0; j<n; j++) {
	  if(!jo(x[j], y[j], i, z, m)) {
	    joo=false;
	    break;
	  }
	}
	if(joo) {
	  kiir(i, z, m);
	  return true;
	}
      }
    }
  }
  printf("Impossible\n");
  return true;
}
main()
{
  //kiir(2, 12, 9);
//  printf("%d\n", jo(1, 0, 2, 12, 9));
 // return 0;
  while(csinal());
  return 0;
}


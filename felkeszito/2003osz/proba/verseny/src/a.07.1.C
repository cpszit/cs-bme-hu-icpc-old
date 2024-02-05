#include <stdio.h>

int p[2001];
int m[1001];
int mo[1001];
int md, dd, pd;
int i,j,k,l,n;

int main(void) {
  
  scanf("%d", &n);
  while (n--) {
  for (i=0;i<2001; i++) p[i]=0;
    scanf("%d", &md);
    for (i=md-1;i>=0;i--) { 
      scanf("%d", &m[i]);
    }
    scanf("%d", &pd);
    for (i=pd-1;i>=0; i--) {
      scanf("%d", &k);
      if (k)
        for (j=0;j<md;j++) {
	  p[j+i]=(p[j+i]+m[j])%2;
	}

    }
    scanf("%d", &dd);
    for (i=dd-1; i>=0; i--) {
      scanf("%d", &m[i]);
    }
    

    j=2001;
    do {
      while (!p[j]&&j>=0) j--;
      if (j<dd-1) {
        j++;
	printf("%d", j);
	j--;
	while (j>=0) { printf(" %d", p[j]); j--; }
	printf("\n");
	break;
      } else {
        for (k=dd-1; k>=0; k--) {
	  p[j-(dd-1)+k]^=m[k];
	}
      }
    } while (1);
  }
  
  return 0;
}


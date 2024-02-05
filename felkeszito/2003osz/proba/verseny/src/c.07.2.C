#include <stdio.h>

int dp[25][193];
int erk[25][193];
int h, n;
int t[25];
int k5[25];
int f1[25], d[25];
int fi[25][193];
int i,j,k,l;
int mx, mxk;

int main(void) {

  do {
    scanf("%d", &n);
    if (!n)
      break;
    scanf("%d", &h);
    for (i=0;i<n;i++)
      scanf("%d", &f1[i]);
    for (i=0;i<n;i++)
      scanf("%d", &d[i]);
    t[0]=0;
    for (i=1;i<n;i++)
      scanf("%d", &t[i]);
    for (i=0;i<n;i++) {
      fi[i][0]=0;
      for (j=1;j<193;j++) {
        if (f1[i]<=0) 
	  fi[i][j]=fi[i][j-1];
	else {
	  fi[i][j]=fi[i][j-1]+f1[i];
	  f1[i]-=d[i];
	}
      }
    }
    h=h*12+1;
    dp[0][0]=0;
    for (i=0;i<h;i++) {
      dp[0][i]=fi[0][i]; erk[0][i]=i;
    }
//    for (j=0;j<h;j++) printf("%d ", fi[1][j]);
    for (i=1;i<n;i++) {
      for (j=0;j<h;j++) {
        mx=0; mxk=0;
	l=j-t[i]-1; k=1;
	while (l>=0) {
//	  printf("M: %d %d %d %d", i, j, l, k);
//	  printf(" dp:%d fi:%d\n", dp[i-1][l], fi[i][k]);
	  if (mx<(dp[i-1][l]+fi[i][k])) {
	    mx=dp[i-1][l]+fi[i][k]; mxk=k;
	  }
	  k++; l--;
	}
	dp[i][j]=mx; erk[i][j]=mxk;
      }
    }
    
/*    for (i=0;i<n;i++) {
     for (j=0;j<h;j++) {
      printf("%d ",dp[i][j]);
     }
     printf("\n");
    }
*/    
    mx=0; h--; mxk=0;
    for (j=0;j<n; j++)
      if (dp[j][h]>mx) {
        mx=dp[j][h]; mxk=j;
      }
      
    for (i=mxk+1; i<n; i++)
      k5[i]=0;
      
    while (mxk>=0) {
      k5[mxk]=erk[mxk][h]; h=h-k5[mxk]-t[mxk]; mxk--;
    }
    
    for (i=0; i<n; i++) {
      printf("%d", k5[i]*5);
      if (i!=n-1)
        printf(", ");
      else
        printf("\n");
    }
    
    printf("Number of fish expected: %d\n\n", mx);
  } while (1);
  
  return 0;
}
      
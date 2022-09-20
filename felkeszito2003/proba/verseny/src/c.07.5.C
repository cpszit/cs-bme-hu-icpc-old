#include <stdio.h>

int dp[30][250];
int erk[30][250];
int h, n;
int t[30];
int k5[30];
int f1[30], d[30];
int fi[30][250];
int i,j,k,l,vm;
int mx, mxk;

int main(void) {


  vm=0;
  do {
    scanf("%d", &n);
    if (!n)
      break;
    if (vm) {
      printf("\n");
    } else {
      vm=1;
    }
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
      for (j=1;j<250;j++) {
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
    for (i=1;i<n;i++) {
      for (j=0;j<h;j++) {
        mx=0; mxk=0;
	l=j-t[i]-1; k=1;
	while (l>=0) {
	  if (mx<(dp[i-1][l]+fi[i][k])) {
	    mx=dp[i-1][l]+fi[i][k]; mxk=k;
	  }
	  k++; l--;
	}
	dp[i][j]=mx; erk[i][j]=mxk;
      }
    }
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
    
    printf("Number of fish expected: %d\n", mx);

  } while (1);
  
  return 0;
}
      
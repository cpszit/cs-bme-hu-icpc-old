#include <stdio.h>
#define MAXN 26
#define MAXT 193

int n,h,H, elso=1;
int f[MAXN], t[MAXN], d[MAXN], tim[MAXN][MAXT], fish[MAXN][MAXT];

int calcfish(int x, int h) {
    int maxh;
    if (d[x]) { 
	maxh = f[x]/d[x];
	if (f[x]%d[x]) maxh++;
	if (h>maxh) h=maxh;
    }    
    return h*f[x]-h*(h-1)/2*d[x];
}

int main() {
    int i,j,k, curfish;
    
    while (scanf("%d",&n), n) {
	if (elso) elso=0; else printf("\n");
	scanf("%d",&h);
	h*=12;
	H=h;
	for (i=0; i<n; i++) scanf("%d",&f[i]);
	for (i=0; i<n; i++) scanf("%d",&d[i]);
	for (i=0; i<n-1; i++) scanf("%d",&t[i]);
	
	for (i=n-1; i>=0; i--) {
	    for (j=h; j>=0; j--) {
		tim[i][j] = j;
		fish[i][j] = calcfish(i, j);
		if (i!=n-1) {
		    for (k=j-t[i]; k>=0; k--) {
		        curfish = calcfish(i,k) + fish[i+1][j-k-t[i]];
		        if (curfish>fish[i][j]) {
			    fish[i][j] = curfish;
			    tim[i][j] = k;
			}			
		    }
		}
	    }
	}
	
	for (i=0; i<n; i++) {
	    printf("%d",tim[i][h]*5);
	    h-=tim[i][h];
	    h-=t[i];
	    if (i!=n-1)
		printf(", ");
	    else
		printf("\n");	    
	}
	printf("Number of fish expected: %d\n", fish[
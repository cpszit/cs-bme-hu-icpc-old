#include <stdio.h>
#include <stdlib.h>

int compy(const void *a, const void *b) {
	return *((int*)b)-*((int*)a);
}

int main(void) {
	char st[10000];
	scanf("%s",&st);
	int f[256];
	int i,l,cl;
	float rat;
	while(strcmp(st,"END")) {
		for(i=0;i<256;f[i++]=0);
		i=0;
		l=0;
		cl=0;
		while(st[i]) f[st[i++]]++, l++;
		l*=8;
		qsort(&f[0],256,sizeof(int),compy);
		i=0;
		while(f[i]) i++;
		i--;
		while(i) {
			cl+=(f[i-1]+=f[i]);
			qsort(&f[0],i,sizeof(int),compy);
			i--;
		}
		rat=float(l)/cl;
		printf("%d %d %.1f\n", l, cl, rat);
		scanf("%s",&st);
	}
	return 0;
}
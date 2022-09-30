#include <stdio.h>
int tomb[101][101];
int q[101][101];
int w[101][101];

void sort(int& x, int& y) {
	if (y>x) {
		int z=y; y=x; x=z;
	}
}
int get(int x, int y)
{
	sort(x,y);
	return tomb[y][x];
}


void fill(int maxx, int maxy)
{
	sort(maxx, maxy);
	for (int i=1; i<=maxy; i++) {
		tomb[i][i]=1;
		q[i][i]=w[i][i]=0;
	}

	for (int y=1; y<=maxy; y++) {
		for (int x=y+1; x<=maxx; x++) {
			int minval=100000;
			int minx, miny;
			for (int j=1; j<=y/2; j++) {
				int val=get(x, j)+get(x, y-j);
				if (val<minval) {
					minval=val;
					minx=x; miny=j;
				}
			}
			for (int i=1; i<=x/2; i++) {
				int val=get(i, y)+get(x-i, y);
				if (val<minval) {
					minval=val;
					minx=i; miny=y;
				}
			}
			tomb[y][x]=minval;
			sort(minx, miny);

			q[y][x]=minx;
			w[y][x]=miny;
		}
	}
}

void trace(int x, int y)
{
	sort(x,y);
	printf("(%d,%d)\n", y,x);
	if (x!=y) {
		trace(q[y][x], w[y][x]);
		if (x==q[y][x]) trace(x, y-w[y][x]);
		else if (x==w[y][x]) trace(x, y-q[y][x]);
		else if (y==q[y][x]) trace(y, x-w[y][x]);
		else trace(y, x-q[y][x]);
	}
}

void main()
{
	FILE* f=fopen("cuts.in", "rt");
	int x,y;
	fscanf(f, "%d %d", &x, &y);
	fclose(f);

	fill(x, y);
	int res=get(x,y);
	trace(x,y);

	f=fopen("cuts.out", "w+t");
	fprintf(f, "%d", res);
	fclose(f);
}
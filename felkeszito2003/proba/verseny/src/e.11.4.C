#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float road[30][30];
struct
{
	int city;
	char name[20];
} city[30];
struct LINE
{
	char* name;
	float km;
} lines[30];
struct
{
	float	km;
	int	start;
} way[30][30];
int n,m,k,s;


int lcmp(const void *a, const void *b)
{
	LINE* aa=(LINE*)a;
	LINE* bb=(LINE*)b;

	float d=aa->km-bb->km;
	if (d!=0.0f)
		return d>0.0f;
	else
		return strcmp(aa->name,bb->name);
}


int main(void)
{
	int i,j,l;

	scanf("%d %d %d",&n,&m,&k);
	while (n)
	{
		// Torles
		for (i=0; i<30; i++)
		{
			for (j=0; j<30; j++)
				if (i==j)
					road[i][i]=0.0;
				else
					road[i][j]=1.0f/0.0f;
			city[i].city=0;
			city[i].name[0]=0;
		}


		// Beolvas graphot
		for (i=0; i<m; i++)
		{
			int i1,i2;
			float d;

			scanf("%d %d %f",&i1,&i2,&d);
			road[i1][i2]=road[i2][i1]=d;

		//	printf("Graf %d %d %f\n",i1,i2,d);
		}

		// Floyd
		for (i=0; i<n; i++)
			for (j=0; j<n; j++)
			{
				way[i][j].km=road[i][j];
				way[i][j].start=j;
			}
		for (l=0; l<n; l++)
			for (i=0; i<n; i++)
				for (j=0; j<n; j++)
				{
					float other=way[i][l].km+way[l][j].km;
					if (way[i][j].km>other)
					{
						way[i][j].km=other;
						way[i][j].start=way[i][l].start;
					}
				}

/*for (i=0; i<n; i++)
{
	for (j=0; j<n; j++)
		printf("%d %d ",(int)(way[i][j].km), way[i][j].start);
	printf("\n");
}*/

		// Be varosok
		for (i=0; i<k; i++)
		{
			scanf("%d",&j);
			city[j].city=1;
			scanf("%s",city[j].name);

		//	printf("Varos %d neve %s\n",j,city[j].name);
		}

		// Tablak
		scanf("%d",&s);
		for (i=0; i<s; i++)
		{
			int i1,i2,line=0;
			float d;

			scanf("%d %d %f",&i1,&i2,&d);

//			printf("tabla %d %d %f",i1,i2,d);

			for (j=0; j<n; j++)
				if (city[j].city && way[i1][j].start==i2)
				{
//printf("varos %s\n",city[j].name);
					lines[line].km=way[i1][j].km-d;
					lines[line].name=city[j].name;
					line++;
				}
			qsort(lines,line,sizeof(LINE),lcmp);

			for (j=0; j<line; j++)
				printf("%-20s %d\n",lines[j].name,(int)(0.5f+lines[j].km));

			if (i<s-1)
				printf("\n");
		}


		// Kov eset.
		scanf("%d %d %d",&n,&m,&k);
	}
	return 0;
}
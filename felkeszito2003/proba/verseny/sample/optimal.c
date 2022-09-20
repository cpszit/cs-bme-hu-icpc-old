/* SWERC'98 - Optimal Programs */
/* 10/05/98 - Matthias Ruhl    */

#include <stdio.h>

#define MAXLEN 10
#define MAXPTS 10
#define MAXVALUE 30000

FILE *inp;
int n,a[MAXPTS],b[MAXPTS],cmd[MAXLEN],bestcmd[MAXLEN];
int caseno=1,bestlen;
char *cmdstr[5] = { "ADD", "DIV", "DUP", "MUL", "SUB" };

int read_data()
{
  int i;

  fscanf(inp,"%d",&n);
  for(i=0;i<n;i++) fscanf(inp,"%d",a+i);
  for(i=0;i<n;i++) fscanf(inp,"%d",b+i);
  return n;
}

void try(int step, int stack, int *s[])
{
  int i,c,sn[MAXPTS],*tmp;

  if(step >= bestlen) return;

  for(i=0;i<n;i++)
    if(b[i] != s[stack][i]) break;
  if(i == n)
    {
      bestlen = step;
      for(i=0;i<step;i++) bestcmd[i] = cmd[i];
      return;
    }

  if(step == MAXLEN) return;

  for(c=0;c<5;c++)
    {
      if(c != 2 && stack < 1) continue;
      if(c == 2 && stack > MAXLEN-1-step) continue;
      cmd[step] = c;
      switch(c)
	{
	case 0: /* ADD */
	  for(i=0;i<n;i++) sn[i] = s[stack-1][i] + s[stack][i]; break;
	case 1: /* DIV */
	  for(i=0;i<n;i++)
	    if(s[stack][i] == 0)
	      goto skip;
	    else
	      sn[i] = s[stack-1][i] / s[stack][i];
	  break;
	case 2: /* DUP */
	  tmp = s[stack+1]; 
	  s[stack+1] = s[stack]; try(step+1,stack+1,s);
	  s[stack+1] = tmp;
	  continue;
	case 3: /* MUL */
	  for(i=0;i<n;i++) sn[i] = s[stack-1][i] * s[stack][i]; break;
	case 4: /* SUB */
	  for(i=0;i<n;i++) sn[i] = s[stack-1][i] - s[stack][i]; break;
	}
      for(i=0;i<n;i++)
	if(abs(sn[i]) > MAXVALUE) goto skip;
      tmp = s[stack-1];
      s[stack-1] = sn; try(step+1,stack-1,s);
      s[stack-1] = tmp;
    skip: ;
    }
}

void process_data()
{
  int *s[MAXPTS],i;

  s[0] = a;
  bestlen = MAXLEN + 1;
  try(0,0,s);

  printf("Program %d\n",caseno++);
  if(bestlen > MAXLEN)
    printf("Impossible");
  else
    if(bestlen == 0)
      printf("Empty sequence");
    else
      for(i=0;i<bestlen;i++,printf(" ")) printf("%s",cmdstr[bestcmd[i]]);
  printf("\n\n");
}

int main()
{
  inp = fopen("optimal.in","r");
  while(read_data())
    process_data();
  fclose(inp);
  return 0;
}

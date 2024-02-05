#include <stdio.h>
char freq[256];
char S[5100000];
int opt;
bool osszevon()
{
  int m1=10000000, m2=10000000, m1i=-1, m2i=-1;
  for(int i=0; i<256; i++) if(freq[i]>0)
  {
    if(freq[i]<m2) {
      if(freq[i]<m1) {
	m2=m1, m2i=m1i, m1i=i, m1=freq[i];
      } else
	m2=freq[i], m2i=i;
    }
  }
  if(m2i==-1)
    return false;
  //printf("...%d, %d\n");
  freq[m1i]+=m2;
  freq[m2i]=0;
  opt+=freq[m1i];
}
bool sor()
{
  char *s=S;
  scanf("%s", s);
  if(!strcmp(s, "END"))
    return false;
  for(int i=0; i<256; i++)
    freq[i]=0;
  int l=0;
  opt=0;
  for(;*s;s++)
    freq[*s]++, l++;
  int n=0;
  while(osszevon())
    n++;
  if(n==0)
    opt=l;
  
  printf("%d %d %.1f\n", l*8, opt, ((float)l*8)/((float)opt));

  return true;
}
int main()
{
  while(sor());
  return 0;
}

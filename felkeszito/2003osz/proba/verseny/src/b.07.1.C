#include <stdio.h>

int prob[256];
int i,j,k;
int n, l;
char c;
char c1,c2,c3,c4;
int m1, m2, m1i, m2i;



int main(void) {

 while (1) {
   for (i=0;i<256;i++) prob[i]=0;n=0;
   c1=0; c2=0; c3=0; c4=0;
   while (1) {
     c=getchar();
     if (c=='\n')
       break;
     prob[c]++; n++;
     c1=c2; c2=c3; c3=c4; c4=c;
   }
//   printf("%c %c %c %c %d", c1, c2, c3, c4, n);
   if (n==3 && c4=='D' && c3=='N' && c2=='E')
     break;
     
   l=0;
     
   for (i=0;i<50;i++) {
     m1=2000000000; m2=2000000000; m1i=-1; m2i=-1;
     for (j=0; j<256; j++) {
       if (prob[j] && prob[j]<m1) {
         m2=m1; m2i=m1i; m1=prob[j]; m1i=j;
       } else if (prob[j] && prob[j]<m2) {
         m2=prob[j]; m2i=j;
       }
     }
     if (m2i==-1) 
       break;
     l+=(m1+m2);
     prob[m1i]=m1+m2;
     prob[m2i]=0;
   }
   
   printf("%d %d %.1lf\n", 8*n, l, ((double) (8*n))/l);
  }
  return 0;
 }
 
     
     
   
     
   
      
   
   
  

int max(int a,int b) { return a<b?b:a; }

void add(int* f,int *degf,int* g,int degg,int gshift) {
  int i;
  for (i=0;i<=degg;i++) f[i+gshift]^=g[i];
  *degf=max(*degf,degg+gshift);
  while (*degf>0 && f[*degf]==0) (*degf)--;
}

void writepol(int* f,int degf) {
  int i;
  printf("%d",degf+1);
  for (i=0;i<=degf;i++) printf(" %d",f[degf-i]);
  printf("\n");
}

void mod(int* f,int *degf, int* g,int degg) {
//  printf("%d %d\n",*degf,degg);
  while (*degf && (*degf)>=degg) {
//    writepol(f,*degf);
    add(f,degf,g,degg,*degf-degg);
  }  
}

void mul(int* f,int *degf,int* g,int degg) {
  int i,degz;
  int* z=(int*)malloc(sizeof(int)*2100);
  for (i=0;i<=*degf;i++) z[i]=f[i];
  for (i=0;i<=*degf;i++) f[i]=0; 
  degz=*degf; *degf=0;
  for (i=0;i<=degg;i++)
    if (g[i]) add(f,degf,z,degz,i);
  free(z);
}

int main(void)
{
  int c,i,n,degf,degg,degh;
  int f[2100],g[2100],h[2100];
  scanf("%d",&n);
  for (c=0;c<n;c++) {
    scanf("%d",&degf);
    for (i=0;i<degf;i++) scanf("%d",&(f[degf-1-i]));
    scanf("%d",&degg);
    for (i=0;i<degg;i++) scanf("%d",&(g[degg-1-i]));
    scanf("%d",&degh);
    for (i=0;i<degh;i++) scanf("%d",&(h[degh-1-i]));
    degf--;degg--;degh--;
    
/*    writepol(f,degf);
/    add(f,&degf,g,degg,0);
    writepol(f,degf);
    add(f,&degf,g,degg,0);
    writepol(f,degf);*/
    mul(f,&degf,g,degg);
//    writepol(f,degf);
    mod(f,&degf,h,degh);
    writepol(f,degf);
//    printf("\n");
  }
  
  return 0;
}

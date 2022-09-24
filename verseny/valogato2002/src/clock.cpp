//
// Problem A: Clock
//

#include <stdio.h>

int main()
{
  int i,j,x,y,t1,t2;
  for (;;)
    {
      scanf("%d:%d",&x,&y);
      t1=(x*60+y)*11;
      scanf("%d:%d",&x,&y);
      t2=(x*60+y)*11;
      if (!t1&&!t2) break;
      if (t2<t1) t2+=24*60*11;
      j=0;
      for (i=0;i<44;i++)
	{
	  if (i*60*12 > t1 && i*60*12 < t2 ) j++;
	}
      printf("%d\n",j);
    }
}

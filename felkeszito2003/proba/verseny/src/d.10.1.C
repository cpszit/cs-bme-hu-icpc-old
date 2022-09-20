#include <stdio.h>
#include <math.h>

main(){
  int i,j,k;
  
  int n;  // input szama
  int x[12];
  int y[12];
  
  int program=0;
  int stack[20];
  int stackhossz;
  int lepesek[20];
  int lepes;
  int ok,ok2;
  int szam,szamtemp,szammax;
  int temp;
  
  while(1){  // input esetek
    program++;
    scanf("%d",&n);
    if(n==0) break;
    for(i=1;i<=n;i++) scanf("%d",&x[i]);
    for(i=1;i<=n;i++) scanf("%d",&y[i]);
    lepes=0;
    ok=1;
    for(i=1;i<=n;i++) if(x[i]!=y[i]) ok=0;
    if(ok==1){
      printf("Program %d\n",program);
      printf("Empty sequence\n\n");	   
      continue;
    }
    else{ //tobbi eset
      ok2=0;
      for(lepes=2;lepes<=4;lepes++){  // lepesszamra
        //printf("lepes=%d\n",lepes);
        lepesek[1]=3;
	szammax=1;// ennel kisebb kell
	for(i=1;i<=lepes-1;i++) szammax*=5;
	for(szam=0;szam<szammax;szam++){  // osszes program adott lepesre
	  szamtemp=szam;
	  for(i=lepes;i>=2;i--){ lepesek[i]=szamtemp%5+1; szamtemp/=5;}
	  ok=1;
	  for(i=1;i<=n;i++){  // minden bemenetre megnezzuk
	     stackhossz=1;
	     stack[1]=x[i];
	     for(j=1;j<=lepes;j++){  // a lepesek
	       if(lepesek[j]==1){ // ADD
	         if(stackhossz==1){ ok=0;break;}
		 temp=stack[stackhossz]+stack[stackhossz-1];
		 if(abs(temp)>30000) { ok=0; break;}
		 stack[stackhossz-1]=temp;
		 stackhossz--;       
	       }
	       if(lepesek[j]==2){  // DIV
	         if(stackhossz==1){ ok=0;break;}
		 if(stack[stackhossz]==0) {ok=0;break;}
		 temp=stack[stackhossz-1]/stack[stackhossz];
		 if(abs(temp)>30000) { ok=0; break;}
		 stack[stackhossz-1]=temp;
		 stackhossz--;              
	       }
	       if(lepesek[j]==3){ // DUP
	         if(stackhossz==0){ ok=0;break;}
		 stack[stackhossz+1]=stack[stackhossz];
		 stackhossz++;       
	       }
	       if(lepesek[j]==4){ // MUL
	         if(stackhossz==1){ ok=0;break;}
		 temp=stack[stackhossz]*stack[stackhossz-1];
		 if(abs(temp)>30000) { ok=0; break;}
		 stack[stackhossz-1]=temp;
		 stackhossz--;       
	       }
	       if(lepesek[j]==5){ // SUB
	         if(stackhossz==1){ ok=0;break;}
		 temp=stack[stackhossz-1]-stack[stackhossz];
		 if(abs(temp)>30000) { ok=0; break;}
		 stack[stackhossz-1]=temp;
		 stackhossz--;       
	       }	     
	     } // lepesek vege
	     if(ok==0) break;
	     //printf("szam=%d ",szam); 
	     //for(k=1;k<=lepes;k++) printf(" %d",lepesek[k]);
	     //printf("stackhossz=%d ",stackhossz); printf("top=%d\n",stack[stackhossz]);
	     if(stackhossz!=1) {ok=0; continue;}
	     if(stack[1]!=y[i]) {ok=0; continue;}
	  } // minden bemenetre ciklus vege
	  // teszt a szimulacio utan
	  if(ok==0) continue;	  
	  if(ok==1){
	    printf("Program %d\n",program);
	    for(i=1;i<=lepes;i++){
	      if(lepesek[i]==1) printf("ADD");
	      if(lepesek[i]==2) printf("DIV");
	      if(lepesek[i]==3) printf("DUP");
	      if(lepesek[i]==4) printf("MUL");
	      if(lepesek[i]==5) printf("SUB");
	      if(i!=lepes) printf(" ");	  
	    }
	    printf("\n\n");
	    ok2=1; break;
	  }
	}  // szam felsorolas ciklus
	if(ok2==1) break;
      } // lepesszam ciklus
      if(ok2==0){
        printf("Program %d\n",program);
	printf("Impossible\n\n");   
      
      }
    
    }  // else  lepes>0
  }    // while(1)
  return 1;
}
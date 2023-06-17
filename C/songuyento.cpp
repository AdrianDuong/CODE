#include<stdio.h> 
#include<math.h>
 int main(){ 
 int a,b ; 
 scanf("%d %d", &a, &b); 
 int start=sqrt(a); 
 start=(start*start==a);
 start : start+1 ; 
 int end=sqrt(b);
  int i; 
  printf("%d",end-start+1); 
  for(i=start;i<=end;i++){
   printf("\n%d",i*i); 
   } 
   return 0 ; 
   }

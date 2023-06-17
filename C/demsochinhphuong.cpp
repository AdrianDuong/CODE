#include<stdio.h> 
int main(){ 
int n,i; 
scanf("%d",&n); 
int m = 1;
 while(n>0){
  m*=n%10;
   n/=10; 
  } printf("%d",m); 
  return 0; 
  }

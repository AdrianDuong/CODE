#include<stdio.h> 
int main(){ 
int n; 
int a=0; 
scanf("%d",&n); 
do{ n=n/10; a=a+1; }
while(n>0); 
printf("%d",a); 
}

#include<stdio.h> 
main(){ 
int t; 
scanf("%d",&t); 
while(t--){ 
printf("\n"); 
int n; 
scanf("%d",&n); 
int i=2; 
while(n>1){ 
if(n%i==0){ 
printf("%d ",i);
n/=i; 
} 
else i++; 
} } 
return 0; 
}

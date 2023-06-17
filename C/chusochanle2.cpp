#include <stdio.h> 
#include <math.h> 
int main() {
int i; 
scanf("%d",&i); 
while(i--) {
int t,n,c=0,l=0; 
scanf("%d",&n); 
for( n;n>0;n=n/10) 
{ 
t=n%10; 
if (t%2==0) {c=c+1; } 
else l=l+1; 
} 
printf("%d %d\n ",l,c);
 } }

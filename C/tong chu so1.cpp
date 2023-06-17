#include <stdio.h> 
int main(){ 
int i; 
scanf("%d\n",&i); 
while (i--) { 
unsigned int n,m; 
scanf("%d", &n); 
int k=n; 
while(k/10 >= 1) {
 k/=10; m=k; 
 }
 if(m == (n%10)){ 
 printf("YES\n");
  }else printf("NO\n");
   } return 0; 
   }

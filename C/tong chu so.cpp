#include<stdio.h> 
main() { 
int i;
 scanf("%d\n",&i); 
 while (i--) { int m, s=0,n;
  scanf("%d",&n); 
  while (n/10 >= 1) 
  { m=n%10; s+=m; n=n/10; 
  } 
  s+=n; printf("%d\n",s); 
  } 
  }

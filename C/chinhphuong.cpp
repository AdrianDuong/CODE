#include<stdio.h> 
#include<math.h> 
main(){ 
	int t; 
	scanf("%d",&t); 
	while(t--){ 
	int n; 
	scanf("%d",&n); 
	int m = sqrt(n); 
	if(n==pow(m,2)) 
	printf("YES\n");
	 else printf("NO\n"); 
	 } 
	 return 0; }

#include<stdio.h>

	int main(){
	int n;
	scanf ("%d",&n);
	for (int i=1;i<=n;i++){
	int y=0;
	for (int j=1;j<=i;j++){
	int k=i+y;
		printf("%d ",k);
		y+=n-j;}
			printf("\n");
			}
			}
		

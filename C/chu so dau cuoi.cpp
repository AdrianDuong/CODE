#include<stdio.h>
	int main(){
		int n,s;
		int a;
		scanf("%d", &n);
		a=n%10;
		while(n>10){
			s=n%10;
			n/=10;}
			printf("%d %d", n, a);
		}


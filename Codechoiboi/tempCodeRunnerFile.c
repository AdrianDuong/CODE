#include<stdio.h>

int main() {
	int a[100];
	int n,m; scanf("%d", &n);
	for( int i= 0; i,n; i++) {
		scanf("%d", &a[i]);
	}
	
	for( int i=0; i<n; i++) {
		if( a[i] > a[i+1]) {
			a[i+1]=m;
			a[i]=a[i+1];
			a[i+1]=a[i];
		}
	}
	for( int i=0; i<n; i++) {
		printf("%d", a[i]);
	}
	return 0;
}

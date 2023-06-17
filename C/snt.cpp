#include<stdio.h>
#include<math.h>

	int snt(int n){
	for(int i=2;
	i<=sqrt(n);i++){
	if(n%i==0){
	return 0;
	break;	}
	}
	return 1;
	}
	int main(){
		int a=1;
		int dem=1;
		scanf("%d",&a);
		for(int j=2; dem<=a;j++){
			if(snt(j)==1){
			printf("%d\n", j);
			dem++;
			}
		}
	}

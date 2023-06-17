#include <stdio.h> 
int main(){ 
int N, number[10], i; 
scanf("%d", &N); 
if(N>0 && N<10){ 
for(i=1; i<11; i++){ 
number[i] = N*i; 
printf("%d ", number[i]); 
} 
} 
}

#include<stdio.h> 
int main (){ 
int a, b, c;
scanf("%d",&a); 
b=a; 
do { c = b % 10; }
while(b /= 10); 
printf("%d", c); 
a%=10; 
printf (" %d",a); 
return 0; 
}

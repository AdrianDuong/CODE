#include<stdio.h> 
int main(){ 
int t; 
scanf("%d",&t); 
int x=0,demchan=0,demle=0; 
while(t!=0){ 
x=t%10; 
if(x%2==0) demchan++; 
else demle++;
t/=10; 
} 
printf("%d %d",demle,demchan); 
return 0; 
}

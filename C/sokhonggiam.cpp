#include<stdio.h> 
#include<string.h> 
int main(){ 
int t,output; 
scanf("%d",&t); 
char a[18]; 
while(t>0){ 
scanf("%s",a); 
int str=strlen(a); 
int output=1; 
for(int i=0;i<str;i++){ 
for (int j=i+1;j<str;j++){ 
if(a[i]>a[j])output=-1;
 }
 } 
if(output==1)printf("YES\n"); 
else printf("NO\n"); t--; 
} 
}


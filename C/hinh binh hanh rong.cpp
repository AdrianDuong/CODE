#include<stdio.h> 
int main() { 
int n,m; 
scanf("%d%d", &n,&m);
 int k=0; 
 for(int i=1;i<=n;i++){ 
 for(int j=1;j<= m+k;j++){ 
 if(j<=k) printf("~");
  else{ 
  if(j==k+1||j==m + k || i==1|| i==n){ 
  printf("*"); }
  else{ printf("."); 
  } 
  } 
  } printf("\n");
   k++; } return 0;
    }

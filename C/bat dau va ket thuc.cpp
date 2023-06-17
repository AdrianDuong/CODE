#include <stdio.h> 
#include <math.h> 
int SNT(long x) { 
if (x == 1) { 
return (0); 
} 
else if (x == 2) { 
return (1); 
} else { int a = sqrt(x); 
for (int i = 2; i <= a; i++) { 
if (x % i == 0) { 
return (0); 
} 
} 
return (1); 
} } int main() { 
int t; 
scanf("%d", &t); 
while (t-- != 0) { 
long n; 
scanf("%ld", &n); 
if (SNT(n) == 0) { 
printf("NO\n"); } 
else { printf("YES\n"); 
} } 
return 0; }

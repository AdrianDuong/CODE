#include <stdio.h> 
#include <math.h> 
int main () { 
float D,a,b,c; 
scanf("%f %f %f",&a ,&b ,&c); 
D=b*b-4*a*c; 
if(a!=0); 
{ 
if (D<0) { 
printf("NO"); 
} 
else if(D==0) 
{ 
printf ("%.2f",-b/(2*a)); 
} else { 
printf ("%.2f %.2f ",(-b+sqrt(D))/(2*a),(-b-sqrt(D))/(2*a));
 }
 }
  return 0;
   }

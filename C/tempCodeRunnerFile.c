#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i=n; i>=-n;i--);
    printf("%d", i-1);
    return 0;
}
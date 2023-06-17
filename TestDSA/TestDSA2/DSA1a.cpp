#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    getchar();

    while (t--) {
        char expression[1001];
        fgets(expression, 1001, stdin);

        int len = strlen(expression);
        if (expression[len - 1] == '\n') {
            expression[len - 1] = '\0';
        }

        int n = strlen(expression);
        int stack[1001];
        int top = -1;

        for (int i = 0; i < n; i++) {
            if (expression[i] == '(') {
                stack[++top] = i;
            } else if (expression[i] == ')') {
                if (top >= 0) {
                    int start = stack[top--];
                    expression[start] = '0';
                    expression[i] = '1';
                } else {
                    expression[i] = '-1';
                }
            }
        }

        while (top >= 0) {
            int start = stack[top--];
            expression[start] = '-';
        }

        printf("%s\n", expression);
    }

    return 0;
}

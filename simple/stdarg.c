#include <stdio.h>
#include <stdarg.h>

int sum(int num, ...) {
    va_list ap;
    int arg, total = 0;
    va_start(ap, num);
    for (int i=0; i<num; i++) {
        arg = va_arg(ap, int);
        printf("%d ", arg);
        total += arg;
    }
    va_end(ap);
    return total;
}

int main()
{
    printf("= sum : %d\n", sum(3, 20, 30, 40));
    printf("= sum : %d\n", sum(5, 20, 30, 40, 50, 60));

    return 0;
}

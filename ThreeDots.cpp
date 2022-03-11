#include <stdarg.h>
#include <stdio.h>

void varargs_fn(int num, ...)
{
    va_list valst;

    va_start(valst, num);

    int n = 0;

    for (int i = 0; i < num; i++)
    {
        n = va_arg(valst, int);

        printf("%d\n", n);
    }

    va_end(valst);
}

int main()
{
    varargs_fn(5, 2, 4, 6, 8, 10);

    return 0;
}
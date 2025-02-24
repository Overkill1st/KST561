#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool *eratosten(int x)
{
    bool *selve = (bool *)malloc(sizeof(bool) * (x + 1));
    memset(selve, false, sizeof(bool) * (x + 1));
    for (int i = 2; i <= x; i++)
    {
        if (!selve[i])
        {

            for (int j = i + i; j <= x; j += i)
            {
                selve[j] = true;
            }
        }
    }
    return selve;
}

void print_numbers(bool *selve, int x)
{
    for (int i = 2; i <= x; i++)
    {
        if (!selve[i])
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int x;
    scanf("%d", &x);
    bool *selve = eratosten(x);

    print_numbers(selve, x);
    return EXIT_SUCCESS;
}

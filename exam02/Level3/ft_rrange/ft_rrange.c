#include <stdlib.h>
#include <stdio.h>

int *ft_rrange(int start, int end)
{
    int i = 0;
    int len = abs((end - start)) + 1;
    int *res = (int *)malloc(sizeof(int) * len);

    while (i < len)
    {
        if (start < end)
        {
            res[i] = end;
            end--;
            i++;
        }
        else
        {
            res[i] = end;
            end++;
            i++;
        }
    }
    return (res);
}

int main(void)
{
    int start, end;

    printf("Enter the start value: ");
    scanf("%d", &start);

    printf("Enter the end value: ");
    scanf("%d", &end);

    int *result = ft_rrange(start, end);

    if (result == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Array: ");
    for (int i = 0; i <= abs(end - start); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}
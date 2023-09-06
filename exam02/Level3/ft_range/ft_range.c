#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>

int			*ft_range(int start, int end)
{
	int			*range;
	int			i;

	if (start > end)
		range = (int*)malloc(sizeof(int) * (start - end));
	else
		range = (int*)malloc(sizeof(int) * (end - start + 1));
	i = 0;
	while (start != end)
	{
		range[i++] = start;
		start += (start > end) ? -1 : 1;
	}
	range[i] = start;
	return (range);
}

void print_array(int *arr, int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main()
{
    int start, end, size;
    int *range;

    start = 1;
    end = 3;
    size = end >= start ? end - start + 1 : start - end + 1;
    range = ft_range(start, end);
    printf("Range from %d to %d: ", start, end);
    print_array(range, size);
    free(range);

    start = -1;
    end = 2;
    size = end >= start ? end - start + 1 : start - end + 1;
    range = ft_range(start, end);
    printf("Range from %d to %d: ", start, end);
    print_array(range, size);
    free(range);

    start = 0;
    end = 0;
    size = end >= start ? end - start + 1 : start - end + 1;
    range = ft_range(start, end);
    printf("Range from %d to %d: ", start, end);
    print_array(range, size);
    free(range);

    start = 0;
    end = -3;
    size = end >= start ? end - start + 1 : start - end + 1;
    range = ft_range(start, end);
    printf("Range from %d to %d: ", start, end);
    print_array(range, size);
    free(range);

    return 0;
}
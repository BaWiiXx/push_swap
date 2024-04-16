#include "push_swap.h"

int	*ft_normalisation(t_stack *stack)
{
	int i;
	int j;
	int count;
	int *normal;

	i = 0;
	normal = ft_calloc(sizeof(int), stack->len + 1);
	while (i < stack->len)
	{
		j = 0;
		count = 0;
		while (j < stack->len)
		{
			if (stack->stack_a[i] > stack->stack_a[j])
				count++;
			j++;
		}
		normal[i] = count;
		i++;
	}
	free(stack->stack_a);
	normal[i] = -1;
	return (normal);
}
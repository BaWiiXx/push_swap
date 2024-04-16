#include "push_swap.h"

void	free_temp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

void	return_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

int free_stack(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	return (0);
}
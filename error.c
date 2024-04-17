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

void	return_error(t_stack *stack)
{
	free(stack->stack_a);	
	write(2, "Error\n", 6);
	exit(1);
}

int	free_stack(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	return (0);
}
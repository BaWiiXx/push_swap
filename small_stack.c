#include "push_swap.h"

void	two_sort(t_stack *stack)
{
	if (is_sorted(stack) == 1)
		return ;
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack);
}
void	three_sort(t_stack *stack)
{
	if (is_sorted(stack) == 1)
		return ;
	if (stack->stack_a[0] > stack->stack_a[1]
		&& stack->stack_a[0] > stack->stack_a[2])
		ra(stack);
	if (stack->stack_a[1] > stack->stack_a[2])
		rra(stack);
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack);
}

void	five_sort(t_stack *stack)
{
	int	i;

	i = 5;
	if (is_sorted(stack) == 1)
		return ;
	while (i > 3)
	{
		if (stack->stack_a[0] == 0 || stack->stack_a[0] == 1)
		{
			pb(stack);
			i--;
		}
		else
			ra(stack);
	}
	three_sort(stack);
	if (stack->stack_b[0] < stack->stack_b[1])
		sb(stack);
	pa(stack);
	pa(stack);
}

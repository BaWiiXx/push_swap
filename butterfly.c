#include "push_swap.h"

void	ft_butterfly(t_stack *stack, int chunk)
{
	int	i;
	int	tracker;
	int	elements_in_chunk;
	int	size;

	size = stack->len;
	tracker = size / chunk;
	elements_in_chunk = tracker;
	while (stack->stack_a[0] != -1)
	{
		i = 0;
		while (i < elements_in_chunk && stack->stack_a[0] != -1)
		{
			if (stack->stack_a[0] < tracker)
			{
				pb(stack);
				if (stack->stack_b[0] > (tracker - size / (chunk * 2)))
					rb(stack);
				i++;
			}
			else
				ra(stack);
		}
		tracker += elements_in_chunk;
	}
}
static void	ft_loop(t_stack *stack, int size, int i)
{
	while (stack->stack_b[i] != size && stack->stack_b[0] != -1)
		i++;
	if (stack_len(stack->stack_b) / 2 > i)
		rb(stack);
	else if (stack->stack_b[0] != -1)
		rrb(stack);
}

static void	sort_loop(t_stack *stack, int size)
{
	int	i;
	int	check;

	check = 0;
	while (stack->stack_b[0] != -1)
	{
		i = 0;
		if (stack->stack_b[0] == size - 1)
		{
			pa(stack);
			check = 1;
		}
		if (stack->stack_b[0] == size)
		{
			pa(stack);
			if (check == 1)
			{
				sa(stack);
				check = 0;
				size--;
			}
			size--;
		}
		ft_loop(stack, size, i);
	}
}

void	main_sort(t_stack *stack, int chunk, int size)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	if (is_sorted(stack) == 1)
		return ;
	ft_butterfly(stack, chunk);
	sort_loop(stack, size);
}

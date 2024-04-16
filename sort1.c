/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:31:44 by bdany             #+#    #+#             */
/*   Updated: 2024/04/16 17:00:46 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	first_elem;

	first_elem = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = first_elem;
	write(1, "sa\n", 3);
}
void	sb(t_stack *stack)
{
	int	first_elem;

	first_elem = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = first_elem;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	int	first_elem;

	first_elem = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = first_elem;
	first_elem = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = first_elem;
	write(1, "ss\n", 3);
}

void	pa(t_stack *stack)
{
	ft_memmove(stack->stack_a + 1, stack->stack_a, sizeof(int)
		* stack_len(stack->stack_a));
	stack->stack_a[0] = stack->stack_b[0];
	ft_memmove(stack->stack_b, stack->stack_b + 1, sizeof(int)
		* stack_len(stack->stack_b));
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	int	i;

	i = stack_len(stack->stack_b) + 1;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	i = 0;
	stack->stack_b[0] = stack->stack_a[0];
	while (stack->stack_a[i] >= 0)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
}
void	rb(t_stack *stack)
{
	int	i;
	int	first_elem;

	i = 0;
	first_elem = stack->stack_b[0];
	while (stack->stack_b[i] != -1)
	{
		if (stack->stack_b[i + 1] != -1)
			stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[i - 1] = first_elem;
	write(1, "rb\n", 3);
}

void	ra(t_stack *stack)
{
	int	i;
	int	first_elem;

	i = 0;
	first_elem = stack->stack_a[0];
	while (stack->stack_a[i] != -1)
	{
		if (stack->stack_a[i + 1] != -1)
			stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[i - 1] = first_elem;
	write(1, "ra\n", 3);
}
void	rra(t_stack *stack)
{
	int	size;
	int	temp;

	size = stack_len(stack->stack_a);
	temp = stack->stack_a[size - 1];
	while (size > 0)
	{
		if (stack->stack_a[size] != -1)
			stack->stack_a[size] = stack->stack_a[size - 1];
		size--;
	}
	stack->stack_a[size] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	int size;
	int temp;

	size = stack_len(stack->stack_b);
	temp = stack->stack_b[size - 1];
	while (size > 0)
	{
		if (stack->stack_b[size] != -1)
			stack->stack_b[size] = stack->stack_b[size - 1];
		size--;
	}
	stack->stack_b[size] = temp;
	write(1, "rrb\n", 4);
}
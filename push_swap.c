#include "push_swap.h"

void	choice_sort(t_stack *stack, int size)
{
	if (stack->len == 2)
		two_sort(stack);
	else if (stack->len == 3)
		three_sort(stack);
	else if (stack->len == 4)
		main_sort(stack, 1, size - 1);
	else if (stack->len == 5)
		five_sort(stack);
	else if (stack->len >= 6 && stack->len <= 100)
		main_sort(stack, 3, size - 1);
	else if (stack->len >= 101 && stack->len <= 200)
		main_sort(stack, 4, size - 1);
	else if (stack->len >= 201 && stack->len <= 300)
		main_sort(stack, 5, size - 1);
	else if (stack->len >= 301 && stack->len <= 400)
		main_sort(stack, 6, size - 1);
	else
		main_sort(stack, 8, size - 1);
}
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	**temp;

	if (argc == 1)
		return (0);
	stack.len = 0;
	temp = arg_to_temp(argc, argv);
	if (!temp)
		return (write(2, "Error.\n", 7));
	while (temp[stack.len])
		stack.len++;
	stack.stack_a = temp_to_stack(temp, &stack);
	if (!stack.stack_a)
		return (write(2, "Error.\n", 1));
	if (double_arg(&stack) == 1)
		return_error();
	stack.stack_b = ft_calloc(sizeof(int), stack.len + 1);
	stack.stack_a = ft_normalisation((&stack));
	if (!stack.stack_a || !stack.stack_b)
		return (0);
	stack.stack_b[0] = -1;
	choice_sort(&stack, stack.len);
}

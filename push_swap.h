#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h> //pa
# include <stdlib.h>

typedef struct s_stack
{
	int	len;
	int	*stack_a;
	int	*stack_b;
	int	pos_min;
	int	pos_max;
}		t_stack;

// PARSING
int		is_sorted(t_stack *stack);
char	**arg_to_temp(int argc, char **argv);
int		*temp_to_stack(char **temp, t_stack *stack);
int		*ft_normalisation(t_stack *stack);
int		double_arg(t_stack *stack);
int		stack_len(int *stack);

// SORT
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	rb(t_stack *stack);
void	ra(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	rrb(t_stack *stack);
void	rra(t_stack *stack);
// CHOICE SORT
void	two_sort(t_stack *stack);
void	three_sort(t_stack *stack);
void	five_sort(t_stack *stack);
void	main_sort(t_stack *stack, int chunk, int size);
// ERROR
void	free_temp(char **temp);
int		free_stack(t_stack *stack);
void	return_error(void);

#endif
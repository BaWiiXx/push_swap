#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack->stack_a[i] != -1)
	{
		j = i + 1;
		while (stack->stack_a[j] != -1)
		{
			if (stack->stack_a[i] > stack->stack_a[j])
				return (0);
			j++;
		}
		i++;
	}
	if (stack->stack_b[0] == -1)
		return (1);
	return (0);
}
int	stack_len(int *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack[i] != -1)
		i++;
	return (i);
}

static int	check_argument(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != '+') && (str[i] != '-') && (ft_isdigit(str[i]) == 0))
			return (1);
		if (str[i] == '+' && ft_strlen(&str[i]) == 1)
			return (1);
		if (str[i] == '-' && ft_strlen(&str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_whitespace(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (str[i])
	{
		j = 0;
		count = 0;
		while (str[i][j])
		{
			if (str[i][j] == 32 || (str[i][j] >= 8 && str[i][j] <= 13))
				count++;
			j++;
		}
		if (count == j)
			return (1);
		i++;
	}
	return (0);
}

static char	**split_str(char **temp, char *str)
{
	int	i;

	i = 0;
	temp = ft_split(str, ' ');
	free(str);
	while (temp[i])
	{
		if (check_argument(temp[i]) == 1)
		{
			free_temp(temp);
			return (NULL);
		}
		i++;
	}
	return (temp);
}

char	**arg_to_temp(int argc, char **argv)
{
	int		i;
	int		size;
	char	*str;
	char	**temp;

	i = 1;
	temp = NULL;
	while (i < argc)
	{
		size = ft_strlen(argv[i]);
		if (ft_strlen(argv[i]) == 0)
			return (0);
		size += 1;
		i++;
	}
	i = 1;
	str = ft_calloc(sizeof(char), size + 1);
	while (argv[i])
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	temp = split_str(temp, str);
	return (temp);
}

int	*temp_to_stack(char **temp, t_stack *stack)
{
	int	i;

	i = 0;
	stack->stack_a = ft_calloc(sizeof(int), stack->len + 1);
	if (!stack->stack_a)
		return (NULL);
	while (i < stack->len)
	{
		if (ft_atoi(temp[i]) == 2147483648)
		{
			free_temp(temp);
			free(stack->stack_a);
			write(2, "Error\n", 6);
			exit(1);
		}
		stack->stack_a[i] = ft_atoi(temp[i]);
		i++;
	}
	free_temp(temp);
	return (stack->stack_a);
}

int	double_arg(t_stack *stack)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (stack->stack_a[i])
	{
		j = i + 1;
		while (stack->stack_a[j])
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	if (stack->stack_a[0] == 0 && stack->stack_a[1] == 0)
		return (1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:16:02 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/05 12:38:51 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks if a string represents a valid integer number.
static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// Verifies that there are no duplicate values
// in the stack and exits on error if found.
static void	check_duplicates(t_stack_node *stack)
{
	t_stack_node	*tmp;
	t_stack_node	*compare;

	tmp = stack;
	while (tmp)
	{
		compare = tmp->next;
		while (compare)
		{
			if (tmp->value == compare->value)
				exit_with_error();
			compare = compare->next;
		}
		tmp = tmp->next;
	}
}

// Assigns an index to each node in the stack
// based on its value's relative order.
void	assign_indexes(t_stack_node *stack)
{
	t_stack_node	*tmp;
	t_stack_node	*compare;
	int				index;

	tmp = stack;
	while (tmp)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < tmp->value)
				index++;
			compare = compare->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
}

// Parses command-line arguments into a stack, validates them,
// checks for duplicates, assigns indexes, and returns the stack.

static void	fill_stack(t_stack_node **stack, char **args)
{
	long	num;
	int		i;

	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]))
			exit_with_error();
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			exit_with_error();
		stack_add_back(stack, stack_new((int)num));
		i++;
	}
}

t_stack_node	*parse_args(int argc, char **argv)
{
	t_stack_node	*stack_a;
	char			**args;

	stack_a = NULL;
	if (argc < 2)
		exit(0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	fill_stack(&stack_a, args);
	if (argc == 2)
		free_split(args);
	check_duplicates(stack_a);
	assign_indexes(stack_a);
	return (stack_a);
}

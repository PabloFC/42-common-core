/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:45:29 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/06 11:22:54 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*The stack_new function creates and initializes
 a new stack node with a given value. */
t_stack_node	*stack_new(int value)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		exit_with_error();
	new->value = value;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/*The stack_add_back function appends a new node
 to the end of a doubly linked list*/
void	stack_add_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

/*The stack_size function returns the number
 of nodes in a doubly linked list stack.*/
int	stack_size(t_stack_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

/*The `free_stack` function frees all nodes 
in a doubly linked list stack and 
sets the stack pointer to `NULL`.*/
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
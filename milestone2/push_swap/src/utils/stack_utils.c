/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:45:29 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/23 10:45:22 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *stack_new(int value)
{
    t_stack_node *new = malloc(sizeof(t_stack_node));
    if (!new)
        exit_with_error();
    new->value = value;
    new->index = 0;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void stack_add_back(t_stack_node **stack, t_stack_node *new)
{
    if (!*stack)
    {
        *stack = new;
        return;
    }
    t_stack_node *tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
}

int stack_size(t_stack_node *stack)
{
    int size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}

void free_stack(t_stack_node **stack)
{
    if (!stack || !*stack)
        return;
    t_stack_node *current = *stack;
    while (current)
    {
        t_stack_node *tmp = current->next;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}
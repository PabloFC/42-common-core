/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:22:44 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/22 13:17:44 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int find_min_index_pos(t_stack_node **stack)
{
    t_stack_node *tmp = *stack;
    int min_index = tmp->index;
    int min_pos = 0;
    int current_pos = 0;

    while (tmp)
    {
        if (tmp->index < min_index)
        {
            min_index = tmp->index;
            min_pos = current_pos;
        }
        tmp = tmp->next;
        current_pos++;
    }
    return (min_pos);
}

void move_to_top(t_stack_node **stack, int pos, bool is_stack_a)
{
    int size = stack_size(*stack);

    if (pos > size / 2)
    {
        while (pos++ < size)
        {
            if (is_stack_a)
                rra(stack, true);
            else
                rrb(stack, true);
        }
    }
    else
    {
        while (pos-- > 0)
        {
            if (is_stack_a)
                ra(stack, true);
            else
                rb(stack, true);
        }
    }
}

int get_max_index(t_stack_node *stack)
{
    int max = stack->index;
    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    return (max);
}

int get_min_index(t_stack_node *stack)
{
    int min = stack->index;
    while (stack)
    {
        if (stack->index < min)
            min = stack->index;
        stack = stack->next;
    }
    return (min);
}
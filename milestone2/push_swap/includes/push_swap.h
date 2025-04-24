/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:15:08 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/24 13:19:03 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct s_stack_node
{
    int value;
    int index;
    struct s_stack_node *next;
    struct s_stack_node *prev;
} t_stack_node;

/* ------------------- Operaciones ------------------- */
/* Swap */
void sa(t_stack_node **a, bool print);
void sb(t_stack_node **b, bool print);
void ss(t_stack_node **a, t_stack_node **b, bool print);

/* Push */
void pa(t_stack_node **a, t_stack_node **b, bool print);
void pb(t_stack_node **a, t_stack_node **b, bool print);

/* Rotate */
void ra(t_stack_node **a, bool print);
void rb(t_stack_node **b, bool print);
void rr(t_stack_node **a, t_stack_node **b, bool print);

/* Reverse Rotate */
void rra(t_stack_node **a, bool print);
void rrb(t_stack_node **b, bool print);
void rrr(t_stack_node **a, t_stack_node **b, bool print);

/* ------------------- Parsing ------------------- */
t_stack_node *parse_args(int argc, char **argv);

/* ------------------- Sort Utils ------------------- */
int find_min_index_pos(t_stack_node **stack);
void move_to_top(t_stack_node **stack, int pos, bool is_stack_a);
int get_max_index(t_stack_node *stack);
int get_min_index(t_stack_node *stack);

/* ------------------- Utils ------------------- */
/* Stack */
int stack_size(t_stack_node *stack);
bool is_sorted(t_stack_node *stack);
void free_stack(t_stack_node **stack);
t_stack_node *stack_new(int value);
void stack_add_back(t_stack_node **stack, t_stack_node *new);

/* Validation */
int ft_isdigit(int c);
long ft_atol(const char *str);
void exit_with_error(void);

/* Output */
int ft_printf(const char *format, ...);

/* ------------------- Algoritmos ------------------- */
void sort_two(t_stack_node **a);
void sort_three(t_stack_node **a);
void sort_four_five(t_stack_node **a, t_stack_node **b);
void radix_sort(t_stack_node **a, t_stack_node **b);

#endif
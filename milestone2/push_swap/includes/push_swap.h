/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:15:08 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/22 12:43:29 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Librerías estándar
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

// Estructura para los nodos de la pila
typedef struct s_stack_node
{
    int value;
    int index;
    struct s_stack_node *next;
    struct s_stack_node *prev;
} t_stack_node;

#endif
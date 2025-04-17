/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:15:08 by pafuente          #+#    #+#             */
/*   Updated: 2025/04/17 11:16:02 by pafuente         ###   ########.fr       */
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
typedef struct s_stack
{
    int             value;          // Valor del número
    int             index;          // Índice (para Radix Sort)
    struct s_stack  *next;          // Puntero al siguiente nodo
}                   t_stack;

#endif
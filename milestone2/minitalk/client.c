/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:26:14 by pafuente          #+#    #+#             */
/*   Updated: 2025/03/25 11:23:42 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


//send_char envía los bits en orden descendente (de 7 a 0).
//send_char usa un bucle while que decrementa bit desde 7 hasta 0.

void send_char(int pid, char c)
{

    int bit; 
    bit = 7;

    while(bit >= 0)
    {
        if(c & (1 << bit))
        {
            kill(pid, SIGUSR1);
        }
        else
        {
            kill(pid, SIGUSR2);

        }
        bit--;
        usleep(100);
    }
}
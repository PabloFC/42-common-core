/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:26:14 by pafuente          #+#    #+#             */
/*   Updated: 2025/03/18 11:18:43 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

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
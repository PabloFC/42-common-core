/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:37:00 by pafuente          #+#    #+#             */
/*   Updated: 2025/03/28 12:02:51 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

/*
The signal_handler function reconstructs characters from binary signals
SIGUSR1 and SIGUSR2). Each signal represents a bit (1 or 0).
When 8 bits have been received, they are interpreted as 
an ASCII character and printed.If the character is null 
('\0'), a line break is printed to indicate the end of the message.
*/

void	signal_handler(int sig)
{
	static unsigned char	character = 0;
	static int				bit_pos = 0;

	if (sig == SIGUSR1)
		character |= 1; // Añade un '1' al bit menos significativo de 'character'
	else
		character |= 0; // Añade un '0' al bit menos significativo de 'character'
	bit_pos++; // Asegura que el programa sepa cuántos bits se han acumulado en la variable character. Cuando bit_pos llega a 8, significa que se ha recibido un byte completo (8 bits), y ese byte se interpreta como un carácter ASCII.
	if (bit_pos == 8)
	{
		if (character == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", character);
		bit_pos = 0;
		character = 0;
	}
	else
		character <<= 1; // Esta operación se utiliza para preparar character para recibir el siguiente bit
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}

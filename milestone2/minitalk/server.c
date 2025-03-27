/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:37:00 by pafuente          #+#    #+#             */
/*   Updated: 2025/03/27 11:06:42 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "libft/libft.h"

#define END_TRANSMISSION '\0'


#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

// The signal_handler function reconstructs characters from binary signals
//  SIGUSR1 and SIGUSR2). Each signal represents a bit (1 or 0).
// When 8 bits have been received, they are interpreted as an ASCII character and printed.
// If the character is null ('\0'), a line break is printed to indicate the end of the message.

void	signal_handler(int sig)
{
    static unsigned char	character = 0;
    static int				bit_pos = 0;

    character |= (sig == SIGUSR1);
    bit_pos++;
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
        character <<= 1; 
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:45:35 by husarpka          #+#    #+#             */
/*   Updated: 2025/01/27 19:14:53 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

void ft_handler(int sig)
{
    static int bit = 128;
    static int c = 0;

    if (sig == SIGUSR1)
    {
        c |= bit;
    }
    bit >>= 1;
    if (bit == 0)
    {
        write(1, &c, 1);
        bit = 128;
        c = 0;
    }
}

int main(void)
{
    struct sigaction sa;

    sa.sa_handler = ft_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    ft_putnbr(getpid());
    write(1, "\n", 1);

    while (80)
    {
        pause();
    }
    
    return 0;
}

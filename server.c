/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:45:35 by husarpka          #+#    #+#             */
/*   Updated: 2025/01/29 16:56:22 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

static void	ft_handler(int sig, siginfo_t *info, void *value)
{
	static int	bit = 128;
	static int	c = 0;

	(void)value;
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
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "pid.. ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}

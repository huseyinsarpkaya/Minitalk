/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husarpka <husarpka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:27:56 by husarpka          #+#    #+#             */
/*   Updated: 2025/01/30 16:00:38 by husarpka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile int	g_ack = 0;

static void	ft_res(int sig)
{
	if (sig == SIGUSR1)
		write(1, "successful", 10);
	if (sig == SIGUSR2)
		g_ack = 1;
}

static void	send_bits(int pid, char a)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		g_ack = 0;
		if (a >> bit & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		while (!g_ack)
			pause();
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(1, "you entered an incorrect argument", 33);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		write(1, "pid error", 9);
		return (1);
	}
	signal(SIGUSR1, ft_res);
	signal(SIGUSR2, ft_res);
	while (argv[2][i])
		send_bits(pid, argv[2][i++]);
	send_bits(pid, '\0');
	return (0);
}
